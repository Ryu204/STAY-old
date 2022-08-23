#include "../../../header/Core/ECS/entityManager.hpp"

#include <cassert>

namespace ECS
{
	EntityManager::EntityManager()
	{
		for (Entity i = 0; i < MAX_ENTITY; i++)
		{
			m_entities.push(i);
			m_Signatures[i] = Signature();
		}
	}

	Entity EntityManager::create()
	{
		assert(!m_entities.empty() && "Too much entities presented!");
		Entity res = m_entities.front();
		m_entities.pop();
		return res;
	}

	void EntityManager::retrieve(Entity e)
	{
		assert(e < MAX_ENTITY && "Entity out of range");
		m_Signatures[e] = Signature();
		m_entities.push(e);
	}

	void EntityManager::set_Signature(Entity e, Signature s)
	{
		assert(e < MAX_ENTITY && "Entity out of range");
		m_Signatures[e] = s;
	}

	Signature EntityManager::get_Signature(Entity e) const
	{
		assert(e < MAX_ENTITY && "Entity out of range");
		return m_Signatures[e];
	}
}