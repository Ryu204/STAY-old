#ifndef STAY_LOGIC_SYSTEM_HOOKSYSTEM_HPP
#define STAY_LOGIC_SYSTEM_HOOKSYSTEM_HPP

/*
	System for shooting hook :')
*/

#include "../../Core/ECS/engine.hpp"
#include "../Loader/textureHolder.hpp"

namespace Logic
{
	class HookSystem : public ECS::System
	{
	public:
		HookSystem(ECS::Engine* engine);
		void init(sf::RenderTarget* target, TextureHolder* textures);
		void update(sf::Time dt);

		// Render the string and head
		void draw();
	private:
		//void add_head(const sf::FloatRect& tf_rect, sf::Vector2f dir, )
		sf::Texture* m_hook_texture;
		sf::RenderTarget* m_render_target;
	};
}

#endif // !STAY_LOGIC_SYSTEM_HOOKSYSTEM_HPP
