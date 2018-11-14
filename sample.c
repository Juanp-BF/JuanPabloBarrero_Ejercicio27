#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"
#define PI 3.14159

int main(int argc, char **argv){
  long n_points;
  double x, y, r;
  double distgauss1, distgauss2;
  double *list;
  float mu, sigma;
  long long i;
  FILE *out;
  int rank, size;
  /* starts MPI */
  MPI_Init (&argc, &argv);
  /* get current process rank */
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  /* get number of processes */
  MPI_Comm_size (MPI_COMM_WORLD, &size);

  n_points = atoi(argv[1])/size;
  mu = atof(argv[2]);
  sigma = atof(argv[3]);

  if(!(out = fopen("sample.dat", "w"))){
    fprintf(stderr, "Problema abriendo el archivo\n");
    exit(1);
  }

  srand48(n_points);
  for(i=0;i<n_points;i++){
      x = drand48();
      y = drand48();
      distgauss1 = sqrt(-2.0 * log(x)) * cos(2.0* PI * y);
      distgauss1 = distgauss1*sigma + mu;
      list[i] = distgauss1;
  }

  if(!(out = fopen("sample.dat", "w"))){
    fprintf(stderr, "Problema abriendo el archivo\n");
    exit(1);
  }

  for(i=0;i<n_points;i++){
    fprintf(out, "%f\n", list[i]);
  }

  fclose(out);

  MPI_Finalize();

  return 0;
}
