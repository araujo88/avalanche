#ifndef AVALANCHE_H_INCLUDED
#define AVALANCHE_H_INCLUDED

typedef struct Parameters
{
    int size;         // sandpile matrix size
    int total_grains; // total number of grains
    int interval;     // matrix printing interval
    int type;         // type of simulation: 0 (grain at center), 1 (grain at random point)
} pr;

void FillMatrix(int t, int **v, int type);              // fills matrix with grains
void CheckAvalanche(int t, int **v);                    // checks for avalanche
void MainLoop(int **v, int t, int e, int it, int type); // main program loop

#endif // AVALANCHE_H_INCLUDED
