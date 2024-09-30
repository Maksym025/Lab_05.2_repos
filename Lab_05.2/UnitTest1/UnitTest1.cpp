#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05.2/Lab_05.21.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			double x = 0.5;
			double eps = 0.000001;
			int n = 0;
			double s = 0;
			S(x, eps, n, s);
			double expected = PI / 2 - atan(x);

		
			Assert::AreEqual(s, expected, 0.0001);
		}
	};
}
