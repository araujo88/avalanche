#ifndef AVALANCHE_H_INCLUDED
#define AVALANCHE_H_INCLUDED

typedef struct Parameters
{
    int size;         // sandpile matrix size
    int total_grains; // total number of grains
    int interval;     // matrix printing interval
} pr;

void FillMatrix(int t, int **v);
void CheckAvalanche(int t, int **v);
void MainLoop(int **v, int t, int e, int it);

#endif // AVALANCHE_H_INCLUDED