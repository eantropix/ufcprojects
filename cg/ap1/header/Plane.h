#pragma once
#include "Object.h"

class Plane : public Object {
    Vector3 point_;
    Vector3 normal_;
    Material material1_;
    Material material2_;
    bool isCheckerboard_;
    float tileSize_;

public:
    Plane(const Vector3& point, const Vector3& normal, const Material& material);
    Plane(const Vector3& point, const Vector3& normal, const Material& mat1, const Material& mat2, float tileSize);

    bool intersect(const Ray& ray, float tMin, float tMax, HitRecord& hit) const override;

    const Vector3& point() const { return point_; }
    const Vector3& normal() const { return normal_; }
    const Material& material() const { return material1_; }
};
