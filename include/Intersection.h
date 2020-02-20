#ifndef CGPROJECT_INTERSECTION_H
#define CGPROJECT_INTERSECTION_H

#include "Object.h"
#include <vector>
#include <Ray.h>

using std::vector;
using std::shared_ptr;
using Eigen::Vector3d;

struct Intersection {
    double t; // parametric distance of ray
    Vector3d n; // normal vector
    shared_ptr<Object> object; // object intersected
    Ray ray;
};

bool find_nearest_intersection(const vector<shared_ptr<Object>> &objects, const Ray &ray, double offset,
                               Intersection &intersection);

#endif //CGPROJECT_INTERSECTION_H
