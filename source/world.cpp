#include "../header/world.hpp"
#include "../header/Logic/Component/componentList.hpp"

#include <vector>

World::World(RWindow* window)
	: m_window(window)
{
	ECS::ECS_init(&m_engine, m_window, m_renderer, m_rigid);
	std::vector<sf::Color> cls{ sf::Color::Blue, sf::Color::Green, sf::Color::Red, sf::Color::Magenta, sf::Color::Cyan};
	for (int i = 1; i <= 1000; i++)
	{
		ECS::Entity e = m_engine.create_entity();
		m_engine.add_component(e, Component::Render{ nullptr, sf::IntRect(), cls[i % 5] });
		m_engine.add_component(e, Component::Transform{ sf::FloatRect{i / 2.f, 0, 5, 5} });
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