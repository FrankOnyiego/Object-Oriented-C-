#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define LATTICE_SIZE 3 // lattice size L
#define LATTICE_VOLUME 27 // L^3
#define MAX_ITERATIONS 10000 // maximum number of iterations
#define TOLERANCE 1e-8 // tolerance for stopping criterion
#define MU 0.1 // chemical potential µ
#define LAMBDA 0.1 // constant ?
#define K 1.0 // constant k

// structure to represent a complex number
typedef struct {
  double real;
  double imag;
} Complex;

// function to calculate the magnitude of a complex number
double magnitude(Complex z) {
  return sqrt(z.real * z.real + z.imag * z.imag);
}

int main() {
  Complex Ø[LATTICE_VOLUME]; // field variable Ø
  Complex Ø_new[LATTICE_VOLUME]; // updated field variable Ø
  double s = 1.0; // overrelaxation parameter

  // initialize Ø with random values
  for (int i = 0; i < LATTICE_VOLUME; i++) {
    Ø[i].real = (double)rand() / RAND_MAX;
    Ø[i].imag = (double)rand() / RAND_MAX;
  }

  // Hybrid Overrelaxation loop
  for (int iter = 0; iter < MAX_ITERATIONS; iter++) {
    double delta = 0.0;
    for (int x = 0; x < LATTICE_VOLUME; x++) {
      // calculate the real and imaginary parts of Ø_new
      Ø_new[x].real = 0.0;
      Ø_new[x].imag = 0.0;
      for (int µ = 0; µ < 3; µ++) {
        int x_neighbor = x + pow(LATTICE_SIZE, µ);
        Ø_new[x].real += -2 * K * (Ø[x_neighbor].real + Ø[x_neighbor].imag);
        Ø_new[x].imag += -2 * K * (Ø[x_neighbor].imag - Ø[x_neighbor].real);
      }
      Ø_new[x].real = (1 - s) * Ø[x].real + s * Ø_new[x].real / (6 * K + MU);
      Ø_new[x].imag = (1 - s) * Ø[x].imag + s * Ø_new[x].imag / (6 * K + MU);

      // apply the constraint Ø_x^T Ø_x = 1
      double magnitude_Ø = magnitude(Ø[x]);
      Ø_new[x].real /= magnitude_Ø;
      Ø_new[x].imag /= magnitude_Ø;
      Ø_new[x].real = Ø_new[x].real - LAMBDA * (magnitude_Ø - 1) * Ø_new[x].real;
      Ø_new[x].imag = Ø_new[x].imag - LAMBDA * (magnitude_Ø - 1) * Ø_new[x].imag;
      
      // update delta
      delta += pow(magnitude(Ø[x]) - magnitude(Ø_new[x]), 2);
    }
    
    // copy Ø_new to Ø
    for (int i = 0; i < LATTICE_VOLUME; i++) {
      Ø[i].real = Ø_new[i].real;
      Ø[i].imag = Ø_new[i].imag;
    }
    
    // check stopping criterion
    if (sqrt(delta / LATTICE_VOLUME) < TOLERANCE) {
      break;
    }
  }
  
 printf("Solution:\n");
for (int x = 0; x < LATTICE_VOLUME; x++) {
  printf("x = %d, Ø.real = %f, Ø.imag = %f\n", x, Ø[x].real, Ø[x].imag);
}

  
  return 0;
}

