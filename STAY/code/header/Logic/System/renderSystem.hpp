#ifndef STAY_LOGIC_SYSTEM_RENDERSYSTEM_HPP
#define STAY_LOGIC_SYSTEM_RENDERSYSTEM_HPP

/*
	This system draws entities using sf::VertexArray
	It layers objects using their texture as the layer
	
	That limits a lot of things, though
*/

#include <map>
#include <vector>

#include "../../Core/coreAlias.hpp"
#include "../../Core/ECS/engine.hpp"

namespace Logic
{
	class RenderSystem : public ECS::System
	{
	public:
		RenderSystem(ECS::Engine* engine);
		void init(RTarget* target);
		void render(const sf::View& view);
		void register_texture(const sf::Texture* txtr);
	private:
		// This function updates the vertex arrays
		void batch_vertices(const sf::View& view);
	private:
		RTarget* m_target;
		std::map<const sf::Texture*, sf::VertexArray> m_vertex_arr;
		std::vector<const sf::Texture*> m_layers;
	};
}

#endif // !STAY_LOGIC_SYSTEM_RENDERSYSTEM_HPP
