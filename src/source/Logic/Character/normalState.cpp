#include "../../../header/Logic/Character/normalState.hpp"
#include "../../../header/Logic/Component/componentList.hpp"
#include<cmath>

namespace Character
{
	NormalState::NormalState(ECS::Engine* engine)
		: CharacterState(engine)
	{ }

	void NormalState::update(sf::Time dt, ECS::Entity e)
	{
		auto& rg = m_engine->get_component<Component::Rigidbody>(e);
		auto& ctrl = m_engine->get_component<Component::Control>(e);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && !ctrl.jumped)
		{
			rg.velocity.y = -std::sqrt(2 * ctrl.jump_height * abs(rg.acceleration.y));
		}

		rg.velocity.x = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			rg.velocity.x += ctrl.speed;
			ctrl.face_right = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			rg.velocity.x -= ctrl.speed;
			ctrl.face_right = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && !ctrl.jumped)
		{
			rg.velocity.y = -std::sqrt(2 * ctrl.gravity * ctrl.jump_height);
			ctrl.jumped = true;
		}
	}
}
