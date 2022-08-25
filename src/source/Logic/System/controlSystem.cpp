#include "../../../header/Logic/System/controlSystem.hpp"
#include "../../../header/Logic/Component/componentList.hpp"

#include <cassert>

namespace Logic
{
    ControlSystem::ControlSystem(ECS::Engine* engine)
        : System(engine)
    {

    }  

    void ControlSystem::update(sf::Time dt)
    {
        for (auto e : m_entities)
        {
            auto& ctrl = m_engine->get_component<Component::Control>(e);
            auto& rg = m_engine->get_component<Component::Rigidbody>(e);

            rg.velocity.x = 0;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                rg.velocity.x += ctrl.speed;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                rg.velocity.x -= ctrl.speed;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
                rg.velocity.y = -std::sqrt(2 * ctrl.gravity * ctrl.jump_height);

            rg.velocity.y += ctrl.gravity * dt.asSeconds();
        }
    }
}