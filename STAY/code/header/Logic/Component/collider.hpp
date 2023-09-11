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
		enum Tag
		{
			Platform,
			Player,
			None
		};

		sf::FloatRect rect = sf::FloatRect();
		Tag tag = None;
	};
}

#endif // !STAY_LOGIC_COMPONENT_COLLIDER_HPP
