#ifndef CGPROJECT_SAMPLING_H
#define CGPROJECT_SAMPLING_H

#include <random>
#include <iostream>
#include "Eigen"
#include <math.h>
using std::uniform_real_distribution;
using std::default_random_engine;
using Eigen::Vector3d;

class Sampler {
private:
    uniform_real_distribution<double> unif;
    default_random_engine re;
    const double PI  =3.141592653589793238463;
public:
    Sampler() : unif(uniform_real_distribution<double>(0,1)) {}
    auto random(double a, double b) -> double;
    auto random() -> double;
    auto sample(Vector3d n, double& cost) -> Vector3d{
        Vector3d nt  = std::fabs(n(0)) > std::fabs(n(1))
                     ? Vector3d(n(2), 0, -n(0)).normalized()
                     : Vector3d(0, -n(2), n(1)).normalized();   // Choose a vector perpendicular to the normal
        Vector3d nb  = n.cross(nt);                             // The cross product of n and nt defines an orthonormal basis
        double randy = random();                                // Cosine-weighted sampling with e = 2. Sample cosTheta^2 for efficiency
        cost = sqrt(randy);
        double phi   = 2 * PI * random();                   // Sample an angle on the nb-nt-plane
        double sinTheta = sqrt(1.0 - randy);                    // sinTheta = sqrt(1 - cosTheta^2)
        double x = sinTheta * cos(phi);                         // Sample x-coordinate on the unit hemisphere
        double y = sqrt(randy);                                 // y = cosTheta
        double z = sinTheta * sin(phi);                         // Sample z-coordinate on the unit hemisphere
        return nb*x + n*y + nt*z;                               // Transform unit vector to the orthonormal basis
    }
    auto sample(Vector3d n) -> Vector3d{
        Vector3d nt  = std::fabs(n(0)) > std::fabs(n(1))
                     ? Vector3d(n(2), 0, -n(0)).normalized()
                     : Vector3d(0, -n(2), n(1)).normalized();   // Choose a vector perpendicular to the normal
        Vector3d nb  = n.cross(nt);
        double phi = (PI / 2) * random();
        double theta = 2 * PI * random();// The cross product of n and nt defines an orthonormal basis
        double x = sin(phi) * sin(theta);                         // Sample x-coordinate on the unit hemisphere
        double y = cos(phi);                                 // y = cosTheta
        double z = sin(phi) * cos(theta);                         // Sample z-coordinate on the unit hemisphere
        return (nb*x + n*y + nt*z).normalized();                               // Transform unit vector to the orthonormal basis
    }
};

#endif //CGPROJECT_SAMPLING_H
