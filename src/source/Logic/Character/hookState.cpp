#include "../../../header/Logic/Character/hookState.hpp"
#include "../../../header/Logic/Component/componentList.hpp"
#include<cmath>

namespace Character
{
	HookState::HookState(ECS::Engine* engine)
		: CharacterState(engine)
	{ }

	void HookState::update(sf::Time dt, ECS::Entity e)
	{
		
	}
}
