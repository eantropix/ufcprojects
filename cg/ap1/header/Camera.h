#pragma once
#include "Vector3.h"
#include "Ray.h"

class Camera {
public:
    Vector3 lookFrom;
    Vector3 lookAt;
    Vector3 vUp;
    float vFov; // graus
    float aspect;

    Vector3 u, v, w;
    float halfWidth, halfHeight;

    Camera();
    Camera(const Vector3& from, const Vector3& at, const Vector3& up, float fovDeg, float aspectRatio);

    void setLook(const Vector3& from, const Vector3& at, const Vector3& up);
    void update();
    Ray getRay(float s, float t) const;
};
