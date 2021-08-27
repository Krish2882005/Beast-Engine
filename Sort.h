#pragma once
#include <vector>

class Sort
{
	public:
		static void QuickSort(std::vector<int> &Vector, int Low, int High);
	private:
		static void Swap(int* a, int* b);
		static int Partition(std::vector<int> &Vector, int Low, int High);
};

