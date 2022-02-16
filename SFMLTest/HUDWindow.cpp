#include "pch.h"
#include "HUDWindow.h"
#include <iostream>
using namespace TD;
void HUDWindow::Clear()
{
	for (int x = 0; x < Buttons.size(); x++)
	{
		delete Buttons[x];
	}

	Buttons.clear();
}