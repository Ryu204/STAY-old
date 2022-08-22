#include "../../../header/Logic/System/collisionSystem.hpp"
#include "../../../header/Logic/Component/componentList.hpp"
#include "../../../header/Logic/Physics/collision.hpp"
#include "../../../header/Helper/utilise.hpp"

#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

namespace Collision
{
	CollisionSystem::CollisionSystem(ECS::Engine* engine)
		: ECS::System(engine)
	{
		m_random.seed(static_cast<unsigned int>(time(NULL)));
	}

	void CollisionSystem::update(sf::Time dt)
	{
		for (int i = 1; i <= 8; i++)
		{
			process(dt);
		}
	}

	void CollisionSystem::process(sf::Time dt)
	{
		std::vector<ECS::Entity> list;
		for (auto e : m_entities)
			list.push_back(e);
		std::shuffle(list.rbegin(), list.rend(), m_random);

		for (auto e : list)
		for (auto f : list)
		if (e < f)
		{
			float time = 0;
			sf::Vector2i normal;
			auto& rge = m_engine->get_component<Component::Rigidbody>(e);
			auto& rgf = m_engine->get_component<Component::Rigidbody>(f);
			auto& cole = m_engine->get_component<Component::Collider>(e);
			auto& colf = m_engine->get_component<Component::Collider>(f);
			if (Collision::entity_and_entity(cole.rect, rge.velocity * dt.asSeconds(), colf.rect, rgf.velocity * dt.asSeconds(), time, normal))
			{
				//std::cout << "1";
				resolve(rge, rgf, time, normal);
			}
		}
	}
}