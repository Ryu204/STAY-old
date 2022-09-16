#ifndef STAY_LOGIC_SYSTEM_CONTROLSYSTEM_HPP
#define STAY_LOGIC_SYSTEM_CONTROLSYSTEM_HPP

/*
	The state machine
*/

#include "../../Core/coreAlias.hpp"
#include "../../Core/ECS/engine.hpp"
#include "../Character/normalState.hpp"

#include "../Component/componentList.hpp"

namespace Logic
{
	class ControlSystem : public ECS::System
	{
	public:
		ControlSystem(ECS::Engine* engine);
		void handle_event(const sf::Event& e);
		void update(sf::Time dt);
		sf::Vector2f get_player_center() const;
	private:
		std::array<SPtr<Character::CharacterState>, Component::Control::STATECOUNT> m_states;
	};
}

#endif // !STAY_LOGIC_SYSTEM_POSITIONSYSTEM_HPP
