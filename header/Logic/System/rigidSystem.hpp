#ifndef STAY_HEADER_LOGIC_SYSTEM_RIGIDSYSTEM_HPP
#define STAY_HEADER_LOGIC_SYSTEM_RIGIDSYSTEM_HPP

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

#endif // !STAY_HEADER_LOGIC_SYSTEM_RIGIDSYSTEM_HPP
