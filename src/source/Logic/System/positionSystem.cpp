#include "../../../header/Logic/System/positionSystem.hpp"
#include "../../../header/Logic/Component/componentList.hpp"
#include "../../../header/Helper/utilise.hpp"

namespace Logic
{
	PositionSystem::PositionSystem(ECS::Engine* engine)
		: System(engine)
	{ }

	void PositionSystem::update(sf::Time dt)
	{
		for (auto e : m_entities)
		{
			auto& tf = m_engine->get_component<Component::Transform>(e);
			auto& rg = m_engine->get_component<Component::Rigidbody>(e);

			if (!rg.fixed)
			{
				tf.rect.left += rg.velocity.x * dt.asSeconds();
				tf.rect.top += rg.velocity.y * dt.asSeconds();
			}

			if (m_engine->has_component<Component::Collider>(e))
				Utilise::align(m_engine->get_component<Component::Collider>(e).rect, tf.rect);
		}
	}
}