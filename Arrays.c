#include <stdio.h>
#define SIZE 50
#define NROWS 10
#define NCOOLS 20

int adds (int n1, int n2)
{
	int n3;
	n3 = n1 + n2;
	return (n3);

}
int add2(int *array, int arraysize)
{
	int i, sum=0;
	for (i=0; i<arraysize; ++i)
		sum = sum + array[i];
	return (sum);

}

int main(int argc, char const *argv[])
{
	int array[SIZE]; //custom Macro
	int i, j;
	int maxtix [NROWS] [NCOOLS];

	maxtix [2] [2] = 7777;

	for (i=0; i<NROWS; ++i)
	{
		for (j=0; j<NCOOLS; ++j)
			printf("%d ", maxtix[i][j] = 0);

		for (i=0; i<SIZE; ++i)
			printf("%d ", array[i]);
		printf("\n");
	}

	//	printf("%d\n", adds(array[20], array[30]));
		// printf("%d\n", add2(array, SIZE));





	return 0;
}