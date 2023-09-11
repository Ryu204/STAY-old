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
	{ }

	void CollisionSystem::update(sf::Time dt)
	{
		ECS::Entity player = -1;
		m_colliders.clear();
		for (auto e : m_entities)
		{
			auto& col = m_engine->get_component<Component::Collider>(e);
			if (col.tag == Component::Collider::Player)
				player = e;
			m_colliders.emplace(e, &col);
		}

		// If player is alive
		if (player != -1)
		{
			// Check for rigidbody 
			assert(m_engine->has_component<Component::Rigidbody>(player) && "Player doesn't have Rigidbody");

			auto& rg = m_engine->get_component<Component::Rigidbody>(player);
			for (auto e : m_entities)
			{
				if (e != player)
				{
					sf::Vector2f normal;
					float time = 0.f;
					if (Collision::entity_and_entity(m_colliders[player]->rect, rg.velocity * dt.asSeconds(), m_colliders[e]->rect, time, normal))
					{
						// std::cout << time << '\n';
						Collision::resolve(rg, time, normal);
						// check if collide with platform underneath
						if (normal.y == -1)
							m_engine->get_component<Component::Control>(player).jumped = false;
					}
				}
			}
		}
	}
}