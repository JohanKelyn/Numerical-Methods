#include<iostream>
#include<math.h>
#include<eigen/Eigen>
#include"equations_solvers.h"

int main() {
    auto f = [](double x){return x*x*x + x - 1;};
    double a = 0;
    double b = 1;

    solve_bisection_method(a, b, f);
    return 0;
}