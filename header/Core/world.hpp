#ifndef STAY_HEADER_CORE_WORLD_HPP
#define STAY_HEADER_CORE_WORLD_HPP

/*
	This class handles everything inside GameState
*/

#include "coreAlias.hpp"
#include "ECS/engine.hpp"

class World
{
public:
	World(RWindow* window);
	void process_input(const sf::Event& e);
	void update(sf::Time dt);
	void render();
private:
	RWindow* m_window;
	ECS::Engine m_engine;
};

#endif // !STAY_HEADER_CORE_WORLD_HPP
