#pragma once
#include <cmath>
#include "point3D.h"

namespace Geometry
{
    class Vector3D : public Point3D
    {
    public:
    Vector3D();
        Vector3D(double x, double y, double z);
        ~Vector3D();
        bool operator == (const Vector3D &other) const;
        double magnitude() const;
        Vector3D normalize() const;
        double dotProduct(const Vector3D &other) const;
        Vector3D crossProduct(const Vector3D &other) const;

        Vector3D operator + (const Vector3D &other) const;
        Vector3D operator - (const Vector3D &other) const;
        Vector3D operator * (const Vector3D &other) const;
        Vector3D operator / (const Vector3D &other) const;
        Vector3D setVectorLength(double newLength) const;

        Vector3D addScalar(double scalar) const;
        Vector3D subtractScalar(double scalar) const;
        Vector3D multiplyScalar(double scalar) const;
        Vector3D divideScalar(double scalar) const;

        double distanceBetweenVectors(const Vector3D &other) const;
        double distanceBetweenVectorAndPlane() const;
        double angleBetweenVectors(const Vector3D &other) const;
        void angleBetweenVectorAndAxis() const;
        double angleBetween(const Vector3D &other) const;
        double angleWithAxis(int axis) const;
        
        Vector3D projection(const Vector3D &onto) const;
        Vector3D directionCosines() const;
        // Vector3D subtractScalar(double scalar) const;
        // Vector3D scalarDivision(double scalar) const;
    };
}
