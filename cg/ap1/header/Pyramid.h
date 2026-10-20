#pragma once
#include "Object.h"
#include "Vector3.h"
#include "Material.h"
#include <vector>

class Pyramid : public Object {
    Vector3 baseCenter_;
    float sideLength_;
    float height_;
    Material material_;

    struct Triangle {
        Vector3 v0, v1, v2;
        Vector3 normal;
    };

    std::vector<Triangle> triangles_;

public:
    Pyramid(const Vector3& baseCenter, float sideLength, float height, const Material& material);

    bool intersect(const Ray& ray, float tMin, float tMax, HitRecord& hit) const override;

    const Vector3& baseCenter() const { return baseCenter_; }
    float sideLength() const { return sideLength_; }
    float height() const { return height_; }
    const Material& material() const { return material_; }
};
