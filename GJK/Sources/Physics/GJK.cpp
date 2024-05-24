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

    if (simplex.size() == 3) {
        Vec3 B = simplex[1];
        Vec3 C = simplex[0];

        Vec3 AB = B - A;
        Vec3 AC = C - A;

        Vec3 ABperp = AB.GetPerpendicular();
        Vec3 ACperp = AC.GetPerpendicular();

        if (Maths::Vectors::DotProduct(ABperp,AO) > 0) {
            simplex = { A, B };
            direction = ABperp;
        }
        else if (Maths::Vectors::DotProduct(ACperp,AO) > 0) {
            simplex = { A, C };
            direction = ACperp;
        }
        else {
            return true;  // Origin is within the triangle
        }
    }
    else {
        Vec3 B = simplex[0];
        Vec3 AB = B - A;
        direction = AB.GetPerpendicular();
        if (Maths::Vectors::DotProduct(direction,AO) < 0) {
            direction = -direction;
        }
    }

    return false;
}

Vec3 calculateDirection(const std::vector<Maths::Vec3>& simplex) {
    Vec3 A = simplex.back();
    Vec3 AO = -A;

    if (simplex.size() == 3) {
        Vec3 B = simplex[1];
        Vec3 C = simplex[0];

        Vec3 AB = B - A;
        Vec3 AC = C - A;

        Vec3 ABperp = AB.GetPerpendicular();
        Vec3 ACperp = AC.GetPerpendicular();

        if (Maths::Vectors::DotProduct(ABperp,AO) > 0) {
            return AB.GetPerpendicular();
        }
        else if (Maths::Vectors::DotProduct(ACperp,AO) > 0) {
            return AC.GetPerpendicular();
        }
    }
    else if (simplex.size() == 2) {
        Vec3 B = simplex[0];
        Vec3 AB = B - A;
        return AB.GetPerpendicular();
    }

    return { 1, 0,0 };  // Default direction
}

bool Physics::TestCollision(Resources::Shapes& a, Resources::Shapes& b)
{
    Vec3 direction{1,0,0};
	std::vector<Vec3> simplex;
	//simplex.push_back(support(a, b, direction));

	bool result = false;

	//direction = -simplex[0];

    //simplex.push_back(support(a, b, direction));


	//while (true)
	//{
 //       Vec3 newPoint = support(a, b, direction);
	//	simplex.push_back(newPoint);

	//	if (Maths::Vectors::DotProduct(newPoint, direction) <= 0)
	//		break;


 //       if (simplexContainsOrigin(simplex, direction)) {
 //           result = true;  // Intersection
 //           break;
 //       }

 //       direction = calculateDirection(simplex);
	//}

    Vec3 pos = (a.GetPosition() - b.GetPosition());
    for (const auto& p : a.points)
    {
        for (const auto& q : b.points)
        {
            simplex.push_back(p - q + pos);
        }

    }

    for (int i = 0; i < simplex.size(); i++)
    {

		DrawCircle((int)simplex[i].x + 400, (int)simplex[i].y + 225, 2, ORANGE);
        if (i + 1 == simplex.size())
            DrawLine(simplex[i].x + 400 , simplex[i].y + 225 , simplex[0].x + 400, simplex[0].y + 225, RED);
        else
            DrawLine(simplex[i].x + 400, simplex[i].y + 225 , simplex[i + 1].x + 400, simplex[i + 1].y + 225, RED);
    }

    std::vector<Vec3> s;

    Vec3 f1 = support(a, b, direction);
    s.push_back(f1);

    Vec3 dir = -f1;
    
    
        Vec3 ft = support(a, b, dir);

        /*if (Maths::Vectors::DotProduct(ft,direction) <= 0)
        {
            std::cout << "ERROR\n";
        }*/

        s.push_back(ft);

        //if (simplexContainsOrigin(simplex, direction))
        //{
        //    std::cout << "simplex Contains Origin\n";
        //    break;  // Intersection
        //}

        /*if (Maths::Vectors::DotProduct(direction,-ft) < 0)
        {
            std::cout << "ERROR2\n";
        }*/

        if (ft.y < 0 || f1.y < 0)
        {
            dir = -ft.GetPerpendicular();
        }
        else {

            dir = ft.GetPerpendicular();
        }
    
        ft = support(a, b, dir);
        s.push_back(ft);


        if (simplexContainsOrigin(s, ft))
        {
            std::cout << "COLISION\n";
        }

    for (int i = 0; i < s.size(); i++)
    {
        DrawCircle((int)s[i].x + 400, (int)s[i].y + 225, 2, GREEN);
        if (i + 1 == s.size())
            DrawLine(s[i].x + 400, s[i].y + 225, s[0].x + 400, s[0].y + 225, DARKGREEN);
        else
            DrawLine(s[i].x + 400, s[i].y + 225, s[i + 1].x + 400, s[i + 1].y + 225, DARKGREEN);

    }




	return result;
}