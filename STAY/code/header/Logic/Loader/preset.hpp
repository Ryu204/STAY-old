#ifndef STAY_LOGIC_LOADER_PRESET_HPP
#define STAY_LOGIC_LOADER_PRESET_HPP

/*
	Loads presets entities
*/

#include "../System/ecsInit.hpp"

namespace Preset
{
	// Creates an invinsible static collider
	void create_collider(ECS::Engine* engine, sf::FloatRect rect = sf::FloatRect());

	// Create an entity with transform and render component
	void create_tile(ECS::Engine* engine, sf::FloatRect rect = sf::FloatRect(),
		sf::Texture* texture = nullptr, sf::IntRect texture_rect = sf::IntRect(0, 0, 1, 1));

	// Create a player
	void create_player(ECS::Engine* engine, sf::FloatRect transform_rect, sf::FloatRect collider_rect, sf::Texture* texture, sf::IntRect texture_rect, float speed, float gravity, float jump_height);
}

#endif // !STAY_LOGIC_LOADER_PRESET_HPP
