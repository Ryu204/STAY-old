#ifndef STAY_CORE_ECS_ENTITYMANAGER_HPP
#define STAY_CORE_ECS_ENTITYMANAGER_HPP

/*
	Part of ECS implementation
	This class is responsible for lifecycles 
	and signatures of entities
*/

#include <queue>
#include <array>

#include "entity.hpp"

namespace ECS
{
	class EntityManager
	{
	public:
		EntityManager();
		Entity create();
		void retrieve(Entity e);

		// These 2 functions don't gurantee the Entity is still active
		void set_Signature(Entity e, Signature s);
		Signature get_Signature(Entity e) const;
	private:
		std::queue<Entity> m_entities;
		std::array<Signature, MAX_ENTITY> m_Signatures;
	};
}

#endif // !STAY_CORE_ECS_ENTITYMANAGER_HPP
