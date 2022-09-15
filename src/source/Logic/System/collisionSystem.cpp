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
		ECS::Entity player = -1, hook_head = -1;
		m_colliders.clear();
		for (auto e : m_entities)
		{
			auto& col = m_engine->get_component<Component::Collider>(e);
			if (col.tag == Component::Collider::Player)
				player = e;
			else if (col.tag == Component::Collider::HookHead)
				hook_head = e;

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
				if (m_colliders[e]->tag == Component::Collider::Platform)
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
		// If there is a hook
		if (hook_head != -1)
		{
			for (auto e : m_entities)
			{
				assert(m_engine->has_component<Component::Rigidbody>(hook_head) && "Hook doesn't have Rigidbody");
				auto& rg = m_engine->get_component<Component::Rigidbody>(hook_head);

				if (m_colliders[e]->tag == Component::Collider::Platform)
				{
					sf::Vector2f normal;
					float time = 0.f;
					if (Collision::entity_and_entity(m_colliders[hook_head]->rect, rg.velocity * dt.asSeconds(), m_colliders[e]->rect, time, normal))
					{
						rg.acceleration = sf::Vector2f();
						rg.velocity = sf::Vector2f();
						m_colliders[hook_head]->tag = Component::Collider::None;
					}
				}
			}
		}
	}
}