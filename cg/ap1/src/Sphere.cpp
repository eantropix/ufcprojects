#include "Sphere.h"
#include <cmath>

Sphere::Sphere(const Vector3& c, float r, const Material& m)
    : center_(c), radius_(r), material_(m) {}

bool Sphere::intersect(const Ray& ray, float tMin, float tMax, HitRecord& hit) const {
    Vector3 oc = ray.origin - center_;
    float a = ray.direction.dot(ray.direction);
    float hb = oc.dot(ray.direction);
    float c = oc.dot(oc) - radius_ * radius_;
    float disc = hb * hb - a * c;

    if (disc < 0.0f) return false;

    float s = std::sqrt(disc);
    float t = (-hb - s) / a;
    if (t < tMin || t > tMax) {
        t = (-hb + s) / a;
        if (t < tMin || t > tMax) return false;
    }

    hit.t = t;
    hit.point = ray.at(t);
    Vector3 outward_normal = (hit.point - center_) / radius_;
    hit.normal = (outward_normal.dot(ray.direction) < 0.0f) ? outward_normal : -outward_normal;
    hit.material = &material_;
    hit.object = this;
    return true;
}
