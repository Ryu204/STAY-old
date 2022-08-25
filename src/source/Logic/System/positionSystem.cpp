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
			{
				auto& col = m_engine->get_component<Component::Collider>(e);
				Utilise::align(col.rect, tf.rect);
				col.vrect.left = std::floor(col.rect.left);
				col.vrect.top = std::floor(col.rect.top);
				col.vrect.width = std::ceil(col.rect.left + col.rect.width - col.vrect.left);
				col.vrect.height = std::ceil(col.rect.top + col.rect.height - col.vrect.top);
			}
		}
	}
}