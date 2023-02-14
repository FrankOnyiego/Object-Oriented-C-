#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define LATTICE_SIZE 3 // lattice size L
#define LATTICE_VOLUME 27 // L^3
#define MAX_ITERATIONS 10000 // maximum number of iterations
#define TOLERANCE 1e-8 // tolerance for stopping criterion
#define MU 0.1 // chemical potential �
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
  Complex �[LATTICE_VOLUME]; // field variable �
  Complex �_new[LATTICE_VOLUME]; // updated field variable �
  double s = 1.0; // overrelaxation parameter

  // initialize � with random values
  for (int i = 0; i < LATTICE_VOLUME; i++) {
    �[i].real = (double)rand() / RAND_MAX;
    �[i].imag = (double)rand() / RAND_MAX;
  }

  // Hybrid Overrelaxation loop
  for (int iter = 0; iter < MAX_ITERATIONS; iter++) {
    double delta = 0.0;
    for (int x = 0; x < LATTICE_VOLUME; x++) {
      // calculate the real and imaginary parts of �_new
      �_new[x].real = 0.0;
      �_new[x].imag = 0.0;
      for (int � = 0; � < 3; �++) {
        int x_neighbor = x + pow(LATTICE_SIZE, �);
        �_new[x].real += -2 * K * (�[x_neighbor].real + �[x_neighbor].imag);
        �_new[x].imag += -2 * K * (�[x_neighbor].imag - �[x_neighbor].real);
      }
      �_new[x].real = (1 - s) * �[x].real + s * �_new[x].real / (6 * K + MU);
      �_new[x].imag = (1 - s) * �[x].imag + s * �_new[x].imag / (6 * K + MU);

      // apply the constraint �_x^T �_x = 1
      double magnitude_� = magnitude(�[x]);
      �_new[x].real /= magnitude_�;
      �_new[x].imag /= magnitude_�;
      �_new[x].real = �_new[x].real - LAMBDA * (magnitude_� - 1) * �_new[x].real;
      �_new[x].imag = �_new[x].imag - LAMBDA * (magnitude_� - 1) * �_new[x].imag;
      
      // update delta
      delta += pow(magnitude(�[x]) - magnitude(�_new[x]), 2);
    }
    
    // copy �_new to �
    for (int i = 0; i < LATTICE_VOLUME; i++) {
      �[i].real = �_new[i].real;
      �[i].imag = �_new[i].imag;
    }
    
    // check stopping criterion
    if (sqrt(delta / LATTICE_VOLUME) < TOLERANCE) {
      break;
    }
  }
  
 printf("Solution:\n");
for (int x = 0; x < LATTICE_VOLUME; x++) {
  printf("x = %d, �.real = %f, �.imag = %f\n", x, �[x].real, �[x].imag);
}

  
  return 0;
}

