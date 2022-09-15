#include "../../../header/Logic/Loader/preset.hpp"
#include "../../../header/Logic/Component/componentList.hpp"

namespace Preset
{
	void create_collider(ECS::Engine* engine, sf::FloatRect rect)
	{
		const auto& en = engine->create_entity();
		engine->add_component(en, Component::Collider{ rect, Component::Collider::Platform });
	}

	void create_tile(ECS::Engine* engine, sf::FloatRect rect, sf::Texture* texture,
		sf::IntRect texture_rect)
	{
		const auto& en = engine->create_entity();
		engine->add_component(en, Component::Transform{ rect });
		engine->add_component(en, Component::Render{ texture, texture_rect });
	}

	void create_player(ECS::Engine* engine, sf::FloatRect transform_rect, sf::FloatRect collider_rect, sf::Texture* texture, sf::IntRect texture_rect, float speed, float gravity, float jump_height)
	{
		const auto& en = engine->create_entity();
		engine->add_component(en, Component::Transform{ transform_rect });
		engine->add_component(en, Component::Rigidbody{ });
		engine->add_component(en, Component::Collider{ collider_rect, Component::Collider::Player });
		engine->add_component(en, Component::Render{ texture, texture_rect });
		engine->add_component(en, Component::Control{ speed, gravity, jump_height, false });
		engine->add_component(en, Component::Hook{ Component::Hook::Idle });
	}
}