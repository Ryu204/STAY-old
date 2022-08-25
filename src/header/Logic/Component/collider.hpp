#ifndef STAY_LOGIC_COMPONENT_COLLIDER_HPP
#define STAY_LOGIC_COMPONRNT_COLLIDER_HPP

/*
	Collider component
	rect: The real collider
	vrect: The rect achieved by truncate rect to
	avoid floating point imprecission
*/

#include <SFML/Graphics.hpp>

namespace Component
{
	struct Collider
	{
		float cor = 0.f; // coefficient of resitution
		sf::FloatRect rect = sf::FloatRect();
		sf::FloatRect vrect = rect;
	};
}

#endif // !STAY_LOGIC_COMPONENT_COLLIDER_HPP
