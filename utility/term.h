
#ifndef __TERM_H_USER
#define __TERM_H_USER
#define SUCCESS 0x0001911
#define FAILURE 0x0001912

#define LOOP(x) for (int i = 0; i < x; i++)

void display(int arr[], int n);
void _getchar();
void swap(int *i, int *j);
int check_integrity(int one[], int two[], int n);
#endif
