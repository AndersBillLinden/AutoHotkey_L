#include "stdafx.h"
#include "reg_permissions_string_parser.h"
#include "string_splitter.h"
#include "lookup_account_name.h"
#include <Shlwapi.h>
#include <string.h>
#include "last_error_exception.h"

LPTSTR strtrim(LPTSTR input);

reg_permissions_string_parser::reg_permissions_string_parser(LPTSTR str, ilookup_account_name& lookup)
{
	string_splitter splitter(str, ';');

	for (LPTSTR *ptr = splitter.strings; *ptr != NULL; ptr++)
	{
		string_splitter splitter2(*ptr, '=');

		LPTSTR account_name = strtrim(splitter2.strings[0]);
		LPTSTR flags = strtrim(splitter2.strings[1]);

		PSID psid = lookup.lookup(account_name);

		result.push_back(reg_permissions_string_parse_result(account_name, psid, flags));
	}	
}

LPTSTR strtrim(LPTSTR input)
{
	int length = lstrlen(input);

	LPTSTR result = input;
	for (int i = 0; i < length; i++, result++)
		if (*result != ' ')
			break;

	for (int i = length - 1; i >= 0 && input[i] == ' '; i--)
		input[i] = '\0';

	return result;
}
