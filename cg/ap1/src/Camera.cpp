#include "Camera.h"
#include <cmath>

Camera::Camera()
    : lookFrom(0.0f, 0.0f, 0.0f),
      lookAt(0.0f, 0.0f, -1.0f),
      vUp(0.0f, 1.0f, 0.0f),
      vFov(60.0f),
      aspect(1.0f)
{
    update();
}

Camera::Camera(const Vector3& from, const Vector3& at, const Vector3& up, float fovDeg, float aspectRatio)
    : lookFrom(from),
      lookAt(at),
      vUp(up),
      vFov(fovDeg),
      aspect(aspectRatio)
{
    update();
}

void Camera::setLook(const Vector3& from, const Vector3& at, const Vector3& up) {
    lookFrom = from;
    lookAt = at;
    vUp = up;
    update();
}

void Camera::update() {
    const float PI = 3.14159265358979323846f;
    float theta = vFov * PI / 180.0f;
    halfHeight = std::tan(theta * 0.5f);
    halfWidth = aspect * halfHeight;

    w = (lookFrom - lookAt).normalized();
    u = vUp.cross(w).normalized();
    v = w.cross(u);
}

Ray Camera::getRay(float s, float t) const {
    // s in [0, 1] da esquerda para a direita
    // t in [0, 1] de cima para baixo
    float px = (2.0f * s - 1.0f) * halfWidth;
    float py = (1.0f - 2.0f * t) * halfHeight;
    Vector3 dir = (u * px + v * py - w).normalized();
    return Ray(lookFrom, dir);
}
