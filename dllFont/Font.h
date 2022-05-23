#pragma once
#include <Windows.h>
#include <xstring>

#define DLLEXP extern "C" __declspec(dllexport)
DLLEXP TCHAR ChangeCase(const TCHAR& letter)
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

