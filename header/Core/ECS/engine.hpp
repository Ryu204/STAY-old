#ifndef STAY_HEADER_CORE_ECS_ENGINE_HPP
#define STAY_HEADER_CORE_ECS_ENGINE_HPP

/*
	Part of ECS implementation
	This is a wrapper around 3 elements:
	Entity - Component - System
	It provides fuctionalities that will be used by the
	game's classes such as Entity's creation, component 
	access, manages systems .etc
*/

#include "entityManager.hpp"
#include "componentManager.hpp"
#include "systemManager.hpp"

namespace ECS
{
	class Engine
	{
	public:
		Engine();

		// Entity
		Entity create_entity();
		void destroy_entity(Entity e);

		// Component
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

		// System
		template<typename T>
		void register_system();

		template<typename T>
		void set_system_Signature(Signature s);
	private:
		template<typename T>
		Signature generate_Signature();

		template<typename T, typename... Ts>
		Signature generate_Signature();
	private:
		UPtr<EntityManager> m_entities;
		UPtr<ComponentManager> m_components;
		UPtr<SystemManager> m_systems;
	};

	template<typename T>
	void Engine::register_component()
	{
		m_components->register_component<T>();
	}

	template<typename T>
	void Engine::add_component(Entity e, T component)
	{
		m_components->add_component<T>(e, component);
		
		Signature s = m_entities->get_Signature(e);
		s.set(m_components->get_component_type<T>());

		m_entities->set_Signature(e, s);
		m_systems->entity_Signature_changed(e, s);
	}

	template<typename T>
	T& Engine::get_component(Entity e)
	{
		return m_components->get_component<T>(e);

		Signature s = m_entities->get_Signature(e);
		s.set(m_components->get_component_type<T>(), false);

		m_entities->set_Signature(e, s);
		m_systems->entity_Signature_changed(e, s);
	}

	template<typename T>
	bool Engine::has_component(Entity e)
	{
		return m_components->has_component<T>(e);
	}

	template<typename T>
	void Engine::register_system()
	{
		m_systems->register_system<T>();
	}

	template<typename T>
	void Engine::set_system_Signature(Signature s)
	{
		m_systems->set_Signature<T>(s);
	}

	template<typename T>
	Signature Engine::generate_Signature()
	{
		Signature res;
		res.set(m_components->get_component_type<T>());
		return res;
	}

	template<typename T, typename... Ts>
	Signature Engine::generate_Signature()
	{
		Signature res = generate_Signature<Ts>();
		res.set(m_components->get_component_type<T>());
		return res;
	}
}

#endif // !STAY_HEADER_CORE_ECS_ENGINE_HPP
