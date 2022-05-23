#include "pch.h"
#include "Color.h"

DLLEXP void RandomTextColour(HDC CurrentDC)
{
	srand(time(0));
	SetTextColor(CurrentDC,
		RGB(rand() % 255,
			rand() % 255,
			rand() % 255
		));
}