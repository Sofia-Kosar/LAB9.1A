#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB9.1A/LAB9.1A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91A
{
	TEST_CLASS(UnitTest91A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int N = 3;
			Student students[N] = {
				{ "Student1", 1, PHYSICS, 5, 5, 0 },
				{ "Student2", 2, MATH, 5, 5, 0 },
				{ "Student3", 3, PHYSICS, 5, 5, 0 }
			};

			double result = CalculatePercentGoodPhysicsMath(students, N);
            Assert::AreEqual(100.0, result);
		}
	};
}
