#pragma once
#include "../Source/stdafx.h"
#include <Windows.h>

class string_splitter
{
public:
	LPTSTR *strings;
	string_splitter(LPTSTR input, TCHAR delimiter);
	~string_splitter();
	int num_strings();
private:
	void allocate(LPCTSTR input, TCHAR delimiter);
	void split(LPTSTR input, TCHAR delimiter);
};
