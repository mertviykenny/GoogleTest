#include "pch.h"
#include "../BaubleSort/Bubble.h"
TEST(BubbleSort, correctTest) {
	int input[] = { 1,4,3,5,2,6 };
	int size = 6;
	BubbleSort(input, size);
	int res[] = { 1,2,3,4,5,6 };
	for (int i = 0; i < size; i++)
	{
		EXPECT_EQ(input[i], res[i]);
	}
}

TEST(BubbleSort, smallerSizeTest) {
	int input[] = { 1,4,3,5,2,6,7,8 };
	int size = 6;
	BubbleSort(input, size);
	int res[] = { 1,2,3,4,5,6};
	for (int i = 0; i < size; i++)
	{
		EXPECT_EQ(input[i], res[i]);
	}
	EXPECT_EQ(input[6], 7);
	EXPECT_EQ(input[7], 8);
}

TEST(BubbleSort, EmptyArrayTest) {
	int *input = {};
	int size = 0;
	BubbleSort(input, size);
	int *res = {};
	EXPECT_EQ(input, res);
}

TEST(BubbleSort, SameMemoryAddressTest) {
	int input []= {1,2,3};
	int size = 3;
	int *res = BubbleSort(input, size);
	ASSERT_EQ(res, input);
}

TEST(BubbleSort, PerformanceTest) {
	int *input;
	input= new int[10000];
	int size = 10000;
	for (int i = 0; i < 10000; i++)
	{
		input[i] = rand()%(size/4);
	}
	clock_t t0 = clock();
	int *res = BubbleSort(input, size);
	clock_t t1 = clock();
	double elapsedSec = (t1 - t0) / (double)CLOCKS_PER_SEC;
	EXPECT_GT(1.0, elapsedSec);
}

TEST(BubbleSort, SizeInvalidArgumentExceptionTest) {
	int input[] = { 1,2,3,4 };
	int size = -1;
	try {
		BubbleSort(input, size);
	}
	catch (invalid_argument e)
	{
		EXPECT_EQ(e.what(), string("size should be >=0"));
	}
}
