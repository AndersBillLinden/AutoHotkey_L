#include "../Source/stdafx.h"
#include "CppUnitTest.h"
#include "../Source/string_splitter.h"
#include <shlwapi.h>

#pragma comment(lib, "shlwapi.lib")

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AutoHotkeyxTest
{		
	TEST_CLASS(string_splitter_test)
	{
	public:
		TEST_METHOD(TestSimpleSplitting)
		{
			string_splitter s = string_splitter(StrDup(L"bara"), 'r');

			Assert::AreEqual(L"ba", s.strings[0]);
			Assert::AreEqual(L"a", s.strings[1]);
			Assert::AreEqual(NULL, s.strings[2]);
		}

		TEST_METHOD(TestSplitEmptyString)
		{
			string_splitter s = string_splitter(L"", 'r');

			Assert::AreEqual(NULL, s.strings[0]);
		}

		TEST_METHOD(TestNoHitSplitting)
		{
			string_splitter s = string_splitter(L"bara", 'x');

			Assert::AreEqual(L"bara", s.strings[0]);
			Assert::AreEqual(NULL, s.strings[1]);
		}
	};
}
