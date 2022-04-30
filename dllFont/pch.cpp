// pch.cpp: source file corresponding to the pre-compiled header

#include "pch.h"

// When you are using pre-compiled headers, this source file is necessary for compilation to succeed.
DLLEXP void ChangeCase(std::wstring & str)
{
	//lower 97-122
	//upper 65-90
	if (str.empty())
	{
		return;
	}
	size_t lastLetter = str.size()-1;
	if (iswlower((wint_t)str[lastLetter]))
	{
		str[lastLetter] = towupper(str[lastLetter]);
	}
	else 
		str[lastLetter] = towlower(str[lastLetter]);
}