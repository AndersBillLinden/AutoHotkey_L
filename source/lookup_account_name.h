#pragma once
#include "../Source/stdafx.h"
#include <Windows.h>

class ilookup_account_name
{
public:
	virtual PSID lookup(LPTSTR name) = 0;
};

class lookup_account_name : public ilookup_account_name
{
public:
	PSID lookup(LPTSTR name);
};
