#include "Cone.h"
#include <cmath>
#include <algorithm>

Cone::Cone(const Vector3& baseCenter, const Vector3& direction, float radius, float height, const Material& material, bool capped)
    : baseCenter_(baseCenter),
      axis_(direction.normalized()),
      apex_(baseCenter + axis_ * height),
      radius_(radius),
      height_(height),
      k_cone_((radius / height) * (radius / height)),
      material_(material),
      capped_(capped)
{
}

bool Cone::intersect(const Ray& ray, float tMin, float tMax, HitRecord& hit) const {
    float closest_t = tMax;
    bool found = false;
    Vector3 hitPoint;
    Vector3 hitNormal;

    // 1. Superfície lateral do cone
    Vector3 delta = ray.origin - apex_;
    float d_u = ray.direction.dot(axis_);
    float delta_u = delta.dot(axis_);

    float M = 1.0f + k_cone_;
    float a = ray.direction.dot(ray.direction) - M * d_u * d_u;
    float b = 2.0f * (ray.direction.dot(delta) - M * d_u * delta_u);
    float c = delta.dot(delta) - M * delta_u * delta_u;

    if (std::fabs(a) > 1e-7f) {
        float disc = b * b - 4.0f * a * c;
        if (disc >= 0.0f) {
            float sqrt_disc = std::sqrt(disc);
            float t1 = (-b - sqrt_disc) / (2.0f * a);
            float t2 = (-b + sqrt_disc) / (2.0f * a);
            if (t1 > t2) std::swap(t1, t2);

            for (float t_candidate : { t1, t2 }) {
                if (t_candidate >= tMin && t_candidate < closest_t) {
                    Vector3 P = ray.at(t_candidate);
                    Vector3 w = P - apex_;
                    float w_u = w.dot(axis_);
                    float h = -w_u; // Altura a partir do ápice em direção à base
                    if (h >= 0.0f && h <= height_) {
                        closest_t = t_candidate;
                        hitPoint = P;
                        Vector3 r_vec = w - axis_ * w_u;
                        Vector3 n_vec = r_vec - axis_ * (w_u * k_cone_);
                        hitNormal = n_vec.normalized();
                        found = true;
                        break;
                    }
                }
            }
        }
    }

    // 2. Tampa da base circular (se capped_ == true)
    if (capped_) {
        float denom = ray.direction.dot(-axis_);
        if (std::fabs(denom) > 1e-6f) {
            float t_base = (baseCenter_ - ray.origin).dot(-axis_) / denom;
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
