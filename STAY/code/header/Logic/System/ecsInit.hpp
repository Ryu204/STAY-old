#ifndef STAY_LOGIC_SYSTEM_ECSINIT_HPP
#define STAY_LOGIC_SYSTEM_ECSINIT_HPP

/*
	This header contains the function used for
	ECS machine initialisation
*/

#include "../../Core/ECS/engine.hpp"
#include "../../Core/coreAlias.hpp"
#include "renderSystem.hpp"
#include "rigidSystem.hpp"
#include "collisionSystem.hpp"
#include "positionSystem.hpp"
#include "controlSystem.hpp"
#include "../Loader/textureHolder.hpp"

namespace ECS
{
	void ECS_init(Engine* engine, RTarget* rtar, TextureHolder* txtrs,
		SPtr<Logic::RenderSystem>& renderer, 
		SPtr<Logic::RigidSystem>& rigid,
		SPtr<Collision::CollisionSystem>& collider,
		SPtr<Logic::PositionSystem>& positioner,
		SPtr<Logic::ControlSystem>& controller);
}

#endif // !STAY_LOGIC_SYSTEM_ECSINIT_HPP
