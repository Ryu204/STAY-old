#ifndef STAY_CORE_COREALIAS_HPP
#define STAY_CORE_COREALIAS_HPP

/*
	This file list #define macros and typedef
*/

#include <SFML/Graphics.hpp>
#include<memory>

template<typename T>
using UPtr = std::unique_ptr<T>;
template<typename T>
using SPtr = std::shared_ptr<T>;

typedef sf::RenderWindow RWindow;
typedef sf::RenderTarget RTarget;

#endif // !STAY_CORE_COREALIAS_HPP
