#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;
int main()
{
  Vector3f v(1,2,3);
  Vector3f w(0,1,2);

  cout << "Dot product: " << v.dot(w) << endl;
  double dp = v.adjoint()*w; // automatic conversion of the inner product to a scalar
  cout << "Dot product via a matrix product: " << dp << endl;
  cout << "Cross product:\n" << v.cross(w) << endl;
}
