#include "../../../header/Logic/System/renderSystem.hpp"
#include "../../../header/Logic/Component/componentList.hpp"

#include <cassert>

namespace Logic
{
	RenderSystem::RenderSystem(ECS::Engine* engine)
		: System(engine)
		, m_target(nullptr)
	{

	}

	void RenderSystem::init(RTarget* target)
	{
		m_target = target;
	}

	void RenderSystem::render()
	{
		batch_vertices();
		for (auto& p : m_vertex_arr)
		{
			m_target->draw(p.second, p.first);
		}
	}

    void RenderSystem::register_texture(const sf::Texture* txtr)
    {
        assert(m_vertex_arr.find(txtr) == m_vertex_arr.end() && "Texture registered");
        m_vertex_arr.emplace(txtr, sf::VertexArray(sf::Quads));
    }

	void RenderSystem::batch_vertices()
	{
        for (auto& p : m_vertex_arr)
        {
            p.second.clear();
        }
        for (auto e : m_entities)
        {
            auto const& rd = m_engine->get_component<Component::Render>(e);
            auto const& tf = m_engine->get_component<Component::Transform>(e);
            sf::Vertex v[4];
            // Init rect position
            v[0].position = sf::Vector2f(0.1f + std::floor(tf.rect.left), 0.1f + std::floor(tf.rect.top));
            v[1].position = sf::Vector2f(0.1f + std::floor(tf.rect.left + tf.rect.width), 0.1f + std::floor(tf.rect.top));
            v[2].position = sf::Vector2f(0.1f + std::floor(tf.rect.left + tf.rect.width), 0.1f + std::floor(tf.rect.top + tf.rect.height));
            v[3].position = sf::Vector2f(0.1f + std::floor(tf.rect.left), 0.1f + std::floor(tf.rect.top + tf.rect.height));
            // Rotation and Scale
            sf::Transformable trans;
            trans.setOrigin(tf.rect.left + tf.rect.width / 2, tf.rect.top + tf.rect.height / 2);
            trans.setRotation(tf.rotation);
            trans.setScale(tf.scale);
            for (int i = 0; i < 4; i++)
                trans.getTransform().transformPoint(v[i].position);
            // Texture
            v[0].texCoords = sf::Vector2f(sf::Vector2i(rd.texture_rect.left, rd.texture_rect.top));
            v[1].texCoords = sf::Vector2f(sf::Vector2i(rd.texture_rect.left + rd.texture_rect.width, rd.texture_rect.top));
            v[2].texCoords = sf::Vector2f(sf::Vector2i(rd.texture_rect.left + rd.texture_rect.width, rd.texture_rect.top + rd.texture_rect.height));
            v[3].texCoords = sf::Vector2f(sf::Vector2i(rd.texture_rect.left, rd.texture_rect.top + rd.texture_rect.height));
            // Batching
            for (int i = 0; i < 4; i++)
            {
                v[i].color = rd.color;
                assert(m_vertex_arr.find(rd.texture) != m_vertex_arr.end() && "Unregistered texture!");
                m_vertex_arr[rd.texture].append(v[i]);
            }
        }
	}
}