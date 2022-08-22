#include "../header/world.hpp"
#include "../header/Logic/Component/componentList.hpp"

#include <vector>
#include <iostream>

World::World(RWindow* window)
	: m_window(window)
{
	m_textures.load("test", "resource/texture/test.png");

	ECS::ECS_init(&m_engine, m_window, &m_textures, m_renderer, m_rigid, m_collider, m_positioner);
	std::vector<sf::Color> cls{ sf::Color::Blue, sf::Color::Green, sf::Color::Red, sf::Color::Magenta, sf::Color::Cyan};

	sf::Texture* txtr = &m_textures.get("test");

	for (int i = 1; i <= 10; i++)
	{
		ECS::Entity e = m_engine.create_entity();
		m_engine.add_component(e, Component::Render{ txtr, sf::IntRect(0, 0, 10, 10), cls[i % 5] });
		m_engine.add_component(e, Component::Transform{ sf::FloatRect{i * 50.f, 0, 25.f, 25.f} });
		m_engine.add_component(e, Component::Rigidbody{ sf::Vector2f(), sf::Vector2f{i*0.5f * ( rand() % 3 - 1), i * 100.f}, 10.f, false});
		m_engine.add_component(e, Component::Collider{ sf::FloatRect{i * 50.f, 0.f, 25.f, 25.f} });
	}

	ECS::Entity e = m_engine.create_entity();
	m_engine.add_component(e, Component::Render{ txtr, sf::IntRect(0, 0, 10, 10), sf::Color::Yellow});
	m_engine.add_component(e, Component::Transform{ sf::FloatRect{0, 400, 600, 5} });
	m_engine.add_component(e, Component::Rigidbody{ sf::Vector2f(), sf::Vector2f(), 50000.f, false});
	m_engine.add_component(e, Component::Collider{ sf::FloatRect{0, 400, 600, 5} });

	ECS::Entity e1 = m_engine.create_entity();
	m_engine.add_component(e1, Component::Render{ txtr, sf::IntRect(0, 0, 10, 10), sf::Color::Yellow });
	m_engine.add_component(e1, Component::Transform{ sf::FloatRect{0, -300, 600, 200} });
	m_engine.add_component(e1, Component::Rigidbody{ sf::Vector2f(), sf::Vector2f(0, 15), 600.f, false });
	m_engine.add_component(e1, Component::Collider{ sf::FloatRect{0, -300, 600, 200} });
}

void World::process_input(const sf::Event& e)
{

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