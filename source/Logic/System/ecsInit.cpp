#include "../../../header/Logic/System/ecsInit.hpp"
#include "../../../header/Logic/Component/componentList.hpp"
#include "../../../header/Logic/System/systemList.hpp"

namespace ECS
{
	void ECS_init(Engine* engine, RTarget* rtar, SPtr<Logic::RenderSystem>& renderer, SPtr<Logic::RigidSystem>& rigid)
	{
		// Register components
		engine->register_component<Component::Transform>();
		engine->register_component<Component::Render>();
		engine->register_component<Component::Rigidbody>();

		// Register and init systems
		renderer = engine->register_system<Logic::RenderSystem>();
		renderer->init(rtar);
		renderer->register_texture(nullptr);

		rigid = engine->register_system<Logic::RigidSystem>();

		// Set signature
		Signature s = engine->generate_Signature<Component::Transform, Component::Render>();
		engine->set_system_Signature<Logic::RenderSystem>(s);

		s = engine->generate_Signature<Component::Transform, Component::Rigidbody>();
		engine->set_system_Signature<Logic::RigidSystem>(s);
	}
}