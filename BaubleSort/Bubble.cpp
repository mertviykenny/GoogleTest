// BaubleSort.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include<iostream>
using namespace std;
#include<conio.h>

void output(int input[], int size)
{
	for (int i = 0; i < size; i++)
		cout << input[i];
}
int * BubbleSort(int *input,int size)
{
	if (size < 0)
		throw invalid_argument("size should be >=0");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (input[i] < input[j])
			{
				swap(input[i], input[j]);
			}
		}
	}
	return input;
}



