// pch.cpp: source file corresponding to the pre-compiled header

#include "pch.h"

// When you are using pre-compiled headers, this source file is necessary for compilation to succeed.
DLLEXP wchar_t ChangeCase(int letter)
{
	//lower 97-122
	//upper 65-90
	if (letter >= 65 || letter <= 90)
	{
		letter += 32;
	}
	else
		letter -= 32;
	
	return letter;
}