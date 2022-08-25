#ifndef STAY_LOGIC_SYSTEM_CONTROLSYSTEM_HPP
#define STAY_LOGIC_SYSTEM_CONTROLSYSTEM_HPP

/*
	The state machine
*/

#include "../../Core/coreAlias.hpp"
#include "../../Core/ECS/engine.hpp"

namespace Logic
{
	class ControlSystem : public ECS::System
	{
	public:
		ControlSystem(ECS::Engine* engine);
		void update(sf::Time dt);
	};
}

#endif // !STAY_LOGIC_SYSTEM_POSITIONSYSTEM_HPP
