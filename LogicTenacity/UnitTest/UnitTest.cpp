#include "pch.h"
#include "CppUnitTest.h"
#include "../LogicTenacity/LogicTenacity-Functions.h"
#include "../LogicTenacity/LogicTenacity-Functions.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{
	TEST_CLASS(UnitTesting)
	{
	public:
		
		TEST_METHOD(TestCheckFunction)
		{
			bool expected;
			bool result;

			result = check(2, 0, 1);
			expected = false;
		}

	};
}
