#include "../../../header/Logic/Physics/collision.hpp"
#include "../../../header/Helper/utilise.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>

namespace Collision
{
    bool point_and_rect(sf::Vector2f point, const sf::FloatRect& rect)
    {
        return rect.contains(point);
    }

    bool AABB(const sf::FloatRect& rect1, const sf::FloatRect& rect2)
    {
        return rect1.intersects(rect2);
    }

    bool broad_phase(const sf::FloatRect& mover, sf::Vector2f path, const sf::FloatRect& target)
    {
        sf::FloatRect bounds(mover);
        bounds.left += std::min(0.f, path.x);
        bounds.top += std::min(0.f, path.y);
        bounds.width += abs(path.x);
        bounds.height += abs(path.y);

        return bounds.intersects(target);
    }

    bool vector_and_rect(sf::Vector2f root, sf::Vector2f path, const sf::FloatRect& target, float& time, sf::Vector2i& normal)
    {
        sf::Vector2f near, far;
        if (path.x == 0.f)
        {
            near.x = -std::numeric_limits<float>::infinity();
            far.x = std::numeric_limits<float>::infinity();
        }
        else
        {
            near.x = (target.left - root.x) / path.x;
            far.x = (target.left + target.width - root.x) / path.x;

            if (near.x > far.x)
                std::swap(near.x, far.x);
        }

        if (path.y == 0.f)
        {
            near.y = -std::numeric_limits<float>::infinity();
            far.y = std::numeric_limits<float>::infinity();
        }
        else
        {
            near.y = (target.top - root.y) / path.y;
            far.y = (target.top + target.height - root.y) / path.y;

            if (near.y > far.y)
                std::swap(near.y, far.y);
        }

        if (std::max(far.x, far.y) <= -eps)
            return false;
        if (std::min(near.x, near.y) >= 1 + eps)
            return false;
        if (near.x >= far.y || near.y >= far.x)
            return false;

        if (near.x >= near.y)
        {
            time = near.x;
            normal = RIGHT;
        }
        else
        {
            time = near.y;
            normal = DOWN;
        }
        
        return true;
    }

    void one_dimension(float& v1, float& v2, float m1, float m2, float e)
    {
        assert(m1 > 0 && m2 > 0 && "Mass must be positive");

        float u1 = v1, u2 = v2;
        if (m1 == INF && m2 == INF)
            return;
        else if (m1 == INF)
        {
            v2 = u1 + e * (u1 - u2);
        }
        else if (m2 == INF)
        {
            v1 = u2 + e * (u2 - u1);
        }
        else
        {
            v1 = (m1 * u1 + m2 * u2 + e * m2 * (u2 - u1)) / (m1 + m2);
            v2 = (m1 * u1 + m2 * u2 + e * m1 * (u1 - u2)) / (m1 + m2);
        }
    }

    bool entity_and_entity(const sf::FloatRect& e1, sf::Vector2f path1, const sf::FloatRect& e2, sf::Vector2f path2, float& time, sf::Vector2i& normal)
    {
        // We fix e2, then increase it sizes by half e1 each dimension
        // After that we consider the system of interest including
        // 2 objects

        sf::FloatRect boundsM = e1, boundsT = e2;

        if (broad_phase(boundsM, path1 - path2, boundsT))
        {
            boundsT.left -= boundsM.width / 2.0f;
            boundsT.top -= boundsM.height / 2.0f;
            boundsT.width += boundsM.width;
            boundsT.height += boundsM.height;

            sf::Vector2f root(e1.left + e1.width / 2.0f, e1.top + e1.height / 2.0f);

            if (vector_and_rect(root, path1 - path2, boundsT, time, normal))
                return true;
            else
                return false;
        }
        else
        {
            return false;
        }
    }

    void resolve(Component::Rigidbody& e1, Component::Rigidbody& e2, float time, sf::Vector2i normal, float cor)
    {
        float n1 = Utilise::dot_product(e1.velocity, sf::Vector2f{ normal });
        float n2 = Utilise::dot_product(e2.velocity, sf::Vector2f{ normal });

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            std::cout << std::setprecision(10) << time << '\n';

        if (e1.fixed)
            e1.mass = INF;
        if (e2.fixed)
            e2.mass = INF;
        
        float esl = 0.0f;
        one_dimension(n1, n2, e1.mass, e2.mass, cor);
        if (normal == DOWN)
        {
            if (!e1.fixed)
                e1.velocity.y = n1 * (1.f + esl);
            if (!e2.fixed)
                e2.velocity.y = n2 * (1.f + esl);
        }
        else 
        {
            if (!e1.fixed)
                e1.velocity.x = n1 * (1.f + esl);
            if (!e2.fixed)
                e2.velocity.x = n2 * (1.f + esl);
        }
    }
}