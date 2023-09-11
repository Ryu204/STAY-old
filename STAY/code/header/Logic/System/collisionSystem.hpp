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
		std::unordered_map<ECS::Entity, Component::Collider*> m_colliders;
	};
}

#endif // !STAY_LOGIC_SYSTEM_COLLISIONSYSTEM_HPP
