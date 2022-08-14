#ifndef STAY_HEADER_LOGIC_SYSTEM_ECSINIT_HPP
#define STAY_HEADER_LOGIC_SYSTEM_ECSINIT_HPP

#include "../../Core/ECS/engine.hpp"
#include "../../Core/coreAlias.hpp"
#include "renderSystem.hpp"
#include "rigidSystem.hpp"

namespace ECS
{
	void ECS_init(Engine* engine, RTarget* rtar, SPtr<Logic::RenderSystem>& renderer, SPtr<Logic::RigidSystem>& rigid);
}

#endif // !STAY_HEADER_LOGIC_SYSTEM_ECSINIT_HPP
