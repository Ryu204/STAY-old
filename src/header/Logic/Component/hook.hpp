#ifndef STAY_LOGIC_COMPONENT_HOOK_HPP
#define STAY_LOGIC_COMPONRNT_HOOK_HPP

/*
	Hook gun component
	Emit hook head
*/

#include <SFML/Graphics.hpp>

#include "../../Core/ECS/entity.hpp"

namespace Component
{
	struct Hook
	{
		enum State
		{
			IDLE,
			SHOT,
			PULL,
			RETRIEVE
		};

		// Information
		State state = State::IDLE;
		ECS::Entity head = 0;
		float max_distance = 200;
		float initial_speed = 1000;
		float pull_speed = 300;

		// Calculation
		sf::Vector2f acceleration = sf::Vector2f();
	};
}

#endif // !STAY_LOGIC_COMPONENT_HOOK_HPP
