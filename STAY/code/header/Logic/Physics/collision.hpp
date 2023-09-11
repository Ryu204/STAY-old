#ifndef STAY_LOGIC_PHYSICS_COLLISION_HPP
#define STAY_LOGIC_PHYSICS_COLLISION_HPP

/*
    A collision-related functions collection
    ===============================================
    Collision detection: swept AABB
    Collision resolution: only resolve dynamic vs static
    ===============================================
    IMPORTANT NOTE !!!
    It's necessary that entities don't intersect before the update
    Otherwise the behaviours are undefined
*/

#include <SFML/Graphics.hpp>

#include "../Component/componentList.hpp"
#include "../System/ecsInit.hpp"

namespace Collision
{

    // ==============================================
    // Global constants
    const sf::Vector2f DOWN = sf::Vector2f(0.f, 1.f);
    const sf::Vector2f RIGHT = sf::Vector2f(1.f, 0.f);
    const sf::Vector2f UP = sf::Vector2f(0.f, -1.f);
    const sf::Vector2f LEFT = sf::Vector2f(-1.f, 0.f);
    const float INF = std::numeric_limits<float>::infinity();
    // ==============================================

    // Check if a point is inside a rectangle (not on)
    bool point_and_rect(sf::Vector2f point, const sf::FloatRect& rect);

    // Check if two rectangles is intersecting
    bool AABB(const sf::FloatRect& rect1, const sf::FloatRect& rect2);

    // Returns false if mover moving along path won't intersect target
    bool broad_phase(const sf::FloatRect& mover, sf::Vector2f path, const sf::FloatRect& target);

    // Check if vector intersects a rectangle
    // time is how much we have to scale path to meet the rect
    // normal is the normal vector of the collision surface
    bool vector_and_rect(sf::Vector2f root, sf::Vector2f path, const sf::FloatRect& target, float& time, sf::Vector2f& normal);

    // Check if 2 entity will collide and return according time and normal
    bool entity_and_entity(const sf::FloatRect& mover, sf::Vector2f path, const sf::FloatRect& target, float& time, sf::Vector2f& normal);

    // Resolve elastic collision
    void resolve(Component::Rigidbody& mover, float time, sf::Vector2f normal);
}

#endif // !STAY_LOGIC_PHYSICS_COLLISION_HPP
