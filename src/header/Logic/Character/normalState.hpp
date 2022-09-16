#ifndef STAY_LOGIC_CHARACTER_NORMALSTATE_HPP
#define STAY_LOGIC_CHARACTER_NORMALSTATE_HPP

/*
	In this state, the player is a basic platformer
	with side movements and jump
*/

#include "characterState.hpp"

namespace Character
{
	class NormalState : public CharacterState
	{
	public:
		NormalState(ECS::Engine* engine);
		void update(sf::Time dt, ECS::Entity e) override;
	};
}

#endif // STAY_LOGIC_CHARACTER_NORMALSTATE_HPP
