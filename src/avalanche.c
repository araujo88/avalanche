#include <stdio.h>
#include <stdlib.h>
#include "avalanche.h"
#include "matrix.h"
#include "utils.h"

void FillMatrix(int t, int **v, int type)
{
    int x, y;

    if (v == NULL)
    {
        printf("** Error: aborting program **\n");
        exit(1);
    }
    if (t < 1)
    {
        printf("** Error: invalid parameter **\n");
        exit(1);
    }

    if (type == 0)
    {
        x = t / 2;
        y = t / 2;
    }
    else if (type == 1)
    {
        x = RandomInteger(0, t - 1);
        y = RandomInteger(0, t - 1);
    }
    else
    {
        printf("\nInvalid type of simulation. Aborting program....");
        exit(1);
    }

    v[x][y] += 1;
}

void CheckAvalanche(int t, int **v)
{
    int i, j;

    if (v == NULL)
    {
        printf("** Error: aborting program **\n");
        exit(1);
    }
    if (t < 1)
    {
        printf("** Error: invalid parameter **\n");
        exit(1);
    }

    for (i = 0; i < t; i++)
    {
        for (j = 0; j < t; j++)
        {
            if ((v[i][j]) > 4) // checks for criticallity
            {
                v[i][j] = v[i][j] - 4;
                if (i + 1 < t - 1)
                    v[i + 1][j] = v[i + 1][j] + 1;
                if (j + 1 < t - 1)
                    v[i][j + 1] = v[i][j + 1] + 1;
                if (i - 1 > 0)
                    v[i - 1][j] = v[i - 1][j] + 1;
                if (j - 1 > 0)
                    v[i][j - 1] = v[i][j - 1] + 1;
                i = 0; // restarts search
                j = 0;
            }
        }
    }
}

void MainLoop(int **v, int t, int e, int it, int type)
{
    int i, n;

    n = it;

    printf("\n");
    if (v == NULL)
    {
        printf("** Error: aborting program **\n");
        exit(1);
    }
    if (t < 1)
    {
        printf("** Error: Invalid parameter **\n");
        exit(1);
    }

    for (i = 1; i <= e; i++)
    {
        FillMatrix(t, v, type);
        CheckAvalanche(t, v);
        if (i == it)
        {
            PrintMatrix(t, v);
            it = it + n;
        }
    }
    printf("\nProgram executed successfully.\n");
}