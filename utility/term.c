#include<stdio.h>
#include<stdlib.h>
#include<termios.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/uio.h>
#include<unistd.h>

#define SUCCESS 0x0001911
#define FAILURE 0x0001912

void _getchar()
{
	struct termios term;
	struct termios backup;
	char buffer[16];

	if(tcgetattr(0, &term) != 0)
	{
		printf("Error in tcgetattr [%d]\n", errno);
		exit(1);
	}

	backup = term;

	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	
	if(tcsetattr(0, TCSANOW | TCSAFLUSH, &term)!=0)
	{
		printf("Error in tcsetattr [%d]\n", errno);
		exit(1);
	}

	read(0, buffer, 1);

	if(tcsetattr(0, TCSANOW | TCSAFLUSH, &backup)!=0)
	{
		printf("Error in tcsetattr [%d]\n", errno);
		exit(1);
	}
}

void display(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf(" %3d ", arr[i]);
	}
	printf("\n");
}

void swap(int *i, int *j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}

void _uniq_1911_bSort(int arr[], int n)
{
	int k;
	int swapCounter=0;
	for (int i = 1; i < n; i++)
	{
		swapCounter = 0;
		for (int j = 0; j < n - i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(arr + j, arr + j + 1);
				swapCounter++;
			}
		}
		if (swapCounter == 0)
			return;
	}
}


int check_integrity(int one[], int two[], int n)
{
	_uniq_1911_bSort(one, n);
	_uniq_1911_bSort(two, n);
	for (int i = 0; i < n; i++)
	{
		if (one[i] != two [i])
		{
			printf("**Integrity Error**\n");
			return FAILURE;
		}
	}
	printf("Integrity maintained\n");
	return SUCCESS;
}
