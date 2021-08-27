#include "Sort.h"

void Sort::Swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int Sort::Partition(std::vector<int> &Vector, int Low, int High)
{
	int Pivot = Vector[High];
	int i = (Low - 1);

	for (int j = Low; j <= High - 1; j++)
	{
		if (Vector[j] <= Pivot)
		{
			i++;
			Swap(&Vector[i], &Vector[j]);
		}
	}
	Swap(&Vector[i + 1], &Vector[High]);
	return (i + 1);
}

void Sort::QuickSort(std::vector<int>& Vector, int Low, int High)
{
	if (Low < High)
	{
		int Pi = Partition(Vector, Low, High);

		QuickSort(Vector, Low, Pi - 1);
		QuickSort(Vector, Pi + 1, High);
	}
}
