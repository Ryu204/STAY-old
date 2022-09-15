#include "../../../header/Logic/System/hookSystem.hpp"
#include "../../../header/Logic/Component/componentList.hpp"
#include "../../../header/Helper/utilise.hpp"

#include<iostream>

namespace Logic
{
	HookSystem::HookSystem(ECS::Engine* engine)
		: System(engine)
		, m_hook_texture(nullptr)
		, m_render_target(nullptr)
	{ }

	void HookSystem::init(sf::RenderTarget* target, TextureHolder* textures)
	{
		m_render_target = target;
		m_hook_texture = &textures->get("Hook");
	}

	void HookSystem::draw()
	{
		sf::VertexArray line(sf::Lines);

		for (auto e : m_entities)
		{
			// auto& tf = m_engine->get_component<Component::Transform>(e);
			// auto& rg = m_engine->get_component<Component::Rigidbody>(e);
			auto& hk = m_engine->get_component<Component::Hook>(e);
			auto& col = m_engine->get_component<Component::Collider>(e);

			if (hk.state == Component::Hook::Idle)
				continue;

			line.append(sf::Vertex(Utilise::get_center(col.rect)));

			assert(m_engine->has_component<Component::Collider>(hk.head) && "No hook head found");
			line.append(Utilise::get_center(m_engine->get_component<Component::Collider>(hk.head).rect));
		}

		m_render_target->draw(line);
	}

	void HookSystem::update(sf::Time dt)
	{
		for (auto e : m_entities)
		{
			// auto& tf = m_engine->get_component<Component::Transform>(e);
			// auto& rg = m_engine->get_component<Component::Rigidbody>(e);
			auto& hk = m_engine->get_component<Component::Hook>(e);
			auto& col = m_engine->get_component<Component::Collider>(e);

			bool press_L = sf::Keyboard::isKeyPressed(sf::Keyboard::L);

			switch (hk.state)
			{
			case Component::Hook::Idle:
			{
				sf::Vector2f dir;
				if (press_L)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						dir.x += 1.f;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
						dir.x -= 1.f;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
						dir.y -= 1.f;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
						dir.y += 1.f;
					if (dir != sf::Vector2f())
					{
						hk.head = m_engine->create_entity();
						//create head
						sf::FloatRect head_col{ 0, 0, 32, 32 };
						Utilise::align(head_col, col.rect);
						m_engine->add_component(hk.head, Component::Transform{ head_col });
						head_col.width /= 2.f;  head_col.height /= 2.f;
						Utilise::align(head_col, col.rect);
						m_engine->add_component(hk.head, Component::Collider{ head_col, Component::Collider::HookHead });
						m_engine->add_component(hk.head, Component::Rigidbody{ Utilise::normalise(dir) * hk.initial_speed, sf::Vector2f(0, 100)});
						m_engine->add_component(hk.head, Component::Render{ m_hook_texture, sf::IntRect(0, 0, 32, 32) });
						//=======
						hk.state = Component::Hook::Shot;
					}
				}
				break;
			}
			case Component::Hook::Pull:
			{
				assert(m_engine->has_component<Component::Collider>(hk.head) && "No hook head found");
				auto& col_head = m_engine->get_component<Component::Collider>(hk.head);

				if (Utilise::length(Utilise::get_center(col.rect) - Utilise::get_center(col_head.rect)) <= 100) //some const_value
				{
					m_engine->destroy_entity(hk.head);
					hk.state = Component::Hook::Idle;
				}
				else
				{
					if (press_L)
						hk.state = Component::Hook::Retrieve;
					else
					{
					} // keep pulling}
				}
				break;
			}
			case Component::Hook::Retrieve:
			{
				assert(m_engine->has_component<Component::Collider>(hk.head) && "No hook head found");
				auto& col_head = m_engine->get_component<Component::Collider>(hk.head);

				if (Utilise::length(Utilise::get_center(col.rect) - Utilise::get_center(col_head.rect)) <= 100) //some const_value
				{
					m_engine->destroy_entity(hk.head);
					hk.state = Component::Hook::Idle;
				}
				else
				{
					// keep pulling the string
				}
				break;
			}
			case Component::Hook::Shot:
			{
				assert(m_engine->has_component<Component::Rigidbody>(hk.head) && "No hook head found");
				auto& rg = m_engine->get_component<Component::Rigidbody>(hk.head);

				if (rg.velocity == sf::Vector2f())
					hk.state = Component::Hook::Pull;

				break;
			}
			default:
				break;
			}
		}
	}
}