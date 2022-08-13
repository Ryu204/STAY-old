#ifndef STAY_HEADER_CORE_APPLICATION_HPP
#define STAY_HEADER_CORE_APPLICATION_HPP

/*
	This class contains the game loops
*/

#include <SFML/Graphics.hpp>

#include "coreAlias.hpp"
#include "world.hpp"

class Application
{
public:
	Application();
	void run();
	void process_input();
	void update(sf::Time dt);
	void render();
private:
	RWindow m_window;
	const sf::Time m_update_interval;

	World m_world;
};

#endif // !STAY_HEADER_CORE_APPLICATION_HPP
