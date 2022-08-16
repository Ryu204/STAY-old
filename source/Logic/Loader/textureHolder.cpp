#include "../../../header/Logic/Loader/textureHolder.hpp"

#include <iostream>

void TextureHolder::load(const std::string& key, const std::string& filename)
{
	UPtr<sf::Texture> texture = std::make_unique<sf::Texture>();
	try
	{
		if (texture->loadFromFile(filename))
		{
			insert(key, std::move(texture));
		}
		else
		{
			throw std::runtime_error("Unable to load texture at " + filename);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}