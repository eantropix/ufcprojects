#pragma once
#include <vector>
#include <memory>
#include "Object.h"
#include "PointLight.h"
#include "Ray.h"
#include "Color.h"
#include "HitRecord.h"
#include "Camera.h"
#include "Framebuffer.h"

class Scene {
public:
    std::vector<std::shared_ptr<Object>> baseObjects;
    std::vector<std::shared_ptr<Object>> rayBeamObjects; // Raio laser e marcadores 3D
    PointLight light;
    Color ambientIntensity;
    Color backgroundColor;
    bool showRayBeam;

    Scene();

    void addBaseObject(std::shared_ptr<Object> obj);
    void addRayBeamObject(std::shared_ptr<Object> obj);

    bool intersect(const Ray& ray, float tMin, float tMax, HitRecord& hit) const;
    Color traceRay(const Ray& ray, int depth = 0) const;

    void render(const Camera& cam, Framebuffer& fb, bool drawReticle = false) const;
};
