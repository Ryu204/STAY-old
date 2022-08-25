#include "../../../header/Logic/System/rigidSystem.hpp"
#include "../../../header/Logic/Component/componentList.hpp"
#include "../../../header/Helper/utilise.hpp"

namespace Logic
{
	RigidSystem::RigidSystem(ECS::Engine* engine)
		: System(engine)
	{ }

	void RigidSystem::update(sf::Time dt)
	{
		for (auto e : m_entities)
		{
			auto& rg = m_engine->get_component<Component::Rigidbody>(e);

			if (!rg.fixed)
				rg.velocity += rg.acceleration * dt.asSeconds();
			rg.velocity *= std::pow(rg.friction, dt.asSeconds());
		}
	}
}