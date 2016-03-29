#include "stdafx.h"
#include "lookup_account_name.h"
#include "last_error_exception.h"

PSID lookup_account_name::lookup(LPTSTR name)
{
	TCHAR szDomain[128] = { '\0' };
	DWORD dwDomainSize = 128;
	DWORD sidSize = 32;
	PSID psid = malloc(sidSize);
	SID_NAME_USE sid_name_use;

	while (!LookupAccountName(NULL, name, psid, &sidSize, szDomain,
		&dwDomainSize, &sid_name_use) && GetLastError() == ERROR_INSUFFICIENT_BUFFER)
	{
		sidSize *= 2;
		free(psid);
		psid = malloc(sidSize);
	}

	if (GetLastError() != ERROR_SUCCESS)
	{
		throw last_error_exception();
	}

	return psid;
}
