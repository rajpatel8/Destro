# A Professor wants his students to write each chapter of a book. 
# Write a program that could assign chapters to students (Professor - root, student - process, use scatter). 

from mpi4py import MPI
import numpy as np

comm = MPI.COMM_WORLD
rank = comm.Get_rank()

if rank == 0:
    # assign chapters to professor
    data = np.array([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20])
    comm.Scatter(data, root=0)
else:
    # assign chapters to students
    data = None
    data = comm.Scatter(data, root=0)
    print("I am process %d and I got %d" %(rank, data))