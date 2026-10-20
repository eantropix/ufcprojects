#pragma once
#include "Color.h"

class Material {
public:
    Color ka;
    Color kd;
    Color ks;
    float shininess;
    Color emissive;

    Material();
    Material(const Color& ka, const Color& kd, const Color& ks, float shininess, const Color& emissive = Color(0.0f, 0.0f, 0.0f));
};
