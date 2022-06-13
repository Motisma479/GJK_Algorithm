#include "Physics/GJK.hpp"

bool Physics::TestCollision(Resources::Shapes& a, Resources::Shapes& b)
{
	Maths::sVector::Vector3 d = Maths::sVector::Vector3::Normalize(Maths::sVector::Vector3(b.GetPosition() - a.GetPosition()));

}