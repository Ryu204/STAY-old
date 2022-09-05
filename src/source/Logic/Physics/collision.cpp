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

    bool vector_and_rect(sf::Vector2f root, sf::Vector2f path, const sf::FloatRect& target, float& time, sf::Vector2f& normal)
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

        if (far.x <= 0.f && far.y <= 0.f)
            return false;
        if (near.x >= 1.f && near.y >= 1.f)
            return false;
        if (near.x >= far.y || near.y >= far.x)
            return false;

        if (near.x >= near.y)
        {
            time = near.x;
            if (path.x < 0)
                normal = RIGHT;
            else
                normal = LEFT;
        }
        else
        {
            time = near.y;
            if (path.y < 0)
                normal = DOWN;
            else
                normal = UP;
        }
        
        return true;
    }

    bool entity_and_entity(const sf::FloatRect& mover, sf::Vector2f path, const sf::FloatRect& target, float& time, sf::Vector2f& normal)
    {
        sf::FloatRect boundsM = mover, boundsT = target;

        if (broad_phase(boundsM, path, boundsT))
        {
            boundsT.left -= boundsM.width / 2.0f;
            boundsT.top -= boundsM.height / 2.0f;
            boundsT.width += boundsM.width;
            boundsT.height += boundsM.height;

            sf::Vector2f root(mover.left + mover.width / 2.0f, mover.top + mover.height / 2.0f);

            if (vector_and_rect(root, path, boundsT, time, normal))
                return true;
            else
                return false;
        }
        else
        {
            return false;
        }
    }

    void resolve(Component::Rigidbody& mover, float time, sf::Vector2f normal)
    {
        mover.velocity.x += (abs(mover.velocity.x) + 10.f) * normal.x * (1.f - time);
        mover.velocity.y += (abs(mover.velocity.y) + 10.f) * normal.y * (1.f - time);
    }
}