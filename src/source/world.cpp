#include "../header/world.hpp"
#include "../header/Logic/Component/componentList.hpp"

#include <vector>
#include <iostream>

World::World(RWindow* window)
	: m_window(window)
{
	m_textures.load("test", "resource/texture/test.png");

	ECS::ECS_init(&m_engine, m_window, &m_textures, m_renderer, m_rigid, m_collider, m_positioner, m_controller);

	sf::Texture* txtr = &m_textures.get("test");

	ECS::Entity e = m_engine.create_entity();
	m_engine.add_component(e, Component::Render{ txtr, sf::IntRect(0, 0, 10, 10), sf::Color::Yellow});
	m_engine.add_component(e, Component::Transform{ sf::FloatRect{0, 400, 600, 5} });
	m_engine.add_component(e, Component::Rigidbody{ sf::Vector2f(), sf::Vector2f(), 99000.f, 1.f, true});
	m_engine.add_component(e, Component::Collider{ 0.f, sf::FloatRect{0, 400, 600, 5} });

	ECS::Entity e1 = m_engine.create_entity();
	m_engine.add_component(e1, Component::Render{ txtr, sf::IntRect(0, 0, 10, 10), sf::Color::Yellow });
	m_engine.add_component(e1, Component::Transform{ sf::FloatRect{0, -300, 600, 200} });
	m_engine.add_component(e1, Component::Rigidbody{ sf::Vector2f(), sf::Vector2f(0, 15), 600.f, 1.f, true });
	m_engine.add_component(e1, Component::Collider{ 0.f, sf::FloatRect{0, -300, 600, 200} });

	e = m_engine.create_entity();
	m_engine.add_component(e, Component::Render{ txtr, sf::IntRect(0, 0, 10, 10), sf::Color::White });
	m_engine.add_component(e, Component::Transform{ sf::FloatRect{ 300.f, 0.f, 50.f, 50.f } });
	m_engine.add_component(e, Component::Rigidbody{ sf::Vector2f(), sf::Vector2f(0, 1000), 10.f, 0.1f, false });
	m_engine.add_component(e, Component::Collider{ 0.0f, sf::FloatRect{ 300.f, 0.f, 50.f, 50.f },});

	e = m_engine.create_entity();
	m_engine.add_component(e, Component::Render{ txtr, sf::IntRect(0, 0, 10, 10), sf::Color::White });
	m_engine.add_component(e, Component::Transform{ sf::FloatRect{ 0.f, 0.f, 50.f, 50.f } });
	m_engine.add_component(e, Component::Rigidbody{ sf::Vector2f(), sf::Vector2f(), 10.f, 1.f, false });
	m_engine.add_component(e, Component::Collider{ 0.f, sf::FloatRect{ 0.f, 0.f, 50.f, 50.f },});
	m_engine.add_component(e, Component::Control{ });
}

void World::process_input(const sf::Event& e)
{
	
}

void World::update(sf::Time dt)
{
	m_rigid->update(dt);
	m_controller->update(dt);
	m_collider->update(dt);
	m_positioner->update(dt);
}

void World::render()
{
	m_renderer->render();
}