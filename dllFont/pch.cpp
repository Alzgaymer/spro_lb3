// pch.cpp: source file corresponding to the pre-compiled header

#include "pch.h"

// When you are using pre-compiled headers, this source file is necessary for compilation to succeed.
DLLEXP TCHAR ChangeCase(const TCHAR & letter)
{
	//lower 97-122
	//upper 65-90
	//size_t lastLetter = str.size()-1;
	auto c = letter;
	if (iswlower((wint_t)letter))
	{
		c = towupper(letter);
	}
	else 
		c = towlower(letter);
	return c;
}