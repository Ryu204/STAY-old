#ifndef STAY_CORE_ECS_VALUE_HPP
#define STAY_CORE_ECS_VALUE_HPP

/*
	Part of ECS implementation
	This file defines the limit values of ECS structure
*/

#include <numeric>

namespace ECS
{
	constexpr std::size_t MAX_ENTITY = 5000;
	constexpr std::size_t MAX_COMPONENT = 64;
}

#endif //!STAY_CORE_ECS_VALUE_HPP