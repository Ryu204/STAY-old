#ifndef STAY_LOGIC_CHARACTER_CHARACTERSTATE_HPP
#define STAY_LOGIC_CHARACTER_CHARACTERSTATE_HPP

/*
	Base class for player's FSM
*/

#include "../../Core/ECS/engine.hpp"

namespace Character
{
	class CharacterState
	{
	public:
		CharacterState(ECS::Engine* engine);
		virtual ~CharacterState();
		virtual void init(ECS::Entity e);
		virtual void handle_event(const sf::Event& e);
		virtual void update(sf::Time dt, ECS::Entity e);
	protected:
		ECS::Engine* m_engine;
	};
}

#endif // !STAY_LOGIC_CHARACTER_CHARACTERSTATE_HPP
