#ifndef STAY_HELPER_UTILISE_HPP
#define STAY_HELPER_UTILISE_HPP

/*
	This file includes trivial functions that
	is used many times
*/

#include <SFML/Graphics.hpp>

namespace Utilise
{
	template<typename T>
	inline T dot_product(const sf::Vector2<T>& a, const sf::Vector2<T>& b)
	{
		return a.x * b.x + a.y * b.y;
	};

	inline void align(sf::FloatRect& moved, const sf::FloatRect& fixed)
	{
		sf::Vector2f center{ fixed.left + fixed.width / 2.f, fixed.top + fixed.height / 2.f };
		moved.left = center.x - moved.width / 2.f;
		moved.top = center.y - moved.height / 2.f;
	}
}

#endif // !STAY_HELPER_UTILISE_HPP
