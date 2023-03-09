# Compute the sum of an array of 100 numbers using a reduce operation.

import numpy as np
from mpi4py import MPI

comm = MPI.COMM_WORLD
rank = comm.Get_rank()

if rank == 0:
    # create an array of 100 numbers
    data = np.arange(100)
    # reduce the numbers to all processes
    comm.Reduce(data, root=0)
else:
    # assign chapters to students
    data = None
    data = comm.Reduce(data, root=0)
    # compute the average of the numbers
    avg = np.mean(data)
    # gather the averages from all processes to process 0
    avg = comm.Gather(avg, root=0)
    if rank == 0:
        print("The average of the array is %f" %np.mean(avg))