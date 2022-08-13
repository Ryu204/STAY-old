#include "../../header/Core/ECS/engine.hpp"

namespace ECS
{
	Engine::Engine()
		: m_entities(std::make_unique<EntityManager>())
		, m_components(std::make_unique<ComponentManager>())
		, m_systems(std::make_unique<SystemManager>())
	{ }

	Entity Engine::create_entity()
	{
		auto res = m_entities->create();
		m_systems->entity_Signature_changed(res, Signature());
		return res;
	}

	void Engine::destroy_entity(Entity e)
	{
		m_entities->retrieve(e);
		m_components->entity_destroyed(e);
		m_systems->entity_destroyed(e);
	}
}