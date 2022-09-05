#include "../header/application.hpp"

Application::Application()
	: m_window(sf::VideoMode(600, 600), "STAY")
	, m_update_interval(sf::seconds(1.f/120))
	, m_world(&m_window)
{ 
	m_window.setKeyRepeatEnabled(false);
}

void Application::run()
{
	sf::Clock clock;
	sf::Time elapsed_time = clock.restart();

	while (m_window.isOpen())
	{
		elapsed_time += clock.restart();
		while (elapsed_time >= m_update_interval)
		{
			elapsed_time -= m_update_interval;
			process_input();
			update(m_update_interval);
		}
		render();
	}
}

void Application::process_input()
{
	sf::Event e;
	while (m_window.pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		default:
			break;
		}

		m_world.process_input(e);
	}
}

void Application::update(sf::Time dt)
{
	m_world.update(dt);
}

void Application::render()
{
	m_window.clear();
	m_world.render();
	m_window.display();
}