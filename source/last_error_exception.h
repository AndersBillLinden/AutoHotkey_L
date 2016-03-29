#pragma once
#include "../Source/stdafx.h"
#include <Windows.h>

class last_error_exception
{
public:
	last_error_exception();
	~last_error_exception();
	LPCTSTR message;
};
