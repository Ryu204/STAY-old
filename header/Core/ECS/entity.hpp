#ifndef STAY_HEADER_CORE_ECS_ENTITY_HPP
#define STAY_HEADER_CORE_ECS_ENTITY_HPP

/*
	Part of ECS implementation
	Define Entity as a simple unsigned interger
	Define Signature (Key) as a bitset with length of STAY_MAX_COMPONENT
*/

#include <numeric>
#include <bitset>

#include "value.hpp"

namespace ECS
{
	typedef std::uint64_t Entity;
	typedef std::bitset<MAX_COMPONENT> Signature;
}

#endif // !STAY_HEADER_CORE_ECS_ENTITY_HPP
