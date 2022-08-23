#include "../../../header/Core/ECS/componentManager.hpp"

namespace ECS
{
	ComponentManager::ComponentManager()
		: m_available_type(0)
	{ }

	void ComponentManager::entity_destroyed(Entity e)
	{
		for (auto p : m_arrays)
		{
			p.second->entity_destroyed(e);
		}
	}
}