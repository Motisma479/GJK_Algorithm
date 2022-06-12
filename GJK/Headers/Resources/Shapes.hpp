#pragma once
#include <vector>
#include "Core/Maths/Maths.hpp"

namespace Resources
{
	class Shapes
	{
	private:
		Maths::sVector::Vector2 _position;
	public:
		Shapes();
		Shapes(float x, float y);
		Shapes(float x, float y, Maths::sVector::Vector3* pointsList, int numberOfPoints);
		std::vector<Maths::sVector::Vector3> points;
		void ChangePosition(float x, float y);
		void ChangePosition(Maths::sVector::Vector2 newPos);
		void DrawInformation(int offsetX, int offsetY);
		void Draw();
	};
}