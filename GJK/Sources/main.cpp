#include "Core/App.hpp"
#include "iostream"

#include <crtdbg.h>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(156); //used to break on allocation
	std::cout << "Hello World" << std::endl;

    App newApp("GJK_Collider", 800, 450);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        newApp.update();
    }

	return 0;
}