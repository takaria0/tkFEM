#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class TwoDimensionTriangularFiniteElementMethod {
  private:
    vector<double> d;         // displacement vector d
    vector<vector<double>> K; // stiffness matrix K



    double _eachAreaA(int i, int j, int k) {
      double A = 0.5 * abs((triCoordinates[j][0] - triCoordinates[i][0]) * (triCoordinates[k][1] - triCoordinates[i][1]) -
                    (triCoordinates[k][0] - triCoordinates[i][0]) * (triCoordinates[j][1] - triCoordinates[i][1]));
      return A;
    };

    vector<vector<double>> _eachDmatrix() {
      /*
      D = C*[
        [1, mu, 0],
        [mu, 1, 0],
        [0, 0, (1-mu)/2]
      ]
      C = E / 1-mu^2
      */
      double coef = (modulus / (1 - pow(poissonRatio, 2));
      vector<vector<double>> D {
        {coef * 1, coef * poissonRatio, 0},
        {coef * poissonRatio, coef * 1, 0},
        {0, 0, coef * (1 - poissonRatio)/2}
      };
      return D;
    };

    vector<vector<double>> _eachBmatrix(int i, int j, int k) {

      vector<vector<double>> B {
          {triCoordinates[j][1] - triCoordinates[k][1], 0, triCoordinates[k][1] - triCoordinates[i][1], 0, triCoordinates[i][1] - triCoordinates[j][1], 0},
          {0, triCoordinates[k][0] - triCoordinates[j][0], 0, triCoordinates[i][0] - triCoordinates[k][0], 0, triCoordinates[j][0] - triCoordinates[i][0]},
          {triCoordinates[k][0] - triCoordinates[j][0], triCoordinates[j][1] - triCoordinates[k][1], triCoordinates[i][0] - triCoordinates[k][0], triCoordinates[k][1] - triCoordinates[i][1], triCoordinates[j][0] - triCoordinates[i][0], triCoordinates[i][1] - triCoordinates[j][1]}
      };
      for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 5; b++) {
          B[a][b] = (1 / 2 * _eachAreaA(i, j, k)) * B[a][b];
        }
      }
      return B;
    };

    vector<vector<double>> _eachStiffnessMatrix(int num) {
      vector<double> ijk = triIndeces[num];
      int i = ijk[0];
      int j = ijk[1];
      int k = ijk[2];

      vector<vector<double>> K;
      vector<vector<double>> B = _eachBmatrix(i, j, k);
      vector<vector<double>> D = _eachDmatrix();
      vector<vector<double>> B_T = transpose(B);
      double A = _eachAreaA(i, j, k);
      double t = thickness;

      K = thickness * A * B_T * D * B;
    };

    vector<vector<double>> _stiffnessMatrix() {
      vector<vector<double>> globalK;
      vector<vector<double>> eachK;
      for (int num = 0; num < elements; num++) {
        
        eachK = _eachStiffnessMatrix(num);

        globalK += eachK;
      }
    };



  public:
    const int dims = 2;
    int elements; 
    double thickness; // t
    double poissonRatio; // mu
    double modulus; // E
    vector<vector<double>> coordinates; // [[x1, y1], [x2, y2], ... ]
    vector<vector<double>> triCoordinates;
    vector<vector<double>> triIndeces;
    vector<double> forces; //  force vector F

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
      {0.0, 1.0}
  };

  tri.triIndeces = {
      /*
      {i, j, k} counter clockwise
      */
      {0, 4, 5},
      {0, 1, 4},
      {1, 2, 4},
      {2, 3, 4}
  };

  tri.stiffness();
  tri.displacements();
};