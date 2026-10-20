#include "Cylinder.h"
#include <cmath>
#include <algorithm>

Cylinder::Cylinder(const Vector3& baseCenter, const Vector3& direction, float radius, float height, const Material& material, bool capped)
    : baseCenter_(baseCenter),
      axis_(direction.normalized()),
      radius_(radius),
      height_(height),
      material_(material),
      capped_(capped)
{
}

bool Cylinder::intersect(const Ray& ray, float tMin, float tMax, HitRecord& hit) const {
    float closest_t = tMax;
    bool found = false;
    Vector3 hitPoint;
    Vector3 hitNormal;

    // 1. Interseção com a superfície lateral cilíndrica
    Vector3 delta = ray.origin - baseCenter_;
    float d_dot_u = ray.direction.dot(axis_);
    float delta_dot_u = delta.dot(axis_);

    Vector3 d_perp = ray.direction - axis_ * d_dot_u;
    Vector3 delta_perp = delta - axis_ * delta_dot_u;

    float a = d_perp.dot(d_perp);
    float b = 2.0f * d_perp.dot(delta_perp);
    float c = delta_perp.dot(delta_perp) - radius_ * radius_;

    if (a > 1e-7f) {
        float disc = b * b - 4.0f * a * c;
        if (disc >= 0.0f) {
            float sqrt_disc = std::sqrt(disc);
            float roots[2] = { (-b - sqrt_disc) / (2.0f * a), (-b + sqrt_disc) / (2.0f * a) };

            for (float t_candidate : roots) {
                if (t_candidate >= tMin && t_candidate < closest_t) {
                    Vector3 P = ray.at(t_candidate);
                    float h = (P - baseCenter_).dot(axis_);
                    if (h >= 0.0f && h <= height_) {
                        closest_t = t_candidate;
                        hitPoint = P;
                        Vector3 axisPt = baseCenter_ + axis_ * h;
                        hitNormal = (P - axisPt) / radius_;
                        found = true;
                        break; // Primeira raiz válida é a mais próxima
                    }
                }
            }
        }
    }

    // 2. Se for fechado (capped), testa tampas da base e do topo
    if (capped_) {
        // Tampa da base (h = 0)
        float denom_base = ray.direction.dot(-axis_);
        if (std::fabs(denom_base) > 1e-6f) {
            float t_base = (baseCenter_ - ray.origin).dot(-axis_) / denom_base;
            if (t_base >= tMin && t_base < closest_t) {
                Vector3 P = ray.at(t_base);
                if ((P - baseCenter_).length() <= radius_) {
                    closest_t = t_base;
                    hitPoint = P;
                    hitNormal = -axis_;
                    found = true;
                }
            }
        }

        // Tampa do topo (h = height_)
        Vector3 topCenter = baseCenter_ + axis_ * height_;
        float denom_top = ray.direction.dot(axis_);
        if (std::fabs(denom_top) > 1e-6f) {
            float t_top = (topCenter - ray.origin).dot(axis_) / denom_top;
            if (t_top >= tMin && t_top < closest_t) {
                Vector3 P = ray.at(t_top);
                if ((P - topCenter).length() <= radius_) {
                    closest_t = t_top;
                    hitPoint = P;
                    hitNormal = axis_;
                    found = true;
                }
            }
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
