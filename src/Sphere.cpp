#include "Sphere.h"
#include "Ray.h"
using Eigen::Vector3d;
bool Sphere::intersect(const Ray &ray, double t_min, double &t_max) const {
    Vector3d oc = ray.eye - center;
    double loc = ray.direction.dot(oc);
    double discriminant = pow(loc,2.0) - (oc.squaredNorm() - pow(radius,2.0));
    if (discriminant < 1e-6) {
        return false;
    }
    double sqrt_d = sqrt(discriminant);
    double t = fmin(-loc - sqrt_d,
                    -loc + sqrt_d);
    if (t < t_max && t >= t_min) {
        t_max = t;
        return true;
    }
    return false;
}

void Sphere::get_normal(const Vector3d &l, Vector3d &n) const {
    n = (l - center) / radius;
}

