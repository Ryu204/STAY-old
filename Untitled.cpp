#include <iostream>
#include <SFML/Graphics.hpp>
#include <lua.hpp>

int main()
{
	sf::RenderWindow win(sf::VideoMode(100, 100), "Window");
	while (win.isOpen())
	{
		sf::Event e;
		while (win.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				win.close();
		}

		win.clear(sf::Color::Blue);
		win.display();
	}
}