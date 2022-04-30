// pch.cpp: source file corresponding to the pre-compiled header

#include "pch.h"


// When you are using pre-compiled headers, this source file is necessary for compilation to succeed.
DLLEXP void RandomTextColour(HDC CurrentDC)
{
	srand(time(0));
	SetTextColor(CurrentDC,
		RGB( rand()%255,
			 rand()%255,
			 rand()%255
		));
}