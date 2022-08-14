#ifndef STAY_HEADER_LOGIC_COMPONENT_TRANSFORM_HPP
#define STAY_HEADER_LOGIC_COMPONENT_TRANSFORM_HPP

/*
	Transform component
	Make use of sf::Transform
*/

#include <SFML/Graphics.hpp>

namespace Component
{
	struct Transform
	{
		sf::FloatRect rect = sf::FloatRect(0, 0, 10, 10);
		float rotation = 0.f; // Unit: degree
		sf::Vector2f scale = sf::Vector2f(1.f, 1.f);
	};
}

#endif // STAY_HEADER_LOGIC_COMPONENT_TRANSFORM_HPP
