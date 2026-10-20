#include "Pyramid.h"
#include <cmath>

Pyramid::Pyramid(const Vector3& baseCenter, float sideLength, float height, const Material& material)
    : baseCenter_(baseCenter),
      sideLength_(sideLength),
      height_(height),
      material_(material)
{
    float s = sideLength * 0.5f;
    Vector3 v0(baseCenter.x - s, baseCenter.y, baseCenter.z - s);
    Vector3 v1(baseCenter.x + s, baseCenter.y, baseCenter.z - s);
    Vector3 v2(baseCenter.x + s, baseCenter.y, baseCenter.z + s);
    Vector3 v3(baseCenter.x - s, baseCenter.y, baseCenter.z + s);
    Vector3 apex(baseCenter.x, baseCenter.y + height, baseCenter.z);

    auto makeTriangle = [](const Vector3& a, const Vector3& b, const Vector3& c) {
        Triangle t;
        t.v0 = a;
        t.v1 = b;
        t.v2 = c;
        t.normal = (b - a).cross(c - a).normalized();
        return t;
    };

    // 4 faces laterais triangulares
    triangles_.push_back(makeTriangle(v0, v1, apex));
    triangles_.push_back(makeTriangle(v1, v2, apex));
    triangles_.push_back(makeTriangle(v2, v3, apex));
    triangles_.push_back(makeTriangle(v3, v0, apex));

    // Base quadrada dividida em 2 triângulos (apontando para baixo)
    triangles_.push_back(makeTriangle(v0, v2, v1));
    triangles_.push_back(makeTriangle(v0, v3, v2));
}

bool Pyramid::intersect(const Ray& ray, float tMin, float tMax, HitRecord& hit) const {
    const float EPS = 1e-7f;
    float closest_t = tMax;
    bool found = false;
    Vector3 hitPoint;
    Vector3 hitNormal;

    for (const auto& tri : triangles_) {
        Vector3 edge1 = tri.v1 - tri.v0;
        Vector3 edge2 = tri.v2 - tri.v0;
        Vector3 pvec = ray.direction.cross(edge2);
        float det = edge1.dot(pvec);

        if (std::fabs(det) < EPS) continue;

        float invDet = 1.0f / det;
        Vector3 tvec = ray.origin - tri.v0;
        float u = tvec.dot(pvec) * invDet;
        if (u < 0.0f || u > 1.0f) continue;

        Vector3 qvec = tvec.cross(edge1);
        float v = ray.direction.dot(qvec) * invDet;
        if (v < 0.0f || u + v > 1.0f) continue;

        float t = edge2.dot(qvec) * invDet;
        if (t >= tMin && t < closest_t) {
            closest_t = t;
            hitPoint = ray.at(t);
            hitNormal = tri.normal;
            found = true;
        }
    }

    if (found) {
        hit.t = closest_t;
        hit.point = hitPoint;
        hit.normal = (hitNormal.dot(ray.direction) < 0.0f) ? hitNormal : -hitNormal;
        hit.material = &material_;
        hit.object = this;
        return true;
    }

    return false;
}
