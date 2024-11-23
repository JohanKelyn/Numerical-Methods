#include "equations_solvers.hpp"
#include <iostream>

int main() {
  std::cout << "TESTING" << "/n";
  auto f = [](double x) { return x * x * x + x - 1; };
  double a = 0;
  double b = 1;

  solve_bisection_method(a, b, f);
  return 0;
}