#include "Physics/GJK.hpp"

#include "raylib.hpp"

Maths::sVector::Vector3 support(Resources::Shapes& a, Resources::Shapes& b, Maths::sVector::Vector3& direction)
{
	Maths::sVector::Vector3 tmp = -direction;
	return a.GetfurthestPoint(direction) - b.GetfurthestPoint(tmp);
}

bool Physics::TestCollision(Resources::Shapes& a, Resources::Shapes& b)
{
	Maths::sVector::Vector3 direction = Maths::sVector::Vector3::Normalize(Maths::sVector::Vector3(b.GetPosition() - a.GetPosition()));
	std::vector<Maths::sVector::Vector3> simplex;
	simplex.push_back(support(a, b, direction));

	DrawCircle((int)simplex[0].x + 400, (int)simplex[0].y + 225, 2, ORANGE);

	return true;
}