#ifndef STAY_LOGIC_COMPONENT_RIGIDBODY_HPP
#define STAY_LOGIC_COMPONRNT_RIGIDBODY_HPP

/*
	Rigidbody component
*/

#include <SFML/Graphics.hpp>

namespace Component
{
	struct Rigidbody
	{
		sf::Vector2f velocity = sf::Vector2f();
		sf::Vector2f acceleration = sf::Vector2f();
	};
}

#endif // !STAY_LOGIC_COMPONENT_RIGIDBODY_HPP
