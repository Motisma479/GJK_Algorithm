#include "Resources/Shapes.hpp"

#include "raylib.hpp"
#include <string>

Resources::Shapes::Shapes(): _position(0, 0), collision(false)
{

}
Resources::Shapes::Shapes(float x, float y): _position(x, y), collision(false)
{

}
Resources::Shapes::Shapes(float x, float y, Maths::sVector::Vector3* pointsList, int numberOfPoints) : _position(x, y), collision(false)
{
	for (int i = 0; i < numberOfPoints; i++)
	{
		points.emplace_back(pointsList[i]);
	}
}
Maths::sVector::Vector2 Resources::Shapes::GetPosition()
{
	return _position;
}
void Resources::Shapes::ChangePosition(float x, float y)
{
	_position = { x, y };
}
void Resources::Shapes::ChangePosition(Maths::sVector::Vector2 newPos)
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