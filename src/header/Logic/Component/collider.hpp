#ifndef STAY_LOGIC_COMPONENT_COLLIDER_HPP
#define STAY_LOGIC_COMPONRNT_COLLIDER_HPP

/*
	Collider component

*/

#include <SFML/Graphics.hpp>

namespace Component
{
	struct Collider
	{
		sf::FloatRect rect = sf::FloatRect();
	};
}

#endif // !STAY_LOGIC_COMPONENT_COLLIDER_HPP
