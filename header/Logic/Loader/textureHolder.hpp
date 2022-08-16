#ifndef STAY_LOGIC_LOADER_TEXTUREHOLDER_HPP
#define STAY_LOGIC_LOADER_TEXTUREHOLDER_HPP

/*
	sf::Texture specialization for 
	ResourceHolder template class
*/

#include <SFML/Graphics.hpp>

#include "../../Core/resourceHolder.hpp"


class TextureHolder : public ResourceHolder<std::string, sf::Texture>
{
public:
	void load(const std::string& key, const std::string& filename);
};

#endif // !STAY_LOGIC_LOADER_TEXTUREHOLDER_HPP