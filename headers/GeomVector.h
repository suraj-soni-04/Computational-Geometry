#pragma once
#include <cmath>
#include "Point3D.h"
#include "Matrix.h"

class Plane;
class GeomVector : public Point3D
{
public:
    GeomVector();
    GeomVector(double , double , double );
    ~GeomVector()=default;

    bool operator==(const GeomVector &) const;
    double getMagnitude() const;
    GeomVector getNormalized() const;
    double getDotProduct(const GeomVector &) const;
    GeomVector getCrossProduct(const GeomVector &) const;

    GeomVector operator+(const GeomVector &) const;
    GeomVector operator-(const GeomVector &) const;
    GeomVector operator*(const GeomVector &) const;
    GeomVector operator/(const GeomVector &) const;
    
    GeomVector setVectorLength(double) const;
    GeomVector addScalar(double) const;
    GeomVector subtractScalar(double) const;
    GeomVector multiplyScalar(double) const;
    GeomVector divideScalar(double) const;

    double getDistanceBetweenVectors(const GeomVector &) const;
    double getDistanceBetweenVectorAndPlane(const Plane &) const;
    double getAngleBetweenVectors(const GeomVector &) const;
    double getAngleBetweenVectorAndPlane(const Plane &) const;
    void angleBetweenVectorAndAxis() const;

    GeomVector multiplyMatrix(const Matrix &) const;
    GeomVector projectionOnVector(const GeomVector &) const;
    GeomVector projectVectorOnPlane(const GeomVector &, const GeomVector &) const;
    void directionCosines() const;
};
