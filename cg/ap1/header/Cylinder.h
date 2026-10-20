#pragma once
#include "Object.h"
#include "Vector3.h"
#include "Material.h"

class Cylinder : public Object {
    Vector3 baseCenter_;
    Vector3 axis_; // Vetor unitário apontando da base para o topo
    float radius_;
    float height_;
    Material material_;
    bool capped_;

public:
    Cylinder(const Vector3& baseCenter, const Vector3& direction, float radius, float height, const Material& material, bool capped = false);

    bool intersect(const Ray& ray, float tMin, float tMax, HitRecord& hit) const override;

    const Vector3& baseCenter() const { return baseCenter_; }
    const Vector3& axis() const { return axis_; }
    float radius() const { return radius_; }
    float height() const { return height_; }
    const Material& material() const { return material_; }
};
