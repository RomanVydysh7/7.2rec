#include "pch.h"
#include "CppUnitTest.h"
#include "../АП_КН-2327Б_Видиш_ЛР-07.2/АП_КН-2327Б_Видиш_ЛР-07.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int n = 3;
            const int Low = 1;
            const int High = 10;

            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];

            CreateRecursive(a, n, Low, High,0,0);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);
            for (int i = 0; i < n; i++)
                delete[] a[i];
            delete[] a;
		}
	};
}
