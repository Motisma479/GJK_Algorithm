#include "Core/App.hpp"

#include <iostream>
#include <raylib.hpp>

#include "Physics/GJK.hpp"

// ---- CONSTRUCTOR ----------------------------------------

App::App()
{
	Init("GJK_Collider", 800, 450);
}

App::App(const char* _name, int _width, int _height)
{
	Init(_name, _width, _height);
}

// ---- DESTRUCTOR -----------------------------------------

App::~App()
{
	Destroy();
}

// ---------------------------------------------------------


Maths::sVector::Vector3 SQUARE[4] =
{
	Maths::sVector::Vector3(-0.5, -0.5, 0) * 100,
	Maths::sVector::Vector3(-0.5,  0.5, 0) * 100,
	Maths::sVector::Vector3(0.5,  0.5, 0) * 100,
	Maths::sVector::Vector3(0.5, -0.5, 0) * 100
};

Resources::Shapes shapeI(0, 0, SQUARE, 4);
Resources::Shapes shapeII(0, 0, SQUARE,4);

void App::Update()
{
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		shapeI.ChangePosition(width_ / 2 + 100, heigth_ / 2 - 100);
		shapeII.ChangePosition(GetMousePosition().x, GetMousePosition().y);

		StartFrame();

		DrawLineEx({ (float)width_ / 2, 0 }, { (float)width_ / 2, (float)heigth_ }, 2.f, LIGHTGRAY);
		DrawLineEx({ 0, (float)heigth_ / 2 }, { (float)width_, (float)heigth_ / 2 }, 2.f, LIGHTGRAY);

		DrawFPS(10, 10);
		shapeI.DrawInformation(10, 30);
		shapeII.DrawInformation(10, 50);

		shapeI.Draw();
		shapeII.Draw();

		Physics::TestCollision(shapeII, shapeI);
		//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		EndFrame();
	}
}

void App::Init(const char* _name, int _width, int _height)
{
	width_ = _width;
	heigth_ = _height;

	InitWindow(_width, _height, _name);
	SetTargetFPS(60);
}

void App::Destroy()
{
	CloseWindow();
}

void App::StartFrame()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
}

void App::EndFrame()
{
	EndDrawing();
}