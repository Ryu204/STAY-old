#ifndef STAY_CORE_ECS_SYSTEM_HPP
#define STAY_CORE_ECS_SYSTEM_HPP

/*
	Part of ECS implementation
	The base class that every system derives from
*/

#include<set>

#include "entity.hpp"

namespace ECS
{
	class Engine;

	class System
	{
	public:
		System(Engine* engine);
		virtual ~System() = default;
		// Derived classes will manipulate entities set and the engine pointer
		std::set<Entity> m_entities;
	protected:
		Engine* m_engine;
	};
}

#endif // !STAY_CORE_ECS_SYSTEM_HPP
