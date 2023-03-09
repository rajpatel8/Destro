# Write a program that broadcasts i) a number, ii) an array from one process to all others by using MPI_Bcast.

from mpi4py import MPI
import numpy as np

comm = MPI.COMM_WORLD
rank = comm.Get_rank()

if rank == 0:
    data = np.array([1,2,3,4,5])
    print("Process", rank, "broadcasts", data)
    comm.Bcast(data, root=0)
else:
    data = np.empty(5, dtype='i')
    comm.Bcast(data, root=0)
    print("Process", rank, "received", data)
