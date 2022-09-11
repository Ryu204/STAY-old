#include "../../../header/Logic/Loader/mapLoader.hpp"
#include "../../../header/Logic/Loader/preset.hpp"

namespace Game
{
	MapLoader::MapLoader(const std::string& filepath)
	{
		try
		{
			m_project.loadFromFile(filepath);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	void MapLoader::load_to_engine(ECS::Engine* engine, TextureHolder* textures, const std::string& level) const
	{
		try
		{
			const auto& level_map = m_project.getWorld().getLevel(level);

			for (const auto& layer : level_map.allLayers())
			{
				const std::string& name = layer.getName();

				if (name == "Collision")
				{
					for (const auto& entity : layer.allEntities())
					{
						const auto& pos = entity.getPosition();
						const auto& size = entity.getSize();
						Preset::create_collider(engine, sf::FloatRect{ (float)pos.x, (float)pos.y, (float)size.x, (float)size.y });
					}
				}

				else if (name == "Tile")
				{
					const auto& size = layer.getCellSize();
					sf::Texture* texture = &textures->get(layer.getTileset().name);
					for (const auto& tile : layer.allTiles())
					{
						const auto& pos = tile.getPosition();
						const auto& trect = tile.getTextureRect();
						Preset::create_tile(engine, sf::FloatRect{ (float)pos.x, (float)pos.y, (float)size, (float)size },
							texture, sf::IntRect{ trect.x, trect.y, trect.width, trect.height });
					}
				}

				else if (name == "Player")
				{
					const auto& player = layer.getEntitiesByName("PlayerInit");
					assert(player.size() == 1 && "Incorrect amount of player (!= 1)");
					ldtk::Entity& entity = player[0];
					const auto& pos = entity.getPosition();
					const auto& size = entity.getSize();
					sf::Texture* texture = &textures->get(entity.getField<std::string>("TextureID").value());
					const auto& trect = sf::IntRect(0, 0, 128, 128);
					const auto& collider = entity.getArrayField<float>("CollisionRect");

					Preset::create_player(engine, sf::FloatRect{(float)pos.x, (float)pos.y, (float)size.x, (float)size.y},
						sf::FloatRect{ collider[0].value(), collider[1].value(), collider[2].value(), collider[3].value() },
						texture, trect, entity.getField<float>("Speed").value(),
						entity.getField<float>("Gravity").value(),
						entity.getField<float>("Jump").value());
				}
			}
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
