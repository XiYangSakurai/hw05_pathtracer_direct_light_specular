#include "diffusearealight.h"

Color3f DiffuseAreaLight::L(const Intersection &isect, const Vector3f &w) const
{
    //TODO
    if(twoSided==false)
    {
        if(glm::dot(w,isect.normalGeometric)<=0.0f)
            return Color3f(0.0f);
    }

    return emittedLight;
}
Color3f DiffuseAreaLight::Sample_Li(const Intersection &ref, const Point2f &xi, Vector3f *wi, Float *pdf) const
{
    Intersection isect=shape->Sample(ref,xi,pdf);
    *wi=glm::normalize(isect.point-ref.point);
    if(fabs(*pdf)<FLT_EPSILON)
        return Color3f(0.0f);
    if(glm::length(isect.point-ref.point)<ShadowEpsilon)
        return Color3f(0.0f);
    return L(isect,-1.0f*(*wi));

    //return Color3f(0.0f);
}
