#include "../header/world.hpp"
#include "../header/Logic/Component/componentList.hpp"

#include <vector>
#include <iostream>

World::World(RWindow* window)
	: m_window(window)
{
	m_textures.load("test", "resource/texture/test.png");

	ECS::ECS_init(&m_engine, m_window, &m_textures, m_renderer, m_rigid, m_collider, m_positioner);

	sf::Texture* txtr = &m_textures.get("test");

	ECS::Entity e = m_engine.create_entity();
	m_engine.add_component(e, Component::Render{ txtr, sf::IntRect(0, 0, 10, 10), sf::Color::Yellow});
	m_engine.add_component(e, Component::Transform{ sf::FloatRect{0, 400, 600, 5} });
	m_engine.add_component(e, Component::Rigidbody{ sf::Vector2f(), sf::Vector2f(), 99000.f, true});
	m_engine.add_component(e, Component::Collider{ sf::FloatRect{0, 400, 600, 5} });

	/*ECS::Entity e1 = m_engine.create_entity();
	m_engine.add_component(e1, Component::Render{ txtr, sf::IntRect(0, 0, 10, 10), sf::Color::Yellow });
	m_engine.add_component(e1, Component::Transform{ sf::FloatRect{0, -300, 600, 200} });
	m_engine.add_component(e1, Component::Rigidbody{ sf::Vector2f(), sf::Vector2f(0, 15), 600.f, false });
	m_engine.add_component(e1, Component::Collider{ sf::FloatRect{0, -300, 600, 200} });*/
}

void World::process_input(const sf::Event& e)
{
	if (e.type == sf::Event::MouseButtonPressed)
	{
		std::vector<sf::Color> cls{ sf::Color::Blue, sf::Color::Green, sf::Color::Red, sf::Color::Magenta, sf::Color::Cyan };

		sf::Texture* txtr = &m_textures.get("test");
		ECS::Entity e = m_engine.create_entity();
		m_engine.add_component(e, Component::Render{ txtr, sf::IntRect(0, 0, 10, 10), cls[rand() % 5]});
		m_engine.add_component(e, Component::Transform{ sf::FloatRect{250.f, 0, 25.f, 25.f} });
		m_engine.add_component(e, Component::Rigidbody{ sf::Vector2f(), sf::Vector2f{rand() % 10 * 0.5f * (rand() % 3 - 1), 100.f}, 10.f, false});
		m_engine.add_component(e, Component::Collider{ sf::FloatRect{250.f, 0.f, 25.f, 25.f} });
	}
}

void World::update(sf::Time dt)
{
	m_rigid->update(dt);
	m_collider->update(dt);
	m_positioner->update(dt);
}

void World::render()
{
	m_renderer->render();
}