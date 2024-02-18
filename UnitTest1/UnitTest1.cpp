#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_1/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestCreate)
		{
			const int rowCount = 7;
			const int colCount = 9;
			int** z = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i)
				z[i] = new int[colCount];

			Create(z, rowCount, colCount, -10, 10);

			for (int i = 0; i < rowCount; ++i)
				for (int j = 0; j < colCount; ++j)
					Assert::IsTrue(z[i][j] >= -10 && z[i][j] <= 10);

			for (int i = 0; i < rowCount; ++i)
				delete[] z[i];
			delete[] z;
		}

		TEST_METHOD(TestSort)
		{
			const int rowCount = 7;
			const int colCount = 9;
			int** z = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i)
				z[i] = new int[colCount];

			int testArray[rowCount][colCount] = {
				{5, 3, 4, 2, 1, 6, 8, 7, 9},
				{1, 2, 3, 4, 5, 6, 7, 8, 9},
				{9, 8, 7, 6, 5, 4, 3, 2, 1},
				{4, 3, 6, 5, 1, 2, 7, 9, 8},
				{1, 2, 3, 4, 5, 6, 7, 8, 9},
				{9, 8, 7, 6, 5, 4, 3, 2, 1},
				{5, 3, 4, 2, 1, 6, 9, 7, 8}
			};

			for (int i = 0; i < rowCount; ++i)
				for (int j = 0; j < colCount; ++j)
					z[i][j] = testArray[i][j];

			Sort(z, rowCount, colCount);

			for (int j = 0; j < colCount - 1; ++j)
				Assert::IsTrue(z[0][j] <= z[0][j + 1]);

			for (int i = 0; i < rowCount; ++i)
				delete[] z[i];
			delete[] z;
		}


		TEST_METHOD(TestCalc)
		{
			const int rowCount = 7;
			const int colCount = 9;
			int** R = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i)
				R[i] = new int[colCount];

			int testArray[rowCount][colCount] = {
				{1, 2, 3, 4, 5, 6, 7, 8, 9},
				{-1, -2, -3, -4, -5, -6, -7, -8, -9},
				{0, 0, 0, 0, 0, 0, 0, 0, 0},
				{1, -1, 2, -2, 3, -3, 4, -4, 5},
				{2, 4, 6, 8, 10, 12, 14, 16, 18},
				{-2, -4, -6, -8, -10, -12, -14, -16, -18},
				{1, 3, 5, 7, 9, 11, 13, 15, 17}
			};

			for (int i = 0; i < rowCount; ++i)
				for (int j = 0; j < colCount; ++j)
					R[i][j] = testArray[i][j];

			int S, k;
			Calc(R, rowCount, colCount, S, k);

			Assert::AreEqual(S, 143);
			Assert::AreEqual(k, 47);

			for (int i = 0; i < rowCount; ++i)
				delete[] R[i];
			delete[] R;
		}
	};
}
