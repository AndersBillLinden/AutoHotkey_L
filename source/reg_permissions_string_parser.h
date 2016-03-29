#pragma once
#include "../Source/stdafx.h"
#include <Windows.h>
#include <list>
#include "lookup_account_name.h"

using namespace std;

class reg_permissions_string_parse_result
{
public:
	reg_permissions_string_parse_result(LPTSTR account_name, PSID psid, LPTSTR flags)
	{
		this->account_name = account_name;
		this->psid = psid;
		this->flags = flags;
	}

	LPTSTR account_name;
	PSID psid;
	LPTSTR flags;
};

class reg_permissions_string_parser
{
public:
	reg_permissions_string_parser(LPTSTR str, ilookup_account_name& lookup);
	list<reg_permissions_string_parse_result> result;
	//PACL dacl;
};
