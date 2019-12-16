#ifndef TWO_DIM_TRIANGULAR_H
#define TWO_DIM_TRIANGULAR_H

#include <vector>
using namespace std;

class TwoDimensionTriangularFiniteElementMethod
{
private:
  vector<double> d;         // displacement vector d
  vector< vector<double> > K; // stiffness matrix K

public:

  const int dims = 2;
  int elements;
  double thickness;                   // t
  double poissonRatio;                // mu
  double modulus;                     // E
  vector< vector<double> > coordinates; // [[x1, y1], [x2, y2], ... ]
  vector< vector<double> > triCoordinates;
  vector< vector<double> > triIndeces;
  vector<double> forces; //  force vector F

  double eachAreaA(int i, int j, int k);
  vector< vector<double> > eachDmatrix();
  vector< vector<double> > eachBmatrix(int i, int j, int k);
  vector< vector<double> > eachStiffnessMatrix(int num);
  vector< vector<double> > stiffnessMatrix();
  void stiffness();
  vector<double> displacements();
};

#endif 