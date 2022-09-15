#ifndef STAY_WORLD_HPP
#define STAY_WORLD_HPP

/*
	This class handles everything inside GameState
	and has control over every system
*/

#include "Logic/System/ecsInit.hpp"
#include "Logic/Loader/mapLoader.hpp"
#include "Logic/System/cameraController.hpp"

class World
{
public:
	World(RWindow* window);
	void process_input(const sf::Event& e);
	void update(sf::Time dt);
	void render();
private:
	RWindow* m_window;
	Logic::CameraController m_camera;
	ECS::Engine m_engine;

	SPtr<Logic::RenderSystem> m_renderer;
	SPtr<Logic::RigidSystem> m_rigid;
	SPtr<Collision::CollisionSystem> m_collider;
	SPtr<Logic::PositionSystem> m_positioner;
	SPtr<Logic::ControlSystem> m_controller;
	SPtr<Logic::HookSystem> m_hookgun;

	TextureHolder m_textures;
	Game::MapLoader m_map_loader;
};

#endif // !STAY_WORLD_HPP
