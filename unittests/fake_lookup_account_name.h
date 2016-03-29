#pragma once
#include "../Source/stdafx.h"
#include "../Source/lookup_account_name.h"
#include <list>

using namespace std;

struct fake_lookup_account_name_entry
{
	LPCTSTR name;
	SID* psid;
};

class fake_lookup_account_name : public ilookup_account_name
{
public:
	fake_lookup_account_name(fake_lookup_account_name_entry *entries, int num);
	PSID lookup(LPTSTR name);
private:
	fake_lookup_account_name_entry* entries;
	int num;
};
