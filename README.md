# avalanche
Bak-Tang-Wiesenfeld Sandpile Model

Reference: Bak, Per, Chao Tang, and Kurt Wiesenfeld. "Self-organized criticality." Physical review A 38.1 (1988): 364.

The codes on this folder aim to model the sandpile avalanche model as presented by Bak, Tang and Wiesenfeld (1988). The user is required to enter three parameters: the size of the matrix (which represents a 2D plane), the number of grains which will be randomly distributed along the matrix and the time interval between them. The program computes each iteration and, if a condition for avalanche is met (which is the rule that a single element from the matrix cannot contain more than 4 grains), the four grains are distributed to the adjacent elements, remaning 1 grain. The aim of this simulation is to show how simple systems evolve to chaotic configurations.
