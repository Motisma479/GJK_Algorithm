#pragma once
#include <vector>
#include "Core/Maths/Maths.hpp"
#include "Core/Maths/MathsStream.hpp"

namespace Resources
{
	class Shapes
	{
	private:
		Maths::Vec3 _position;
	public:
		bool collision;
		Shapes();
		Shapes(float x, float y, float z);
		Shapes(float x, float y, float z, Maths::Vec3* pointsList, int numberOfPoints);
		std::vector<Maths::Vec3> points;

		Maths::Vec3 GetPosition();

		Maths::Vec3 GetfurthestPoint(const Maths::Vec3& direction);

		void ChangePosition(float x, float y, float z);
		void ChangePosition(Maths::Vec3 newPos);
		void DrawInformation(int offsetX, int offsetY);
		void Draw();
	};
}