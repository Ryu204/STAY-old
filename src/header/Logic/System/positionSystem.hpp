#ifndef STAY_LOGIC_SYSTEM_POSITIONSYSTEM_HPP
#define STAY_LOGIC_SYSTEM_POSITIONSYSTEM_HPP

/*
	This system changes entities' position based
	on velocity
*/

#include "../../Core/coreAlias.hpp"
#include "../../Core/ECS/engine.hpp"

namespace Logic
{
	class PositionSystem : public ECS::System
	{
	public:
		PositionSystem(ECS::Engine* engine);
		void update(sf::Time dt);
	};
}

#endif // !STAY_LOGIC_SYSTEM_POSITIONSYSTEM_HPP
