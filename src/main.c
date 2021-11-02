#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "avalanche.h"

int main(int argc, char *argv[])
{
	int **m;
	pr p;

	printf("\nBak-Tang-Wiesenfeld sandpile avalanche model\n");
	printf("\nBeginning program ...");

	if (argv[1] == NULL)
	{
		printf("\nError - size of matrix not provided. Aborting program ...\n");
		exit(1);
	}
	if (argv[2] == NULL)
	{
		printf("\nError - total number of grains not provided. Aborting program ...\n");
		exit(1);
	}
	if (argv[3] == NULL)
	{
		printf("\nError - matrix printing interval not provided. Aborting program ...\n");
		exit(1);
	}

	printf("\nargv1: %s", argv[1]);
	printf("\nargv2: %s", argv[2]);
	printf("\nargv3: %s", argv[3]);

	p.size = atoi(argv[1]);			// size of matrix
	p.total_grains = atoi(argv[2]); // total number of grains
	p.interval = atoi(argv[3]);		// matrix printing interval

	printf("\nSize of matrix: %d", p.size);
	printf("\nTotal number of grains: %d", p.total_grains);
	printf("\nMatrix printing interval: %d", p.interval);

	m = AllocateIntMatrix(p.size);
	ZeroMatrix(p.size, m);
	MainLoop(m, p.size, p.total_grains, p.interval);

	m = FreeIntMatrix(p.size, m);
	return 0;
}
