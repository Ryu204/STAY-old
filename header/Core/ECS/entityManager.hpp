#ifndef STAY_HEADER_CORE_ECS_ENTITYMANAGER_HPP
#define STAY_HEADER_CORE_ECS_ENTITYMANAGER_HPP

/*
	Part of ECS implementation
	The class responsible for lifecycles and Signatures of Entities
*/

#include <queue>
#include<array>

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

#endif // !STAY_HEADER_CORE_ECS_ENTITYMANAGER_HPP
