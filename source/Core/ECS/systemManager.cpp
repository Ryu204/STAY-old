#include "../../header/Core/ECS/systemManager.hpp"

namespace ECS
{
	SystemManager::SystemManager()
	{ }

	void SystemManager::entity_destroyed(Entity e)
	{
		for (auto p : m_systems)
		{
			p.second->m_entities.erase(e);
		}
	}

	void SystemManager::entity_Signature_changed(Entity e, Signature s)
	{
		for (auto p : m_systems)
		{
			Signature key = m_Signatures[p.first];

			// If the Signature matches the system's Signature
			if ((key & s) == key)
			{
				p.second->m_entities.insert(e);
			}
		}
	}
}