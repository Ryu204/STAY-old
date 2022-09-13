#ifndef STAY_LOGIC_SYSTEM_CAMERACONTROLLER_HPP
#define STAY_LOGIC_SYSTEM_CAMERACONTROLLER_HPP

/*
	This class is not a ECS::System
	It controls the viewport to follow player
	At any moment the camera is snapped inside one
	sf::FloatRect of m_regions
*/

#include <SFML/Graphics.hpp>

namespace Logic
{
	class CameraController
	{
	public:
		CameraController(const sf::View& view);
		CameraController(sf::Vector2f size);
		const sf::View& get_view() const;

		// Add a region to the list
		void add_region(sf::FloatRect region);

		// Update the camera to view target
		void update(sf::Vector2f target, sf::Time dt);
	private:
		sf::View m_view;
		std::vector<sf::FloatRect> m_regions;
	};
}

#endif // !STAY_LOGIC_SYSTEM_CAMERACONTROLLER_HPP
