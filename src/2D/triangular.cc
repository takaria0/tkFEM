#include "triangular.h"
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

double TwoDimensionTriangularFiniteElementMethod::eachAreaA(int i, int j, int k)
{
  double A = 0.5 * abs((triCoordinates[j][0] - triCoordinates[i][0]) * (triCoordinates[k][1] - triCoordinates[i][1]) -
                      (triCoordinates[k][0] - triCoordinates[i][0]) * (triCoordinates[j][1] - triCoordinates[i][1]));
  return A;
};

vector< vector<double> > TwoDimensionTriangularFiniteElementMethod::eachDmatrix()
{
  /*
  D = C*[
    [1, mu, 0],
    [mu, 1, 0],
    [0, 0, (1-mu)/2]
  ]
  C = E / 1-mu^2
  */
  double coef = (modulus / (1 - pow(poissonRatio, 2)));

  vector<vector<double> > D {
    {
      {coef * 1, coef * poissonRatio, 0},
      {coef * poissonRatio, coef * 1, 0},
      {0, 0, coef * (1 - poissonRatio)/2}
    }
  };

  return D;
};
vector< vector<double> > TwoDimensionTriangularFiniteElementMethod::eachBmatrix(int i, int j, int k)
{
  vector<vector<double> > B {
    {
      {triCoordinates[j][1] - triCoordinates[k][1], 0, triCoordinates[k][1] - triCoordinates[i][1], 0, triCoordinates[i][1] - triCoordinates[j][1], 0},
      {0, triCoordinates[k][0] - triCoordinates[j][0], 0, triCoordinates[i][0] - triCoordinates[k][0], 0, triCoordinates[j][0] - triCoordinates[i][0]},
      {triCoordinates[k][0] - triCoordinates[j][0], triCoordinates[j][1] - triCoordinates[k][1], triCoordinates[i][0] - triCoordinates[k][0], triCoordinates[k][1] - triCoordinates[i][1], triCoordinates[j][0] - triCoordinates[i][0], triCoordinates[i][1] - triCoordinates[j][1]}
    }
  };

  for (int a = 0; a < 3; a++)
  {
    for (int b = 0; b < 5; b++)
    {
      B[a][b] = (1 / 2 * eachAreaA(i, j, k)) * B[a][b];
    };
  };
  return B;
};
vector< vector<double> > TwoDimensionTriangularFiniteElementMethod::eachStiffnessMatrix(int num)
{
  // vector<double> ijk = triIndeces[num];
  // int i = ijk[0];
  // int j = ijk[1];
  // int k = ijk[2];

  // vector< vector<double> > K;
  // vector< vector<double> > B = eachBmatrix(i, j, k);
  // vector< vector<double> > D = eachDmatrix();
  // vector< vector<double> > B_T = B.transpose();
  // double A = eachAreaA(i, j, k);
  // double t = thickness;

  // K = thickness * A * B_T * D * B;
};
vector< vector<double> > TwoDimensionTriangularFiniteElementMethod::stiffnessMatrix()
{
  // vector< vector<double> > globalK;
  // vector< vector<double> > eachK;
  // for (int num = 0; num < elements; num++)
  // {

  //   eachK = eachStiffnessMatrix(num);

  //   globalK += eachK;
  // }
};

void TwoDimensionTriangularFiniteElementMethod::stiffness()
{

};
vector<double> TwoDimensionTriangularFiniteElementMethod::displacements()
{

};
