#include "Core/App.hpp"
#include <crtdbg.h>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(156); //used to break on allocation
	
    App newApp("GJK_Collider", 800, 450);

    newApp.Update();
   
	return 0;
}