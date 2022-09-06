#include "../../../header/Logic/Loader/textureHolder.hpp"

#include <iostream>

void TextureHolder::load(const std::string& key, const std::string& filename)
{
	UPtr<sf::Texture> texture = std::make_unique<sf::Texture>();
	
	if (texture->loadFromFile(filename))
	{
		insert(key, std::move(texture));
	}
	else
	{
		std::cerr << "Unable to load texture at " << filename << '\n';
	}
}