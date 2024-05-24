#include "Resources/Shapes.hpp"

#include "raylib.hpp"
#include <string>

Resources::Shapes::Shapes(): _position(0, 0, 0), collision(false)
{

}
Resources::Shapes::Shapes(float x, float y, float z) : _position(x, y, z), collision(false)
{

}
Resources::Shapes::Shapes(float x, float y, float z, Maths::Vec3* pointsList, int numberOfPoints) : _position(x, y, z), collision(false)
{
	for (int i = 0; i < numberOfPoints; i++)
	{
		points.emplace_back(pointsList[i]);
	}
}
Maths::Vec3 Resources::Shapes::GetPosition()
{
	return _position;
}
Maths::Vec3 Resources::Shapes::GetfurthestPoint(const Maths::Vec3& direction)
{
	//float temp = Maths::sVector::Vector3::DotProduct(Maths::sVector::Vector3::Normalize(points[0] - _position), direction);
	//int indexOfPoint = 0;
	Maths::Vec3 maxPoint;
	float maxDistance = -FLT_MAX;

	for (Maths::Vec3& point : points)
	{
		float distance = Maths::Vectors::DotProduct(point, direction);
		if (distance > maxDistance)
		{
			maxDistance = distance;
			maxPoint = point;
		}
	}
	return maxPoint;
}
void Resources::Shapes::ChangePosition(float x, float y, float z)
{
	_position = Maths::Vec3( x, y, z );
}
void Resources::Shapes::ChangePosition(Maths::Vec3 newPos)
{
	_position = newPos;
}
void Resources::Shapes::DrawInformation(int offsetX, int offsetY)
{
	std::string temp = "Position: " + std::to_string(_position.x) + ", " + std::to_string(_position.y) + ", " + std::to_string(points.size());
	DrawText(temp.c_str(), offsetX, offsetY, 20, RED);
}
void Resources::Shapes::Draw()
{
	for (int i = 0; i < points.size(); i++)
	{
		Color tempColor;
		if (collision)
			tempColor = RED;
		else
			tempColor = DARKGRAY;

		DrawCircle(_position.x + points[i].x, _position.y + points[i].y, 2, tempColor);
		if(i+1 == points.size())
			DrawLine(_position.x + points[i].x, _position.y + points[i].y, _position.x + points[0].x, _position.y + points[0].y, tempColor);
		else
			DrawLine(_position.x + points[i].x, _position.y + points[i].y, _position.x + points[i + 1].x, _position.y + points[i + 1].y, tempColor);
	}
}