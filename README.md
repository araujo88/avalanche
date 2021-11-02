# avalanche

## Bak-Tang-Wiesenfeld Sandpile Model

The code on this folder aim to model the sandpile avalanche model as presented by Bak, Tang and Wiesenfeld (1988). The user is
required to enter three parameters: the size of the matrix (which represents a 2D plane), the number of grains which will be
randomly distributed along the matrix and the time interval between them. The program computes each iteration and, if a
condition for avalanche is met (which is the rule that a single element from the matrix cannot contain more than 4 grains), the
four grains are distributed to the adjacent elements, remaining 1 grain. The aim of this simulation is to show how simple
systems evolve into chaotic configurations. The output can be visualized in Paraview (www.paraview.org).

Reference: Bak, Per, Chao Tang, and Kurt Wiesenfeld. "Self-organized criticality." Physical review A 38.1 (1988): 364.

## Requirements

Paraview (https://www.paraview.org/) is required for data visualization.

## Compilation and running

Compilation:

`make clean`

`make all`

To run the program, 3 arguments are needed: matrix size, total number of grains and grain printing interval. Example:

`./avalanche 50 5000 5`

This command will run the program with matrix size of 50, 5000 total number of grains and the .vtk file will be printed every 5 grain interval.

## Data visualization

For visualization of the program output, run the following command:

`paraview output/`

In Paraview, choose "open files" and then select the generated .vtk files.
