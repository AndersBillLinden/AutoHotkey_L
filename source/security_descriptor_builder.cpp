#include <Windows.h>
#include "last_error_exception.h"
#include "reg_permissions_string_parser.h"
#include "lookup_account_name.h"
#include "security_description_builder.h"

security_descriptor_builder::security_descriptor_builder(list<reg_permissions_string_parse_result>& input)
{
	int sids_size = 0;
	int num = 0;

	for (list<reg_permissions_string_parse_result>::iterator i = input.begin();
		i != input.end(); i++)
	{
		reg_permissions_string_parse_result& parse_result = *i;
		num++;
		sids_size += GetLengthSid(parse_result.psid);
	}

	DWORD dwDaclSize =
		sizeof(ACL)
		+ 2 * (num * sizeof(ACCESS_ALLOWED_ACE) - sizeof(DWORD))
		+ sids_size;

	dacl = PACL(malloc(dwDaclSize));

	if (!InitializeAcl(dacl, dwDaclSize, ACL_REVISION)) {
		throw last_error_exception();
	}

	for (list<reg_permissions_string_parse_result>::iterator i = input.begin();
		i != input.end(); i++)
	{
		reg_permissions_string_parse_result parse_result = *i;

		if (!AddAccessAllowedAce(dacl, ACL_REVISION, KEY_READ, i->psid)) {
			throw last_error_exception();
		}
	}

	if (!InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION)) {
		throw last_error_exception();
	}

	if (!SetSecurityDescriptorDacl(&sd, TRUE, dacl, FALSE)) {
		throw last_error_exception();
	}
}

security_descriptor_builder::~security_descriptor_builder()
{
	free(dacl);
}