#include "../Source/stdafx.h"
#include "fake_lookup_account_name.h"

fake_lookup_account_name::fake_lookup_account_name(fake_lookup_account_name_entry* entries, int num)
{
	this->entries = entries;
	this->num = num;
}

PSID fake_lookup_account_name::lookup(LPTSTR name)
{
	for (int i = 0; i < num; i++)
	{
		fake_lookup_account_name_entry& entry = entries[i];
		if (!lstrcmp(entry.name, name))
		{
			return entry.psid;
		}
	}

	return NULL;
}
