#!/bin/bash

gcc LR1_tee5x5.c test_cell.c -lm
./a.out -w
mpicc LR1_tee5x5_mpi.c test_cell.c -lm
mpirun -np 5 ./a.out -t
