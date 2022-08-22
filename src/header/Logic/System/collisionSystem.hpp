#ifndef STAY_LOGIC_SYSTEM_COLLISIONSYSTEM_HPP
#define STAY_LOGIC_SYSTEM_COLLISIONSYSTEM_HPP

/*
	This system resolves collision of objects
*/

#include <random>

#include "../../Core/ECS/engine.hpp"

namespace Collision
{
	class CollisionSystem : public ECS::System
	{
	public:
		CollisionSystem(ECS::Engine* engine);
		void update(sf::Time dt);
	private:
		// This function is called multiple times in update(dt)
		void process(sf::Time dt);
	private:
		std::mt19937 m_random;
	};
}

#endif // !STAY_LOGIC_SYSTEM_COLLISIONSYSTEM_HPP
