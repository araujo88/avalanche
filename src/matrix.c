#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

int **AllocateIntMatrix(int t)
{
    int **v;
    int i;
    if (t < 1)
    {
        printf("** Error: invalid parameter **\n");
        return (NULL);
    }
    v = (int **)calloc(t, sizeof(int *));
    if (v == NULL)
    {
        printf("** Error: insufficient memory **");
        return (NULL);
    }
    for (i = 0; i < t; i++)
    {
        v[i] = (int *)calloc(t, sizeof(int));
        if (v[i] == NULL)
        {
            printf("** Error: insufficient memory **");
            return (NULL);
        }
    }
    return (v);
}

int **FreeIntMatrix(int t, int **v)
{
    int i;
    if (v == NULL)
        return (NULL);
    if (t < 1)
    {
        printf("** Error: invalid parameter **\n");
        return (v);
    }
    for (i = 0; i < t; i++)
        free(v[i]);
    free(v);
    return (NULL);
}

void ZeroMatrix(int t, int **v)
{
    int i, j;

    if (v == NULL)
    {
        printf("** Erro: Abortando o programa **\n");
        exit(1);
    }
    if (t < 1) /* verifica parametros recebidos */
    {
        printf("** Erro: Parametro invalido **\n");
        exit(1);
    }

    for (i = 0; i < t; i++)
    {
        for (j = 0; j < t; j++)
        {
            v[i][j] = 0;
        }
    }
}

void PrintMatrix(int t, int **v)
{
    int i, j;
    char c[4];
    static int count = 0;
    char name[64];

    if (v == NULL)
    {
        printf("** Error: Aborting program **\n");
        exit(1);
    }
    if (t < 1)
    {
        printf("** Error: Invalid parameter **\n");
        exit(1);
    }

    sprintf(name, "./output/test-1-%d.vtk", count);
    FILE *pf;

    if ((pf = fopen(name, "a")) == NULL)
    {
        printf("\nError while opening file\n");
        exit(1);
    }

    printf("\n%s", name);

    fprintf(pf, "# vtk DataFile Version 2.0\n"); // vtk file headers
    fprintf(pf, "test\n");
    fprintf(pf, "ASCII\n");
    fprintf(pf, "DATASET STRUCTURED_POINTS\n");
    fprintf(pf, "DIMENSIONS %d %d 1\n", t, t);
    fprintf(pf, "ORIGIN 0 0 0\n");
    fprintf(pf, "SPACING 1 1 1\n");
    fprintf(pf, "POINT_DATA %d\n", t * t);
    fprintf(pf, "SCALARS values float\n");
    fprintf(pf, "LOOKUP_TABLE default");

    for (i = 0; i < t; i++)
    {
        fprintf(pf, "\n");
        for (j = 0; j < t; j++)
        {
            if ((j == 0))
            {
                sprintf(c, "%d", v[i][j]);
                fprintf(pf, c);
            }
            else
            {
                sprintf(c, " %d", v[i][j]);
                fprintf(pf, c);
            }
        }
    }
    fclose(pf);
    count++;
}