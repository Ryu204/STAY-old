#ifndef STAY_LOGIC_PHYSICS_COLLISION_HPP
#define STAY_LOGIC_PHYSICS_COLLISION_HPP

/*
    A collision-related functions collection
    ===============================================
    Collision detection: swept AABB
    Collision resolution: cut down velocity + 2d 
    elastic collision
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
    const sf::Vector2i DOWN = sf::Vector2i(0, 1);
    const sf::Vector2i RIGHT = sf::Vector2i(1, 0);
    const float INF = std::numeric_limits<float>::infinity();
    const float eps = 0.001f;
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
    bool vector_and_rect(sf::Vector2f root, sf::Vector2f path, const sf::FloatRect& target, float& time, sf::Vector2i& normal);

    // one dimension elastic collision
    // v1, v2: initial scalar velocity
    // m1, m2: mass
    // e: coefficient of resistution
    // This function modifies v1 and v2
    void one_dimension(float& v1, float& v2, float m1, float m2, float e);

    // Check if 2 entity will collide and return according time and normal
    bool entity_and_entity(const sf::FloatRect& e1, sf::Vector2f path1, const sf::FloatRect& e2, sf::Vector2f path2, float& time, sf::Vector2i& normal);

    // Resolve elastic collision
    void resolve(Component::Rigidbody& e1, Component::Rigidbody& e2, float time, sf::Vector2i normal, float cor);
}

#endif // !STAY_LOGIC_PHYSICS_COLLISION_HPP
