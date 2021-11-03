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
		printf("\n** Error - size of matrix not provided **\n");
		exit(1);
	}
	if (argv[2] == NULL)
	{
		printf("\n** Error - total number of grains not provided **\n");
		exit(1);
	}
	if (argv[3] == NULL)
	{
		printf("\n** Error - matrix printing interval not provided **\n");
		exit(1);
	}
	if (argv[4] == NULL)
	{
		printf("\n** Error - type of simulation not provided **\n");
		exit(1);
	}

	p.size = atoi(argv[1]);			// size of matrix
	p.total_grains = atoi(argv[2]); // total number of grains
	p.interval = atoi(argv[3]);		// matrix printing interval
	p.type = atoi(argv[4]);			// matrix printing interval

	printf("\nSize of matrix: %d", p.size);
	printf("\nTotal number of grains: %d", p.total_grains);
	printf("\nMatrix printing interval: %d", p.interval);

	if (p.type == 0)
	{
		printf("\nType of simulation: center");
	}
	else if (p.type == 1)
	{
		printf("\nType of simulation: random");
	}
	else
	{
		printf("\n** Error - invalid type argument **");
		printf("\nValid arguments are:");
		printf("\n0 - grain at center point");
		printf("\n1 - grain at random point\n");
		exit(1);
	}

	m = AllocateIntMatrix(p.size);
	ZeroMatrix(p.size, m);
	MainLoop(m, p.size, p.total_grains, p.interval, p.type);

	m = FreeIntMatrix(p.size, m);
	return 0;
}
