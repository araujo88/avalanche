#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

int **AllocateIntMatrix(int t);      // allocates integer matrix
int **FreeIntMatrix(int t, int **v); // free matrix pointer
void PrintMatrix(int t, int **v);    // prints matrix to vtk file
void ZeroMatrix(int t, int **v);     // fills matrix with zeros

#endif // MATRIX_H_INCLUDED