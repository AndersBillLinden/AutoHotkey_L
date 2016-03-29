#include <Windows.h>
#include <list>
#include "reg_permissions_string_parser.h"

class security_descriptor_builder
{
public:
	security_descriptor_builder(list<reg_permissions_string_parse_result>& list);
	~security_descriptor_builder();
	SECURITY_DESCRIPTOR sd;
private:
	PACL dacl;
};