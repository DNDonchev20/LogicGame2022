#include "CppUnitTest.h"
#include "../LogicTenacity/Backend/LogicTenacity-Functions.cpp"
#include "../LogicTenacity/Backend/LogicTenacity-Functions.h"

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
			
			TEST_METHOD(TestcheckNotCardpOneFunctionOne)
			{
				bool expected;
				bool result;

				result = checkNotCardpOne(4, 5, 3);
				expected = false;

				Assert::AreEqual(result, expected, L"Expected false!");
			}

				TEST_METHOD(TestcheckNotCardpOneFunctionTwo)
			{
				bool expected;
				bool result;

				result = checkNotCardpOne(1, 2, 3);
				expected = false;

				Assert::AreEqual(result, expected, L"Expected false!");
			}

				TEST_METHOD(TestcheckNotCardpOneFunctionThree)
				{
					bool expected;
					bool result;

					result = checkNotCardpOne(5, 5, 6);
					expected = false;

					Assert::AreEqual(result, expected, L"Expected false!");
				}

	};
}
