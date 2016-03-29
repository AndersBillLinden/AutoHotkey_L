#include "stdafx.h"
#include "string_splitter.h"
#include <shlwapi.h>

int strcount(LPCTSTR input, TCHAR chr);

string_splitter::string_splitter(LPTSTR input, TCHAR delimiter)
{
	allocate(input, delimiter);
	split(input, delimiter);
}

int string_splitter::num_strings()
{
	int result = 0;

	for (LPTSTR *ptr = strings; *ptr != NULL; ptr++)
		result++;

	return result;
}

void string_splitter::allocate(LPCTSTR input, TCHAR delimiter)
{
	int num = 2 + strcount(input, delimiter);
	strings = new LPTSTR[num];
}

string_splitter::~string_splitter()
{
	free(strings);
}

void string_splitter::split(LPTSTR input, TCHAR delimiter)
{
	bool advance = true;
	int num = 0;

	for (LPTSTR ptr = input; *ptr != '\0'; ptr++)
	{
		if (advance)
		{
			strings[num++] = ptr;
			advance = false;
		}

		TCHAR c = *ptr;

		if (*ptr == delimiter)
		{
			*ptr = '\0';
			advance = true;
		}
	}

	strings[num] = NULL;
}

int strcount(LPCTSTR input, TCHAR chr)
{
	int num = 0;
	for (LPCTSTR ptr = input; *ptr; ptr++)
		if (*ptr == chr)
			num++;

	return num;
}
