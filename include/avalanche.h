#ifndef AVALANCHE_H_INCLUDED
#define AVALANCHE_H_INCLUDED

typedef struct Parameters
{
    int size;         // sandpile matrix size
    int total_grains; // total number of grains
    int interval;     // matrix printing interval
} pr;

void FillMatrix(int t, int **v); // fills matrix with grains
void CheckAvalanche(int t, int **v); // checks for avalanche
void MainLoop(int **v, int t, int e, int it); // main program loop

#endif // AVALANCHE_H_INCLUDED
