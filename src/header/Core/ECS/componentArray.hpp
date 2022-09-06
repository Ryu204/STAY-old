#ifndef STAY_CORE_ECS_COMPONENTARRAY_HPP
#define STAY_CORE_ECS_COMPONENTARRAY_HPP

/*
	Part of ECS implementation
	This class contains component data of one type
	===============================================
	Since we need a ComponentManager class that 
	contains multiple types, we will make a common 
	interface and template derived classes
	===============================================
	The array uses 2 unordered_maps to keep Components 
	continued while maintaining indexing by Entity
*/

#include <array>
#include <unordered_map>
#include <cassert>

#include "value.hpp"
#include "entity.hpp"

namespace ECS
{
	class IComponentArray
	{
	public:
		IComponentArray();
		virtual ~IComponentArray() = default;
		virtual void entity_destroyed(Entity e) = 0;
	};

	template<typename T>
	class ComponentArray : public IComponentArray
	{
	public:
		ComponentArray();

		void add_data(Entity e, T component);
		void remove_data(Entity e);
		T& get_data(Entity e);
		bool has_data(Entity e) const;
		void entity_destroyed(Entity e) override;
	private:
		std::size_t m_real_size;
		std::unordered_map<Entity, std::size_t> m_EnToIn;
		std::unordered_map<std::size_t, Entity> m_InToE;
		std::array<T, MAX_ENTITY> m_array;
	};

	template<typename T>
	ComponentArray<T>::ComponentArray()
		: m_real_size(0)
	{ }

	template<typename T>
	void ComponentArray<T>::add_data(Entity e, T component)
	{
		assert(m_EnToIn.find(e) == m_EnToIn.end() && "Component added twice");
		m_EnToIn[e] = m_real_size;
		m_InToE[m_real_size] = e;
		m_array[m_real_size] = component;
		m_real_size++;
	}

	template<typename T>
	void ComponentArray<T>::remove_data(Entity e)
	{
		assert(has_data(e) && "Non-existed component");
		m_real_size--; // m_real_size is now last valid index
		auto hole_index = m_EnToIn[e], last_entity = m_InToE[m_real_size];
		m_array[hole_index] = m_array[m_real_size];
		m_EnToIn[last_entity] = hole_index;
		m_InToE[hole_index] = last_entity;
		m_EnToIn.erase(e);
		m_InToE.erase(m_real_size);
	}

	template<typename T>
	T& ComponentArray<T>::get_data(Entity e)
	{
		assert(has_data(e) && "Non-existed component");
		return m_array[m_EnToIn[e]];
	}

	template<typename T>
	bool ComponentArray<T>::has_data(Entity e) const
	{
		return m_EnToIn.find(e) != m_EnToIn.end();
	}

	template<typename T>
	void ComponentArray<T>::entity_destroyed(Entity e)
	{
		if (has_data(e))
			remove_data(e);
	}
}

#endif // !STAY_CORE_ECS_COMPONENTARRAY_HPP
