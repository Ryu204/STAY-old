#include "../../../header/Logic/System/rigidSystem.hpp"
#include "../../../header/Logic/Component/componentList.hpp"

namespace Logic
{
	RigidSystem::RigidSystem(ECS::Engine* engine)
		: System(engine)
	{ }

	void RigidSystem::update(sf::Time dt)
	{
		for (auto e : m_entities)
		{
			auto& tf = m_engine->get_component<Component::Transform>(e);
			auto& rg = m_engine->get_component<Component::Rigidbody>(e);

			rg.velocity += rg.acceleration * dt.asSeconds();
			tf.rect.left += rg.velocity.x * dt.asSeconds();
			tf.rect.top += rg.velocity.y * dt.asSeconds();
		}
	}
}