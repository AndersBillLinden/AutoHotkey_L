#include "stdafx.h"
#include "last_error_exception.h"

last_error_exception::last_error_exception()
{
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, GetLastError(), NULL, (LPTSTR)&message, 0, NULL);
}

last_error_exception::~last_error_exception()
{
	//LocalFree((HLOCAL)message);
}
