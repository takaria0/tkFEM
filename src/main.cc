#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class TwoDimensionTriangularFiniteElementMethod {
  private:
    vector<double> d;         // displacement vector d
    vector<vector<double>> K; // stiffness matrix K

    double area() {

    };

    vector<vector<double>> _eachDmatrix(){
      /*
      D = C*[
        [1, mu, 0],
        [mu, 1, 0],
        [0, 0, (1-mu)/2]
      ]
      C = E / 1-mu^2
      */

      vector<vector<double>> D {
        {1, poissonRatio, 0},
        {poissonRatio, 1, 0},
        {0, 0, (1 - poissonRatio)/2}
      };

      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          D[i][j] = (modulus / (1 - pow(poissonRatio, 2))) * D[i][j];
        }
      }
      return D;
    };

    vector<vector<double>> _eachBmatrix(){
      // example code to implement easier for the future.
      vector<int> globalIndex {1, 2, 4};
      vector<vector<double>> coordinates {
        {0.0, 1.0},
        {0.5, 1.0},
        {0.0, 0.0}
      };
      vector<vector<double>> B {
        {},
        {},
        {}
      };
    };

    vector<vector<double>> _eachStiffnessMatrix(){
      vector<vector<double>> K;
    };

    vector<vector<double>> _stiffnessMatrix()
    {
      vector<vector<double>> eachK;
      for (int i = 0; i < elements; i++) {
        
        eachK = _eachStiffnessMatrix();

        K[] = eachK[i];
      }
    };



  public:
    const int dims = 2;
    int elements; 
    double thickness; // t
    double poissonRatio; // mu
    double modulus; // E
    vector<vector<double>> coordinates; // [[x1, y1], [x2, y2], ... ]
    vector<vector<double>> triangulars;
    vector<double> forces; //  force vector F

    void meshing() {

    };

    void stiffness() {

    };

    vector<double> displacements() {

    };

};





void main() {
  TwoDimensionTriangularFiniteElementMethod tri;

  tri.elements = 4;

  tri.coordinates = {
      {0.0, 0.0},
      {0.0, 1.0},
      {1.0, 0.0},
      {1.0, 1.0},
  };

  tri.triangulars = {
    {0.0, 0.0},
    {},
    {},
    {},
    {},
    {},
    {},
    {}
  };

  tri.meshing();
  tri.stiffness();
  tri.displacements();
};