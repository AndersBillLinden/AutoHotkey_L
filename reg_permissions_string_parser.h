#include <Windows.h>
#include <list>

using namespace std;

class reg_permissions_string_parse_result
{

};

class reg_permissions_string_parser
{
public:
	reg_permissions_string_parser(LPTSTR str);
	list<reg_permissions_string_parse_result> get_result();
private:
	LPTSTR str;
	list<reg_permissions_string_parse_result> result;
};
