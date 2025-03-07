#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <vectHandling.h>

/**
 * @brief For scalar alpha and vectors y and x, this
 *        sub-routine performs the following operation -
 *        y = y + (alpha*x)
 *        and prints y to an output file
 * @param vect1 Pointer to first vector (y)
 * @param vect2 Pointer to second vector (x)
 * @param alpha Scalar multiplier
 * @param vect_len Length of vectors
 * @param filename Name of output file
 */
void Daxpy(double *vect1, double *vect2, double alpha, long vect_len,
	   char *filename) {
  long i;

#pragma omp parallel for shared(vect1, vect2) private(i)
  for (i = 0; i <= vect_len; i++)
    vect1[i] += alpha * vect2[i];

  print1dvect(vect1, vect_len, filename);
  return;
}
