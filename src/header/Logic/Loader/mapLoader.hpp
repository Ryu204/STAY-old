#ifndef STAY_LOGIC_LOADER_MAPLOADER_HPP
#define STAY_LOGIC_LOADER_MAPLOADER_HPP

/*
	Functions to load LDtk map into ECS engine
*/

#include <LDtkLoader/Project.hpp>

#include "../System/ecsInit.hpp"
#include "textureHolder.hpp"

namespace Game
{
	class MapLoader
	{
	public:
		MapLoader(const std::string& filepath);
		void load_to_engine(ECS::Engine* engine, TextureHolder* textures, const std::string& level) const;
	private:
		ldtk::Project m_project;
	};
}

#endif // !STAY_LOGIC_LOADER_MAPLOADER_HPP
