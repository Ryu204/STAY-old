#ifndef STAY_CORE_ECS_COMPONENTMANAGER_HPP
#define STAY_CORE_ECS_COMPONENTMANAGER_HPP

/*
	Part of ECS implementation
	This class manages different types of ComponentArray 
	and provides methods to access data of each type
	===============================================
	Before using any type of component, the client must
	first register the template type to the manager

	I.e ComponentManager::register_component<T>();
	===============================================
	Each array is identified by their template type
	via the keyword typeid(template_name).name()
	Internally, the type is an interger in m_type_list
*/

#include <typeinfo>
#include<cassert>

#include "componentArray.hpp"
#include "componentType.hpp"
#include "../coreAlias.hpp"

namespace ECS
{
	class ComponentManager
	{
	public:
		ComponentManager();

		template<typename T>
		void register_component();

		template<typename T> 
		void add_component(Entity e, T component);

		template<typename T>
		void remove_component(Entity e);

		template<typename T>
		T& get_component(Entity e);

		template<typename T>
		bool has_component(Entity e);

		template<typename T>
		ComponentType get_component_type();

		void entity_destroyed(Entity e);
	private:
		template<typename T>
		ComponentArray<T>& get_array();
	private:
		std::unordered_map<const char*, SPtr<IComponentArray>> m_arrays;
		std::unordered_map<const char*, ComponentType> m_type_list;
		ComponentType m_available_type;
	};

	template<typename T>
	void ComponentManager::register_component()
	{
		auto name = typeid(T).name();
		assert(m_type_list.find(name) == m_type_list.end() && "Registered component type");
		assert(m_available_type < MAX_COMPONENT && "Too much component types");
		m_type_list.emplace(name, m_available_type);
		m_arrays.emplace(name, std::make_shared<ComponentArray<T>>());
		m_available_type++;
	}

	template<typename T>
	void ComponentManager::add_component(Entity e, T component)
	{
		auto name = typeid(T).name();
		assert(m_type_list.find(name) != m_type_list.end() && "Non-existed component type");
		get_array<T>().add_data(e, component);
	}

	template<typename T>
	void ComponentManager::remove_component(Entity e)
	{
		auto name = typeid(T).name();
		assert(m_type_list.find(name) != m_type_list.end() && "Non-existed component type");
		get_array<T>().remove_data(e);
	}

	template<typename T>
	T& ComponentManager::get_component(Entity e)
	{
		auto name = typeid(T).name();
		assert(m_type_list.find(name) != m_type_list.end() && "Non-existed component type");
		return get_array<T>().get_data(e);
	}

	template<typename T>
	bool ComponentManager::has_component(Entity e)
	{
		auto name = typeid(T).name();
		assert(m_type_list.find(name) != m_type_list.end() && "Non-existed component type");
		return get_array<T>().has_data(e);
	}

	template<typename T>
	ComponentType ComponentManager::get_component_type()
	{
		auto name = typeid(T).name();
		assert(m_type_list.find(name) != m_type_list.end() && "Non-existed component type");
		return m_type_list[name];
	}

	template<typename T>
	ComponentArray<T>& ComponentManager::get_array()
	{
		auto name = typeid(T).name();
		assert(m_type_list.find(name) != m_type_list.end() && "Non-existed component type");
		return *dynamic_pointer_cast<ComponentArray<T>>(m_arrays[name]);
	}
}

#endif // !STAY_CORE_ECS_COMPONENTMANAGER_HPP
