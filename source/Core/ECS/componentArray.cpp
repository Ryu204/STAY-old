#include "../../header/Core/ECS/componentArray.hpp"

#include<cassert>

namespace ECS
{
	IComponentArray::IComponentArray() 
	{ }

	IComponentArray::~IComponentArray()
	{ }

	template<typename T>
	ComponentArray<T>::ComponentArray()
		: m_real_size(0)
	{ }

	template<typename T>
	void ComponentArray<T>::add_component(Entity e, T component)
	{
		assert(m_real_size >= MAX_COMPONENT && "Too much component");
		m_EnToIn[e] = m_real_size;
		m_InToE[m_real_size] = e;
		m_real_size++;
	}


}
