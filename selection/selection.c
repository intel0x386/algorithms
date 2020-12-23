#include<stdio.h>
#include<stdlib.h>
#include"../utility/term.h"
#include"../utility/color.h"

void selection_sort(int *arr, int n);

int main()
{
	int i[] = {88, 56, 25, 14, 77, 6, 32, 46, 79, 46, 71, 80, 65, 56, 6, 39, 38, 26, 5, 36};
	int j[] = {88, 56, 25, 14, 77, 6, 32, 46, 79, 46, 71, 80, 65, 56, 6, 39, 38, 26, 5, 36};
	display(i, 20);
	selection_sort(i, 20);
	display(i, 20);
}

void selection_sort(int *arr, int n)
{
	int i, j, min;
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i+1; j<n; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		swap(arr+i, arr+min);
	}
}
