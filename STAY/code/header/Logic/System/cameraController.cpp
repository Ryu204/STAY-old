#include "../../../header/Logic/System/cameraController.hpp"
#include "../../../header/Helper/utilise.hpp"

#include <iostream>

namespace Logic
{
	CameraController::CameraController(const sf::View& view)
		: m_view(view)
	{ }

	CameraController::CameraController(sf::Vector2f size)
		: m_view(sf::Vector2f(), size)
	{ }

	void CameraController::add_region(sf::FloatRect region)
	{
		m_regions.push_back(region);
	}

	void CameraController::update(sf::Vector2f target, sf::Time dt)
	{
		const auto& size = m_view.getSize();
		// Find the right region and snap the camera inside it
		for (auto& reg : m_regions)
		{
			if (reg.contains(target))
			{
				target.x = std::max(target.x, reg.left + size.x / 2.f);
				target.x = std::min(target.x, reg.left + reg.width - size.x / 2.f);
				target.y = std::max(target.y, reg.top + size.y / 2.f);
				target.y = std::min(target.y, reg.top + reg.height - size.y / 2.f);
				// no continue
				break;
			}
		}

		m_view.setCenter(target);
	}

	const sf::View& CameraController::get_view() const
	{
		return m_view;
	}
}