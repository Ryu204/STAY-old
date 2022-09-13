#include "../header/world.hpp"
#include "../header/Logic/Component/componentList.hpp"

#include <vector>
#include <iostream>

World::World(RWindow* window)
	: m_window(window)
	, m_camera(sf::Vector2f(300, 300))
	, m_map_loader("resource/level/movement.ldtk")
{
	m_textures.load("test", "resource/texture/test.png");
	m_textures.load("Cat", "resource/texture/cat.png");
	m_textures.load("Mossy", "resource/texture/tileset.png");

	ECS::ECS_init(&m_engine, m_window, &m_textures, m_renderer, m_rigid, m_collider, m_positioner, m_controller);

	m_map_loader.load_to_engine(&m_engine, &m_textures, &m_camera, "Level_0");
	/*ECS::Entity e = m_engine.create_entity();
	m_engine.add_component(e, Component::Render{ txtr, sf::IntRect(0, 0, 10, 10), sf::Color::Yellow});
	m_engine.add_component(e, Component::Transform{ sf::FloatRect{0, 400, 600, 5} });
	m_engine.add_component(e, Component::Collider{ sf::FloatRect{0, 400, 600, 5} });

	ECS::Entity e1 = m_engine.create_entity();
	m_engine.add_component(e1, Component::Render{ txtr, sf::IntRect(0, 0, 10, 10), sf::Color::Yellow });
	m_engine.add_component(e1, Component::Transform{ sf::FloatRect{0, 100, 600, 10} });
	m_engine.add_component(e1, Component::Collider{ sf::FloatRect{0, 100, 600, 10} });

	e = m_engine.create_entity();
	m_engine.add_component(e, Component::Render{ txtr, sf::IntRect(0, 0, 10, 10), sf::Color::White });
	m_engine.add_component(e, Component::Transform{ sf::FloatRect{ 0.f, 350.f, 50.f, 50.f } });
	m_engine.add_component(e, Component::Rigidbody{ sf::Vector2f(), sf::Vector2f() });
	m_engine.add_component(e, Component::Collider{ sf::FloatRect{ 0.f, 350.f, 50.f, 50.f }, Component::Collider::Player });
	m_engine.add_component(e, Component::Control{ });*/
	
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

	m_camera.update(m_controller->get_player_center(), dt);
}

void World::render()
{
	sf::View cur = m_window->getView();
	m_window->setView(m_camera.get_view());
	m_renderer->render(m_camera.get_view());
	m_window->setView(cur);
}