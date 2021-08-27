#pragma once
#include <vector>

class Search
{
	public:
		static int FindElementPositionWithBinarySearch(std::vector<int> Vector, int Key);
	private:
		static int BinarySearch(std::vector<int> Vector, int L, int R, int Key);
};
