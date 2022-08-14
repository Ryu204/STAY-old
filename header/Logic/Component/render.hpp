#ifndef STAY_HEADER_LOGIC_COMPONENT_RENDER_HPP
#define STAY_HEADER_LOGIC_COMPONENT_RENDER_HPP

/*
	Render component
*/

#include <SFML/Graphics.hpp>

namespace Component
{
	struct Render
	{
		const sf::Texture* texture;
		sf::IntRect texture_rect = sf::IntRect(0, 0, 10, 10);
		sf::Color color = sf::Color::White;
	};
}

#endif // !STAY_HEADER_LOGIC_COMPONENT_TRANSFORM_HPP
