#ifndef STAY_HEADER_CORE_ECS_COMPONENTARRAY_HPP
#define STAY_HEADER_CORE_ECS_COMPONENTARRAY_HPP

/*
	Part of ECS implementation
	This class is what actually contains Component
	==============================================================
	Since we need a ComponentManager class that contains multiple type of Components, we will make a common interface and then derive from it with template classes
	==============================================================
	The array uses 2 map to keep Components continued while maintaining indexiong by Entity
*/

#include <array>
#include <unordered_map>

#include "value.hpp"
#include "entity.hpp"

namespace ECS
{
	class IComponentArray
	{
	public:
		IComponentArray();
		virtual ~IComponentArray();
	};

	template<typename T>
	class ComponentArray : public IComponentArray
	{
	public:
		ComponentArray();

		void add_component(Entity e, T component);
	private:
		std::size_t m_real_size;
		std::unordered_map<Entity, std::size_t> m_EnToIn;
		std::unordered_map<std::size_t, Entity> m_InToE;
		std::array<T, MAX_COMPONENT> m_array;
	};
}

#endif // !STAY_HEADER_CORE_ECS_COMPONENTARRAY_HPP
