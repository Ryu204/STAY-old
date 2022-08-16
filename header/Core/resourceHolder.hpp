#ifndef STAY_CORE_RESOURCEHOLDER_HPP
#define STAY_CORE_RESOURCEHOLDER_HPP

/*
	This class is a container used to store
	heavyweight resource

	No resource copy is made
*/

#include <map>
#include <functional>
#include <cassert>

#include "coreAlias.hpp"

template<typename T_key, typename T_val>
class ResourceHolder
{
public:
	ResourceHolder();
	T_val& get(const T_key& key);
	const T_val& get(const T_key& key) const;
	void insert(const T_key& key, UPtr<T_val> val);
	void remove(const T_key& key);
private:
	std::map<T_key, UPtr<T_val>> m_container;
};

template<typename T_key, typename T_val>
ResourceHolder<T_key, T_val>::ResourceHolder()
{ }

template<typename T_key, typename T_val>
T_val& ResourceHolder<T_key, T_val>::get(const T_key& key)
{
	assert(m_container.find(key) != m_container.end() && "Resource not loaded");
	return *m_container[key];
}

template<typename T_key, typename T_val>
const T_val& ResourceHolder<T_key, T_val>::get(const T_key& key) const
{
	assert(m_container.find(key) != m_container.end() && "Resource not loaded");
	return *m_container[key];
}

template<typename T_key, typename T_val>
void ResourceHolder<T_key, T_val>::insert(const T_key& key, UPtr<T_val> val)
{
	assert(m_container.find(key) == m_container.end() && "Resource loaded twice");
	m_container.emplace(key, std::move(val));
}

template<typename T_key, typename T_val>
void ResourceHolder<T_key, T_val>::remove(const T_key& key)
{
	assert(m_container.find(key) != m_container.end() && "Resource not loaded");
	m_container.erase(key);
}

#endif // !STAY_CORE_RESOURCEHOLDER_HPP
