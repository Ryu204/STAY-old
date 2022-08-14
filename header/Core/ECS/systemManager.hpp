#ifndef STAY_HEADER_CORE_ECS_SYSTEMMANAGER_HPP
#define STAY_HEADER_CORE_ECS_SYSTEMMANAGER_HPP

/*
	Part of ECS implementation
	This class manages registration and match Entities to 
	system of corresponding Signature
	===============================================
	Before using any system, the client must register the
	system via method: 
	SystemManager::register_system<T>()
	===============================================
	Which every Entity has all the required Components of
	a specific system will belong to that system
	One Entity can belong to many systems
	===============================================
	The core mechanism here is bitwise operations
*/

#include <map>
#include <memory>
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
		std::map<const char*, SPtr<System>> m_systems;
		std::map<const char*, Signature> m_Signatures;
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

#endif // !STAY_HEADER_CORE_ECS_SYSTEMMANAGER_HPP
