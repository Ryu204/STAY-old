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
		enum State
		{
			NORMAL,
			HOOK,
			STATECOUNT
		};
		float speed = 300.f;
		float gravity = 2000.f;
		float jump_height = 100.f;

		// Conditional

		bool jumped = false;
		bool face_right = true;
		State current_state = NORMAL;
		bool state_changed = false;
	};
}

#endif // !STAY_LOGIC_COMPONENT_CONTROL_HPP
