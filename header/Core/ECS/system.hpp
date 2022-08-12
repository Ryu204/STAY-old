#ifndef STAY_HEADER_CORE_ECS_SYSTEM_HPP
#define STAY_HEADER_CORE_ECS_SYSTEM_HPP

/*
	Part of ECS implementation
	The base class that every system derives from
*/

#include<set>

#include "entity.hpp"

namespace ECS
{
	class System
	{
	public:
		System();
	protected:
		// Derived classes will manipulate these two members
		std::set<Entity> m_entities;
		// Engine* m_engine;
	};
}

#endif // !STAY_HEADER_CORE_ECS_SYSTEM_HPP
