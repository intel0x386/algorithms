#include<stdlib.h>
#include<stdio.h>
#include"../utility/term.h"
#include"../utility/color.h"

void insertion_sort(int a[], int n);

int main()
{
	int i[] = {16, 94, 61, 10, 36, 42, 53, 99, 89, 63, 89, 9, 63, 22, 15, 17, 75, 13, 65, 52};
	printf("Input : "), display(i, 20);
	insertion_sort(i, 20);
	printf("Output: "), display(i, 20);
}

void insertion_sort(int a[], int n)
{
	int d, j, i, val;
	for (i = 1; i < n; i++)
	{

		printf("Iteration %d\n", i);
		for (d = 0; d < n; d++)
		{
			if (d < i)
				printf("%s  ", colorF(str(a[d]), GREEN));
			else if (d == i)
				printf("%s  ", colorF(str(a[d]), BRED));
				//printf("%s  ", colorFB(str(a[d]), BYELLOW, BLUE));
			else
				printf("%s  ", colorF(str(a[d]), BLACK));
				//printf("%s  ", colorFB(str(a[d]), BLACK, BWHITE));
		}
		printf("\n");

		val = a[i];
		for (j = i-1; j >= 0; j--)
		{
			if (val > a[j])
				break;
			a[j+1] = a[j];
		}
		a[j+1] = val;
	}
}
