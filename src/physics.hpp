#pragma once
#include <utility>

std::pair<double, double> computeImplicitEuler(const double& g, const double& m1, const double& m2,
    const double& l1, const double& l2, const double& theta1, const double& theta2,
    const double& theta_vel1, const double& theta_vel2, const double& dt);

