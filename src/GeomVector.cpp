#include <iostream>
#include <cmath>
#include "..\headers\GeomVector.h"
#include "..\headers\Plane.h"
using namespace std;

GeomVector::GeomVector() : Point3D() {}
GeomVector::GeomVector(double x, double y, double z) : Point3D(x, y, z) {}

GeomVector GeomVector::getCrossProduct(const GeomVector &other) const
{
    double newX = (this->getY() * other.getZ()) - (this->getZ() * other.getY());
    double newY = (this->getZ() * other.getX()) - (this->getX() * other.getZ());
    double newZ = (this->getX() * other.getY()) - (this->getY() * other.getX());
    return GeomVector(newX, newY, newZ);
}

bool GeomVector ::operator==(const GeomVector &other) const
{
    return ((other.getX() == this->getX()) && (other.getY() == this->getY()) && (other.getZ() == this->getZ()));
}
double GeomVector::getDotProduct(const GeomVector &other) const
{
    return (this->getX() * other.getX()) + (this->getY() * other.getY()) + (this->getZ() * other.getZ());
}

double GeomVector::getMagnitude() const
{
    return sqrt(this->getX() * this->getX() + this->getY() * this->getY() + this->getZ() * this->getZ());
}

GeomVector GeomVector::operator+(const GeomVector &other) const
{
    return GeomVector(this->getX() + other.getX(), this->getY() + other.getY(), this->getZ() + other.getZ());
}

GeomVector GeomVector::getNormalized() const
{
    double mag = getMagnitude();
    return GeomVector(this->getX() / mag, this->getY() / mag, this->getZ() / mag);
}

GeomVector GeomVector::operator*(const GeomVector &other) const
{
    return GeomVector(this->getX() * other.getX(), this->getY() * other.getY(), this->getZ() * other.getZ());
}

GeomVector GeomVector::operator-(const GeomVector &other) const
{
    return GeomVector(this->getX() - other.getX(), this->getY() - other.getY(), this->getZ() - other.getZ());
}

GeomVector GeomVector::operator/(const GeomVector &other) const
{
    return GeomVector(this->getX() / other.getX(), this->getY() / other.getY(), this->getZ() / other.getZ());
}

GeomVector GeomVector::addScalar(double scalar) const
{
    return GeomVector(this->getX() + scalar, this->getY() + scalar, this->getZ() + scalar);
}

GeomVector GeomVector::setVectorLength(double newLength) const
{
    return this->getNormalized().multiplyScalar(newLength);
}

GeomVector GeomVector::subtractScalar(double scalar) const
{
    return GeomVector(this->getX() - scalar, this->getY() - scalar, this->getZ() - scalar);
}

GeomVector GeomVector::multiplyScalar(double scalar) const
{
    return GeomVector(this->getX() * scalar, this->getY() * scalar, this->getZ() * scalar);
}

double GeomVector::getDistanceBetweenVectorAndPlane(const Plane &plane) const
{
    double dX = getX() - plane.getPointOnPlane().getX();
    double dY = getY() - plane.getPointOnPlane().getY();
    double dZ = getZ() - plane.getPointOnPlane().getZ();
    double getDotProduct = dX * plane.getNormal().getX() + dY * plane.getNormal().getY() + dZ * plane.getNormal().getZ();
    double distance = abs(getDotProduct) / plane.getNormal().getMagnitude();
    return distance;
}

GeomVector GeomVector::divideScalar(double scalar) const
{
    return GeomVector(this->getX() / scalar, this->getY() / scalar, this->getZ() / scalar);
}

double GeomVector::getDistanceBetweenVectors(const GeomVector &other) const
{
    double dx = this->mX - other.getX();
    double dy = this->mY - other.getY();
    double dz = this->mZ - other.getZ();
    return sqrt(dx * dx + dy * dy + dz * dz);
}


double GeomVector ::getAngleBetweenVectors(const GeomVector &other) const
{
    double dotProductResult = this->getDotProduct(other);
    double magnitudeResult = getMagnitude() * other.getMagnitude();
    double angleradians = acos(dotProductResult / magnitudeResult);
    return angleradians * (180.0 /M_PI);
}

GeomVector GeomVector::multiplyMatrix(const Matrix &matrix) const
{
    double resultX = getX() * matrix.getElement(0, 0) + getY() * matrix.getElement(1, 0) + getZ() * matrix.getElement(2, 0);
    double resultY = getX() * matrix.getElement(0, 1) + getY() * matrix.getElement(1, 1) + getZ() * matrix.getElement(2, 1);
    double resultZ = getX() * matrix.getElement(0, 2) + getY() * matrix.getElement(1, 2) + getZ() * matrix.getElement(2, 2);
    return GeomVector(resultX, resultY, resultZ);
}


double GeomVector::getAngleBetweenVectorAndPlane(const Plane &plane) const
{
    double dotProductResult = getDotProduct(plane.getNormal());
    double vectorMagnitude = getMagnitude();
    double normalMagnitude = plane.getNormal().getMagnitude();
    double angleRadians = acos(dotProductResult / (vectorMagnitude * normalMagnitude));
    return angleRadians * (180.0 / M_PI);
}

void GeomVector ::directionCosines() const
{
    double magnitudeResult = getMagnitude();
    double alpha;
    double beta;
    double gamma;
    if (magnitudeResult != 0.0)
    {
        alpha = acos(this->getX() / getMagnitude()) * (180.0 / M_PI);
        beta = acos(this->getY() / getMagnitude()) * (180.0 / M_PI);
        gamma = acos(this->getZ() / getMagnitude()) * (180.0 / M_PI);
    }
    else
    {
        alpha = beta = gamma = 0.0;
    }
}


GeomVector GeomVector::projectVectorOnPlane(const GeomVector &vector, const GeomVector &planeNormal) const
{
    GeomVector projection = vector.projectionOnVector(planeNormal);
    GeomVector result = vector - projection;
    return result;
}

GeomVector GeomVector::projectionOnVector(const GeomVector &otherVector) const
{
    double dotProductResult = getDotProduct(otherVector);
    double denominator = otherVector.getDotProduct(otherVector);

    if (abs(denominator) == 0)
    {
        return GeomVector();
    }

    double scalarValue = dotProductResult / denominator;
    return otherVector.multiplyScalar(scalarValue);
}

