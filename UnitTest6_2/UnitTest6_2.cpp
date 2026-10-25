#include "pch.h"
#define UNIT_TESTING
#include "CppUnitTest.h"
#include "../Lab_6_2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62
{
    TEST_CLASS(UnitTest62)
    {
    public:
        TEST_METHOD(TestIFirstEven)
        {
            int a[] = { 3, 7, 10, -4, 5, 8 };
            Assert::AreEqual(2, IFirstEven(a, 6, 0));
        }

        TEST_METHOD(TestIFirstEvenNone)
        {
            int a[] = { 1, 3, -5 };
            Assert::AreEqual(-1, IFirstEven(a, 3, 0));
        }

        TEST_METHOD(TestMinEven)
        {
            int a[] = { 3, 7, 10, -4, 5, 8 };
            int min = a[2];
            MinEven(a, 6, 3, min);
            Assert::AreEqual(-4, min);
        }

        TEST_METHOD(TestMinEvenNegativeOdd)
        {
            int a[] = { -9, 6, -7, 2, 4 };
            int min = a[1];
            MinEven(a, 5, 2, min);
            Assert::AreEqual(2, min);
        }
    };
}