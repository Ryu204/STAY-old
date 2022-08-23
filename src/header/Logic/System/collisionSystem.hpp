#ifndef STAY_LOGIC_SYSTEM_COLLISIONSYSTEM_HPP
#define STAY_LOGIC_SYSTEM_COLLISIONSYSTEM_HPP

/*
	This system resolves collision of objects
*/

#include <random>

#include "../../Core/ECS/engine.hpp"
#include "../../../header/Logic/Component/componentList.hpp"

namespace Collision
{
	class CollisionSystem : public ECS::System
	{
	public:
		CollisionSystem(ECS::Engine* engine);
		void update(sf::Time dt);
	private:
		// This function is called multiple times in update(dt)
		void process(sf::Time dt, const std::vector<ECS::Entity>& list);
	private:
		std::mt19937 m_random;
		std::unordered_map<ECS::Entity, Component::Collider*> m_colliders;
		std::unordered_map<ECS::Entity, Component::Rigidbody*> m_rigids;
		std::vector<ECS::Entity> m_list;
	};
}

#endif // !STAY_LOGIC_SYSTEM_COLLISIONSYSTEM_HPP
