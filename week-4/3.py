# Compute average of an array of 100 numbers using MPI_Scatter and MPI_Gather
# Steps are
# 1. Create an array of 100 numbers from process 0
# 2. Scatter the numbers to all processes, giving each process an equal amount of numbers.
# 3. Each process computes the average of its numbers
# 4. Gather the averages from all processes to process 0

from mpi4py import MPI
import numpy as np

comm = MPI.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()

if rank == 0:
    # create an array of 100 numbers
    data = np.arange(100)
    # scatter the numbers to all processes
    comm.Scatter(data, root=0, size=100/size)
else:
    # assign chapters to students
    data = None
    data = comm.Scatter(data, root=0, size=100/size)
    # compute the average of the numbers
    avg = np.mean(data)
    # gather the averages from all processes to process 0
    avg = comm.Gather(avg, root=0, size=100/size)
    if rank == 0:
        print("The average of the array is %f" %np.mean(avg))

