#include "stdafx.h"  //________________________________________ MyShine.cpp
#include "MyShine.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE , LPTSTR cmdLine, int cmdShow){
	MyShine app;
	return app.BeginDialog(IDI_MyShine, hInstance);
}

void MyShine::Window_Open(Win::Event& e)
{
}

