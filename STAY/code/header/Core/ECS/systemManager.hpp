#ifndef STAY_CORE_ECS_SYSTEMMANAGER_HPP
#define STAY_CORE_ECS_SYSTEMMANAGER_HPP

/*
	Part of ECS implementation
	This class registers and matches entities to 
	systems of corresponding signature
	===============================================
	Before using any system, the client must register the
	system via method: 
	SystemManager::register_system<T>()
	===============================================
	Key matching mechanism using bitwise operations
*/

#include <unordered_map>
#include <cassert>

#include "system.hpp"
#include "../coreAlias.hpp"

namespace ECS
{
	class Engine;

	class SystemManager
	{
	public:
		SystemManager();

		//This function returns a shared_ptr of the system
		template<typename T>
		SPtr<T> register_system(Engine* engine);

		template<typename T>
		void set_Signature(Signature s);

		void entity_Signature_changed(Entity e, Signature s);

		void entity_destroyed(Entity e);
	private:
		std::unordered_map<const char*, SPtr<System>> m_systems;
		std::unordered_map<const char*, Signature> m_Signatures;
	};

	template<typename T>
	SPtr<T> SystemManager::register_system(Engine* engine)
	{
		const char* name = typeid(T).name();
		assert(m_systems.find(name) == m_systems.end() && "System registered");
		auto res = std::make_shared<T>(engine);
		m_systems.emplace(name, res);
		m_Signatures.emplace(name, Signature());
		return res;
	}

	template<typename T>
	void SystemManager::set_Signature(Signature s)
	{
		const char* name = typeid(T).name();
		assert(m_systems.find(name) != m_systems.end() && "System has not been registered");
		m_Signatures[name] = s;
	}
}

#endif // !STAY_CORE_ECS_SYSTEMMANAGER_HPP
