#include "reg_permissions_string_parser.h"
#include <Shlwapi.h>
#include <string.h>

reg_permissions_string_parser::reg_permissions_string_parser(LPTSTR str)
{
	this->str = StrDup(str);

	LPTSTR ptr = StrChr(str, ',');
}


list<reg_permissions_string_parse_result> reg_permissions_string_parser::get_result()
{	
	return result;
}
