#include <iostream>

#include "../header/application.hpp"

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	Application app;
	app.run();
}