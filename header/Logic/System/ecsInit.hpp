#ifndef STAY_LOGIC_SYSTEM_ECSINIT_HPP
#define STAY_LOGIC_SYSTEM_ECSINIT_HPP

#include "../../Core/ECS/engine.hpp"
#include "../../Core/coreAlias.hpp"
#include "renderSystem.hpp"
#include "rigidSystem.hpp"
#include "../Loader/textureHolder.hpp"

namespace ECS
{
	void ECS_init(Engine* engine, RTarget* rtar, TextureHolder* txtrs,
		SPtr<Logic::RenderSystem>& renderer, 
		SPtr<Logic::RigidSystem>& rigid);
}

#endif // !STAY_LOGIC_SYSTEM_ECSINIT_HPP
