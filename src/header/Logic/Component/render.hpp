#ifndef STAY_LOGIC_COMPONENT_RENDER_HPP
#define STAY_LOGIC_COMPONENT_RENDER_HPP

/*
	Render component
*/

#include <SFML/Graphics.hpp>

namespace Component
{
	struct Render
	{
		sf::Texture* texture = nullptr;
		sf::IntRect texture_rect = sf::IntRect(0, 0, 1, 1);
		sf::Color color = sf::Color::White;
	};
}

#endif // !STAY_LOGIC_COMPONENT_TRANSFORM_HPP
