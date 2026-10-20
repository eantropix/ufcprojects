#include "Material.h"

Material::Material()
    : ka(0.2f, 0.2f, 0.2f),
      kd(0.8f, 0.8f, 0.8f),
      ks(0.0f, 0.0f, 0.0f),
      shininess(1.0f),
      emissive(0.0f, 0.0f, 0.0f)
{
}

Material::Material(const Color& a, const Color& d, const Color& s, float sh, const Color& em)
    : ka(a),
      kd(d),
      ks(s),
      shininess(sh),
      emissive(em)
{
}
