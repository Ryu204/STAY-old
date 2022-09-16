#include "../../../header/Logic/Character/characterState.hpp"

namespace Character
{
	CharacterState::CharacterState(ECS::Engine* engine)
		: m_engine(engine)
	{ }

	CharacterState::~CharacterState()
	{ }
	
	void CharacterState::init(ECS::Entity e)
	{ }
	
	void CharacterState::handle_event(const sf::Event& e)
	{ }
	
	void CharacterState::update(sf::Time dt, ECS::Entity e)
	{ }
}