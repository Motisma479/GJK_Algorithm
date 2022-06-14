#include "Core/App.hpp"
#include "Resources/Shapes.hpp"
#include "Physics/GJK.hpp"
App::App(): _width(800), _heigth(450)
{
	InitWindow(_width, _heigth, "GJK_Collider");

	SetTargetFPS(60);
}
App::App(const char* name, int width, int height): _width(width), _heigth(height)
{
	InitWindow(_width, _heigth, name);

	SetTargetFPS(60);
}
App::~App()
{
	CloseWindow();
}

Maths::sVector::Vector3 SQUARE[4] =
{
	Maths::sVector::Vector3(-0.5, -0.5, 0) * 100,
	Maths::sVector::Vector3(-0.5,  0.5, 0) * 100,
	Maths::sVector::Vector3(0.5,  0.5, 0) * 100,
	Maths::sVector::Vector3(0.5, -0.5, 0) * 100
};

Resources::Shapes shapeI(0, 0, SQUARE, 4);
Resources::Shapes shapeII(0, 0, SQUARE,4);

void App::update()
{
	shapeI.ChangePosition(_width/2 +100, _heigth/2 -100);
	shapeII.ChangePosition(GetMousePosition().x, GetMousePosition().y);

	BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawLineEx({ (float)_width / 2, 0 }, { (float)_width / 2, (float)_heigth }, 2.f, LIGHTGRAY);
		DrawLineEx({ 0, (float)_heigth / 2 }, { (float)_width, (float)_heigth / 2 }, 2.f, LIGHTGRAY);

		DrawFPS(10, 10);
		shapeI.DrawInformation(10, 30);
		shapeII.DrawInformation(10, 50);

		shapeI.Draw();
		shapeII.Draw();
		
		Physics::TestCollision(shapeII, shapeI);
		//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

	EndDrawing();
}