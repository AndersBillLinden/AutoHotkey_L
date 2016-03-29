#include "../Source/stdafx.h"
#include "CppUnitTest.h"
#include "../Source/reg_permissions_string_parser.h"
#include "fake_lookup_account_name.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AutoHotkeyxTest
{
	TEST_CLASS(reg_permissions_string_parser_test)
	{
	public:
		TEST_METHOD(TestSimpleSplitting)
		{
			TCHAR str[100] = { L"pelle=RWS;nisse=R" };
			
			SID s1; s1.Revision = 1;
			SID s2; s2.Revision = 2;

			fake_lookup_account_name_entry entries[] =
			{
				{ L"pelle",	&s1	},
				{	L"nisse",	&s2	}
			};

			fake_lookup_account_name lookup(entries, 3);

			reg_permissions_string_parser parser(str, (ilookup_account_name &)lookup);

			Assert::AreEqual(2, (int)parser.result.size());

			Assert::AreEqual(L"pelle", parser.result.front().account_name);
			Assert::AreEqual(L"RWS", parser.result.front().flags);
			Assert::AreEqual((BYTE)1, ((SID *)(parser.result.front().psid))->Revision);

			Assert::AreEqual(L"nisse", parser.result.back().account_name);
			Assert::AreEqual(L"R", parser.result.back().flags);
			Assert::AreEqual((BYTE)2, ((SID *)(parser.result.front().psid))->Revision);
		}

		TEST_METHOD(TestTrimming)
		{
			TCHAR str[100] = { L"pelle =   RWS;nisse=R" };
			fake_lookup_account_name lookup();
			reg_permissions_string_parser parser(str, (ilookup_account_name &)lookup);
			Assert::AreEqual(2, (int)parser.result.size());
			Assert::AreEqual(L"pelle", parser.result.front().account_name);
			Assert::AreEqual(L"RWS", parser.result.front().flags);
		}
	};
}
