#include "../../../header/Logic/System/controlSystem.hpp"
#include "../../../header/Logic/Component/componentList.hpp"
#include "../../../header/Helper/utilise.hpp"

#include <cassert>
#include <cmath>

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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && !ctrl.jumped)
            {
                rg.velocity.y = -std::sqrt(2 * ctrl.gravity * ctrl.jump_height);
                ctrl.jumped = true;
            }

            rg.velocity.y += ctrl.gravity * dt.asSeconds();
        }
    }

    sf::Vector2f ControlSystem::get_player_center() const
    {
        assert(m_entities.size() != 0 && "Player is dead");

        const auto& en = *m_entities.begin();
        assert(m_engine->has_component<Component::Transform>(en) && "Player has no transform");
        const auto& tf = m_engine->get_component<Component::Transform>(en);
        return Utilise::get_center(tf.rect);
    }
}