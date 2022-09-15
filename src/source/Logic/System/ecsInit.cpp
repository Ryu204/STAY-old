#include "../../../header/Logic/System/ecsInit.hpp"
#include "../../../header/Logic/Component/componentList.hpp"

namespace ECS
{
	void ECS_init(Engine* engine, RTarget* rtar, TextureHolder* txtrs,
		SPtr<Logic::RenderSystem>& renderer, 
		SPtr<Logic::RigidSystem>& rigid,
		SPtr<Collision::CollisionSystem>& collider,
		SPtr<Logic::PositionSystem>& positioner,
		SPtr<Logic::ControlSystem>& controller,
		SPtr<Logic::HookSystem>& hookgun)
	{
		// Register components
		engine->register_component<Component::Transform>();
		engine->register_component<Component::Render>();
		engine->register_component<Component::Rigidbody>();
		engine->register_component<Component::Collider>();
		engine->register_component<Component::Control>();
		engine->register_component<Component::Hook>();

		// Register and init systems
		renderer = engine->register_system<Logic::RenderSystem>();
		renderer->init(rtar);
		renderer->register_texture(&txtrs->get("test"));
		renderer->register_texture(&txtrs->get("Cat"));
		renderer->register_texture(&txtrs->get("Hook"));
		renderer->register_texture(&txtrs->get("Mossy"));

		rigid = engine->register_system<Logic::RigidSystem>();

		collider = engine->register_system<Collision::CollisionSystem>();

		positioner = engine->register_system<Logic::PositionSystem>();

		controller = engine->register_system<Logic::ControlSystem>();

		hookgun = engine->register_system<Logic::HookSystem>();
		hookgun->init(rtar, txtrs);

		// Set signature
		Signature s = engine->generate_Signature<Component::Transform, Component::Render>();
		engine->set_system_Signature<Logic::RenderSystem>(s);

		s = engine->generate_Signature<Component::Rigidbody>();
		engine->set_system_Signature<Logic::RigidSystem>(s);

		s = engine->generate_Signature<Component::Collider>();
		engine->set_system_Signature<Collision::CollisionSystem>(s);
		
		s = engine->generate_Signature<Component::Transform, Component::Rigidbody>();
		engine->set_system_Signature<Logic::PositionSystem>(s);

		s = engine->generate_Signature<Component::Rigidbody, Component::Control>();
		engine->set_system_Signature<Logic::ControlSystem>(s);

		s = engine->generate_Signature<Component::Collider, Component::Rigidbody, Component::Hook>();
		engine->set_system_Signature<Logic::HookSystem>(s);
	}
}