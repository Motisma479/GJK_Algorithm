#include "Physics/GJK.hpp"

#include "raylib.hpp"

#include <iostream>

using namespace Maths;

Vec3 support(Resources::Shapes& a, Resources::Shapes& b, const Vec3& direction)
{
	//std::cout << "\r direction = "<< direction << "      a furthestPoint = " << a.GetfurthestPoint(direction) << "       b furthestPoint = " << b.GetfurthestPoint(-direction);

    Vec3 pos = (a.GetPosition() - b.GetPosition());


	return a.GetfurthestPoint(direction) - b.GetfurthestPoint(-direction) + pos;
}

bool simplexContainsOrigin(std::vector<Vec3>& simplex, Vec3& direction) {
    Vec3 A = simplex.back();
    Vec3 AO = -A;

    Vec3 C = simplex[0];
    Vec3 AC = C-A;

    if (simplex.size() == 2)
    {
        direction = Vectors::CrossProduct(Vectors::CrossProduct(AC, AO), AC);
        return false;
    }

    Vec3 B = simplex[1];

    Vec3 AB = B-A;

    Vec3 ABp = Vectors::CrossProduct(Vectors::CrossProduct(AC, AB), AB);
    if (Maths::Vectors::DotProduct(ABp, AO) > 0)
    {
        //direction = ACp;
        simplex.erase(simplex.begin());
        direction = ABp;
        return false;
    }

    Vec3 ACp = Vectors::CrossProduct(Vectors::CrossProduct(AB, AC), AC);
    if (Maths::Vectors::DotProduct(ACp, AO) > 0)
    {

        simplex.erase(simplex.begin()+1);
        direction = ACp;
        return false;
    }

    return true;
}

bool Physics::TestCollision(Resources::Shapes& a, Resources::Shapes& b)
{
    Vec3 direction = (b.GetPosition() - a.GetPosition()).GetNormalized();
    std::vector<Vec3> simplex;
	simplex.push_back(support(a, b, direction));

    direction = -simplex[0];

    while (true)
    {
        Vec3 A = support(a, b, direction);
        if (Maths::Vectors::DotProduct(A, direction) < 0)
        {
            return false;
        }
        simplex.push_back(A);
        if (simplexContainsOrigin(simplex, direction))
        {
            return true;
        }
    }
}