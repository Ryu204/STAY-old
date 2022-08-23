#include "../../../header/Logic/System/collisionSystem.hpp"
#include "../../../header/Logic/Physics/collision.hpp"
#include "../../../header/Helper/utilise.hpp"

#include <unordered_map>
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
		m_list.clear(); m_colliders.clear(); m_rigids.clear();
		for (auto e : m_entities)
		{
			m_list.push_back(e);
			m_colliders.emplace(e, &m_engine->get_component<Component::Collider>(e));
			m_rigids.emplace(e, &m_engine->get_component<Component::Rigidbody>(e));
		}

		std::shuffle(m_list.rbegin(), m_list.rend(), m_random);
		for (int t = 1; t <= 10; t++)
		{
			std::reverse(m_list.begin(), m_list.end());
			for (int i = 1; i <= 5; i++)
			{
				process(dt, m_list);
			}
		}
	}

	void CollisionSystem::process(sf::Time dt, const std::vector<ECS::Entity>& list)
	{
		float time = 0;
		sf::Vector2i normal;
		for (auto e : list)
		{
			auto& cole = *m_colliders[e];
			auto& rge = *m_rigids[e];
			for (auto f : list)
			if (e < f)
			{
				auto& rgf = *m_rigids[f];
				auto& colf = *m_colliders[f];
				if (Collision::entity_and_entity(cole.rect, rge.velocity * dt.asSeconds(), colf.rect, rgf.velocity * dt.asSeconds(), time, normal))
				{
					//std::cout << "1";
					resolve(rge, rgf, time, normal);
				}
			}
		}
	}
}