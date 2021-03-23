#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_2_6/Triangle.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Labtest26
{
	TEST_CLASS(Labtest26)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Triangle::Triad triad(-20.0, 12.0, 0.5);
			Assert::AreEqual(triad.Sum(), -7.5);
		}

		TEST_METHOD(TestMethod2)
		{
			Triangle T(3, 4, 5);
			Assert::AreEqual(T.Square(), 6.0);
		}
	};
}
