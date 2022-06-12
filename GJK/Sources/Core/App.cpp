#include "Core/App.hpp"
#include "Resources/Shapes.hpp"

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

Resources::Shapes shapeI;
Maths::sVector::Vector3 shapeIIPoints[4] =
{
	Maths::sVector::Vector3(-0.5, -0.5, 0) * 100,
	Maths::sVector::Vector3(-0.5,  0.5, 0) * 100,
	Maths::sVector::Vector3( 0.5,  0.5, 0) * 100,
	Maths::sVector::Vector3( 0.5, -0.5, 0) * 100
};
Resources::Shapes shapeII(10, 10, shapeIIPoints,4);

void App::update()
{
	BeginDrawing();

		shapeII.ChangePosition(GetMousePosition().x, GetMousePosition().y);

		ClearBackground(RAYWHITE);

		DrawFPS(10, 10);
		shapeI.DrawInformation(10, 30);
		shapeII.DrawInformation(10, 50);

		DrawLineEx({ (float)_width / 2, 0 }, { (float)_width / 2, (float)_heigth }, 2.f, LIGHTGRAY);
		DrawLineEx({ 0, (float)_heigth / 2 }, { (float)_width, (float)_heigth / 2 }, 2.f, LIGHTGRAY);

		shapeII.Draw();
		
		//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

	EndDrawing();
}