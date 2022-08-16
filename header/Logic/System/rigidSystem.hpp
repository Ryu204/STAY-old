#ifndef STAY_LOGIC_SYSTEM_RIGIDSYSTEM_HPP
#define STAY_LOGIC_SYSTEM_RIGIDSYSTEM_HPP

/*
	This system manages velocity and acceleration
	of entities
*/

#include "../../Core/coreAlias.hpp"
#include "../../Core/ECS/engine.hpp"

namespace Logic
{
	class RigidSystem : public ECS::System
	{
	public:
		RigidSystem(ECS::Engine* engine);
		void update(sf::Time dt);
	};
}

#endif // !STAY_LOGIC_SYSTEM_RIGIDSYSTEM_HPP
