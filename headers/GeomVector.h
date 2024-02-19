#pragma once
#include <cmath>
#include "Point3D.h"
#include "Matrix.h"

class Plane;
class GeomVector : public Point3D
{
public:
    GeomVector();
    GeomVector(double x, double y, double z);
    ~GeomVector();

    bool operator==(const GeomVector &other) const;
    double getMagnitude() const;
    GeomVector getNormalized() const;
    double getDotProduct(const GeomVector &other) const;
    GeomVector getCrossProduct(const GeomVector &other) const;

    GeomVector operator+(const GeomVector &other) const;
    GeomVector operator-(const GeomVector &other) const;
    GeomVector operator*(const GeomVector &other) const;
    GeomVector operator/(const GeomVector &other) const;
    GeomVector setVectorLength(double newLength) const;

    GeomVector addScalar(double scalar) const;
    GeomVector subtractScalar(double scalar) const;
    GeomVector multiplyScalar(double scalar) const;
    GeomVector divideScalar(double scalar) const;

    double getDistanceBetweenVectors(const GeomVector &other) const;
    double getDistanceBetweenVectorAndPlane(const Plane &plane) const;
    double getAngleBetweenVectors(const GeomVector &other) const;
    double getAngleBetweenVectorAndPlane(const Plane &plane) const;
    void angleBetweenVectorAndAxis() const;

    GeomVector multiplyMatrix(const Matrix &matrix) const;
    GeomVector projectionOnVector(const GeomVector &otherVector) const;
    GeomVector projectVectorOnPlane(const GeomVector &vector, const GeomVector &planeNormal) const;
    void directionCosines() const;
};
