#ifndef STAY_LOGIC_CHARACTER_HOOKSTATE_HPP
#define STAY_LOGIC_CHARACTER_HOOKSTATE_HPP

/*
	In this state, the player movement is
	controlled by the hook mechanic only
*/

#include "characterState.hpp"

namespace Character
{
	class HookState : public CharacterState
	{
	public:
		HookState(ECS::Engine* engine);
		void init(ECS::Entity e) override;
		void update(sf::Time dt, ECS::Entity e) override;
		void handle_event(const sf::Event& e) override;
	};
}

#endif // STAY_LOGIC_CHARACTER_NORMALSTATE_HPP
