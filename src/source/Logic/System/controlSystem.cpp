#include "../../../header/Logic/System/controlSystem.hpp"
#include "../../../header/Helper/utilise.hpp"

#include <cassert>
#include <memory>

namespace Logic
{
    ControlSystem::ControlSystem(ECS::Engine* engine)
        : System(engine)
    {
        m_states[Component::Control::NORMAL] = std::make_unique<Character::NormalState>(m_engine);
        // ...
    }  

    void ControlSystem::handle_event(const sf::Event& event)
    {
        for (auto& e : m_entities)
        {
            auto& ctrl = m_engine->get_component<Component::Control>(e);
            m_states[ctrl.current_state]->handle_event(event);
        }
    }


    void ControlSystem::update(sf::Time dt)
    {
        for (auto& e : m_entities)
        {
            auto& ctrl = m_engine->get_component<Component::Control>(e);
            auto& rd = m_engine->get_component<Component::Render>(e);

            if (ctrl.state_changed)
            {
                ctrl.state_changed = false;
                m_states[ctrl.current_state]->init(e);
            }
            m_states[ctrl.current_state]->update(dt, e);
        }
    }

    sf::Vector2f ControlSystem::get_player_center() const
    {
        assert(m_entities.size() == 1 && "Player is dead");

        const auto& en = *m_entities.begin();
        assert(m_engine->has_component<Component::Transform>(en) && "Player has no transform");
        const auto& tf = m_engine->get_component<Component::Transform>(en);
        return Utilise::get_center(tf.rect);
    }
}