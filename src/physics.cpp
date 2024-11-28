#include "physics.hpp"
#include <cmath>

std::pair<double, double> computeImplicitEuler(const double& g, const double& m1,
    const double& m2, const double& l1, const double& l2, const double& theta1,
    const double& theta2, const double& theta_vel1, const double& theta_vel2, const double& dt)
{
    double f1 = -g * (2.0 * m1 + m2) * sin(theta1);
    double f2 = -m2 * g * sin(theta1 - 2.0 * theta2);
    double f3 = -2.0 * sin(theta1 - theta2) * m2;
    double f4 = theta_vel2 * theta_vel2 * l2 + theta_vel1 * theta_vel1 * l1 * cos(theta1 - theta2);
    double f5 = l1 * (2.0 * m1 + m2 - m2 * cos(2.0 * theta1- 2.0 * theta2));
    double theta_acc1 = (f1 + f2 + f3 * f4) / f5;
    f1 = 2.0 * sin(theta1 - theta2);
    f2 = theta_vel1 * theta_vel1 * l1 * (m1 + m2);
    f3 = g * (m1 + m2) * cos(theta1);
    f4 = theta_vel2 * theta_vel2 * l2 * m2 * cos(theta1 - theta2);
    f5 = l2 * (2.0 * m1 + m2 - m2 * cos(2.0 * theta1 - 2.0 * theta2));
    double theta_acc2 = f1 * (f2 + f3 + f4) / f5;
    return {theta_acc1, theta_acc2};
}
