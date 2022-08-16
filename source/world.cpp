#include "../header/world.hpp"
#include "../header/Logic/Component/componentList.hpp"

#include <vector>

World::World(RWindow* window)
	: m_window(window)
{
	m_textures.load("test", "resource/texture/test.png");

	ECS::ECS_init(&m_engine, m_window, &m_textures, m_renderer, m_rigid);
	std::vector<sf::Color> cls{ sf::Color::Blue, sf::Color::Green, sf::Color::Red, sf::Color::Magenta, sf::Color::Cyan};

	sf::Texture* txtr = &m_textures.get("test");

	for (int i = 1; i <= 100; i++)
	{
		ECS::Entity e = m_engine.create_entity();
		m_engine.add_component(e, Component::Render{ txtr, sf::IntRect(0, 0, 10, 10), cls[i % 5] });
		m_engine.add_component(e, Component::Transform{ sf::FloatRect{i * 5.f, 0, 25.f, 25.f} });
		m_engine.add_component(e, Component::Rigidbody(sf::Vector2f(), sf::Vector2f{0, i*0.05f}));
	}
}

void World::process_input(const sf::Event& e)
{

}

void World::update(sf::Time dt)
{
	m_rigid->update(dt);
}

void World::render()
{
	m_renderer->render();
}