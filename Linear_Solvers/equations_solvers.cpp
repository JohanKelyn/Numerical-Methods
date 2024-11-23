#include "equations_solvers.hpp"
#include <Eigen/Dense>
#include <iostream>

void solve_bisection_method(double a, double b, double (*func)(double)) {
  double tolerance = 0.00005;
  double c = 100000000;
  if (func(a) * func(b) >= 0) {
    std::cout << "There is no solution in the interval [" << a << ", " << b
              << "]" << std::endl;
  } else {
    while (((b - a) / 2) > tolerance) {
      c = (a + b) / 2;
      if (abs(func(c)) < tolerance) {
        std::cout << "The solution is " << c << std::endl;
      }
      if (func(a) * func(b) < 0) {
        b = c;
      } else {
        a = c;
      }
    }
  }
}