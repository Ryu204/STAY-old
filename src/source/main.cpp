#include <iostream>
#include <iomanip>

#include "../header/application.hpp"

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	srand(static_cast<unsigned int>(time(NULL)));
	Application app;
	app.run();
}