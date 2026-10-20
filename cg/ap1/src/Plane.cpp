#include "Plane.h"
#include <cmath>

Plane::Plane(const Vector3& point, const Vector3& normal, const Material& material)
    : point_(point),
      normal_(normal.normalized()),
      material1_(material),
      material2_(material),
      isCheckerboard_(false),
      tileSize_(50.0f)
{
}

Plane::Plane(const Vector3& point, const Vector3& normal, const Material& mat1, const Material& mat2, float tileSize)
    : point_(point),
      normal_(normal.normalized()),
      material1_(mat1),
      material2_(mat2),
      isCheckerboard_(true),
      tileSize_(tileSize)
{
}

bool Plane::intersect(const Ray& ray, float tMin, float tMax, HitRecord& hit) const {
    float denom = normal_.dot(ray.direction);
    if (std::fabs(denom) < 1e-6f) {
        return false;
    }

    float t = (point_ - ray.origin).dot(normal_) / denom;
    if (t < tMin || t > tMax) {
        return false;
    }

    hit.t = t;
    hit.point = ray.at(t);
    hit.normal = (denom < 0.0f) ? normal_ : -normal_;
    hit.object = this;

    if (isCheckerboard_) {
        int cx = static_cast<int>(std::floor(hit.point.x / tileSize_));
        int cz = static_cast<int>(std::floor(hit.point.z / tileSize_));
        if ((cx + cz) % 2 != 0) {
            hit.material = &material2_;
        } else {
            hit.material = &material1_;
        }
    } else {
        hit.material = &material1_;
    }

    return true;
}
