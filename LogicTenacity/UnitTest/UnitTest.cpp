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

			Assert::AreEqual(result, expected, L"Expected false!");
		}

		TEST_METHOD(TestCheckFunctionTwo)
		{
			bool expected;
			bool result;

			result = check(3, 3, 4);
			expected = false;

			Assert::AreEqual(result, expected, L"Expected false!");
		}

		TEST_METHOD(TestCheckFunctionThree)
		{
			bool expected;
			bool result;

			result = check(4, 1, 2);
			expected = false;

			Assert::AreEqual(result, expected, L"Expected false!");
		}

		TEST_METHOD(TestCheckFunctionFour)
		{
			bool expected;
			bool result;

			result = check(2, 1, 0);
			expected = false;

			Assert::AreEqual(result, expected, L"Expected false!");
		}
		
			TEST_METHOD(TestaddCardFunctionOne)
		{
			bool expected;
			bool result;

			result = addCard(1, 2);
			expected = false;

			Assert::AreEqual(result, expected, L"Expected false!");
		}

			TEST_METHOD(TestaddCardFunctionTwo)
			{
				bool expected;
				bool result;

				result = addCard(3, 4);
				expected = false;

				Assert::AreEqual(result, expected, L"Expected false!");
			}

			TEST_METHOD(TestaddCardFunctionThree)
			{
				bool expected;
				bool result;

				result = addCard(5, 8);
				expected = false;

				Assert::AreEqual(result, expected, L"Expected false!");
			}

			TEST_METHOD(TestaddCardFunctionFour)
			{
				bool expected;
				bool result;

				result = addCard(2, 3);
				expected = false;

				Assert::AreEqual(result, expected, L"Expected false!");
			}
			

	};
}
