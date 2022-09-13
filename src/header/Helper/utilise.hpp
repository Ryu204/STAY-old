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

	inline sf::Vector2f get_center(const sf::FloatRect& rect)
	{
		return sf::Vector2f(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f);
	}

	// Linear interpolation between start and end
	// t is clamped
	template<typename T>
	T lerp(const T& start, const T& end, float t = 0.5f)
	{
		t = std::max(std::min(1.f, t), 0.f);
		return start * (1 - t) + end * t;
	}
}

#endif // !STAY_HELPER_UTILISE_HPP
