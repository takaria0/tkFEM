#include "../../src/2D/triangular.h"

int main()
{
  TwoDimensionTriangularFiniteElementMethod tri;

  tri.elements = 4;

  tri.coordinates = {
      {0.0, 0.0},
      {0.0, 1.0},
      {1.0, 0.0},
      {1.0, 1.0}
  };

  tri.triCoordinates = {
      /*
      {x_i, y_i} i = 0 : elements
      */
      {0.0, 0.0},
      {1.0, 0.0},
      {2.0, 0.0},
      {2.0, 1.0},
      {1.0, 1.0},
      {0.0, 1.0}};

  tri.triIndeces = {
      /*
      {i, j, k} counter clockwise
      */
      {0, 4, 5},
      {0, 1, 4},
      {1, 2, 4},
      {2, 3, 4}};

  tri.stiffness();
  tri.displacements();

  return 0;
};