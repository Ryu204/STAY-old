#include "../header/world.hpp"
#include "../header/Logic/Component/componentList.hpp"

#include <vector>
#include <iostream>

World::World(RWindow* window)
	: m_window(window)
	, m_camera(sf::Vector2f(300, 300))
	, m_map_loader("resource/level/playground.ldtk")
{
	m_textures.load("test", "resource/texture/test.png");
	m_textures.load("Cat", "resource/texture/cat.png");
	m_textures.load("Mossy", "resource/texture/tileset.png");
	m_textures.load("Hook", "resource/texture/hook.png");

	ECS::ECS_init(&m_engine, m_window, &m_textures, m_renderer, m_rigid, m_collider, m_positioner, m_controller, m_hookgun);

	m_map_loader.load_to_engine(&m_engine, &m_textures, &m_camera, "Level_0");	
}

void World::process_input(const sf::Event& e)
{
	m_controller->handle_event(e);
}

void World::update(sf::Time dt)
{
	m_rigid->update(dt);
	m_hookgun->update(dt);
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
	m_hookgun->draw();
	m_window->setView(cur);
}