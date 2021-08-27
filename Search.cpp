#include "Search.h"

int Search::FindElementPositionWithBinarySearch(std::vector<int> Vector, int Key)
{
	int L = 0;
	int H = 0;
	int Val = Vector[0];

	while (Val < Key)
	{
		L = H;
		H *= 2;
		Val = Vector[H];
	}

	return BinarySearch(Vector, L, H, Key);
}

int Search::BinarySearch(std::vector<int> Vector, int L, int R, int Key)
{
	if (R >= 1)
	{
		int Mid = L + (R - L) / 2;
		if (Vector[Mid] == Key)
		{
			return Mid;
		}
		else if (Vector[Mid] > Key)
		{
			return BinarySearch(Vector, L, Mid - 1, Key);
		}
		else
		{
			return BinarySearch(Vector, Mid + 1, R, Key);
		}
	}
	return -1;
}
