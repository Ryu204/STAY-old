#ifndef STAY_HEADER_CORE_WORLD_HPP
#define STAY_HEADER_CORE_WORLD_HPP

/*
	This class handles everything inside GameState
*/

#include "Core/coreAlias.hpp"
#include "Core/ECS/engine.hpp"
#include "Logic/System/ecsInit.hpp"

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

	SPtr<Logic::RenderSystem> m_renderer;
	SPtr<Logic::RigidSystem> m_rigid;
};

#endif // !STAY_HEADER_CORE_WORLD_HPP
