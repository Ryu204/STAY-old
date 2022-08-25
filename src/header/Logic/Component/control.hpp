#ifndef STAY_LOGIC_COMPONENT_CONTROL_HPP
#define STAY_LOGIC_COMPONENT_CONTROL_HPP

/*
	This component is manipulated by the 
	state machine
*/

#include <SFML/Graphics.hpp>

namespace Component
{
	struct Control
	{
		float speed = 300.f;
		float gravity = 2000.f;
		float jump_height = 100.f;
	};
}

#endif // !STAY_LOGIC_COMPONENT_CONTROL_HPP
