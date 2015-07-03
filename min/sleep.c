#include <stdio.h>
#include <unistd.h>
#include "mpi.h"
#include "charm.h"

#define BRANCH (rank < comm_size / 2)
    
int
main(int argc, char *argv[])
{
    int rank, comm_size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_size);

    int i, pe_before, pe_after;
    
    if (BRANCH)
    	sleep(2);
    else
	    sleep(1);

    pe_before = CkMyPe();
    MPI_Migrate();
    pe_after = CkMyPe();
    
    fprintf(stderr, "%s rank %d from %d to %d\n", 
    	BRANCH?"heavy":"light", rank, pe_before, pe_after);
    MPI_Finalize();
    return 0;
}
