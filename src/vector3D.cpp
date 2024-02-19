#include <iostream>
#include "../headers/vector3D.h"

Geometry :: Vector3D::Vector3D() : Point3D() {}
Geometry :: Vector3D::Vector3D(double x, double y, double z) : Point3D(x,y,z) {}
 
Geometry:: Vector3D :: Vector3D::~Vector3D() {}
 
 bool Geometry:: Vector3D :: operator == (const Vector3D &other) const
 {
        return ( ( other.x() == this->x() ) && ( other.y() == this->y() ) && ( other.z() == this->z() ) );
 }
double Geometry::Vector3D::dotProduct(const Vector3D &other) const {
    return (this->x() * other.x()) + (this->y() * other.y()) + (this->z() * other.z());
}

Geometry::Vector3D Geometry::Vector3D::crossProduct(const Vector3D& other) const {
    double newX = (this->y() * other.z()) - (this->z() * other.y());
    double newY = (this->z() * other.x()) - (this->x() * other.z());
    double newZ = (this->x() * other.y()) - (this->y() * other.x());
    return Vector3D(newX, newY, newZ);
}

double Geometry::Vector3D::magnitude() const {
    return sqrt(this->x()*this->x() + this->y()*this->y() + this->z()*this->z());
}

Geometry::Vector3D Geometry::Vector3D::normalize() const {
    double mag = magnitude();
    return Vector3D(this->x()/mag, this->y()/mag, this->z()/mag);
}

Geometry::Vector3D Geometry::Vector3D:: operator + (const Vector3D &other) const
{
    return Vector3D(this->x() + other.x(), this->y() + other.y(), this->z() + other.z());
}

Geometry::Vector3D Geometry::Vector3D:: operator - (const Vector3D &other) const
{
    return Vector3D(this->x() - other.x(), this->y() - other.y(), this->z() - other.z());
}

Geometry::Vector3D Geometry::Vector3D:: operator * (const Vector3D &other) const
{
    return Vector3D(this->x() * other.x(), this->y() * other.y(), this->z() * other.z());
}

Geometry::Vector3D Geometry::Vector3D:: operator / (const Vector3D &other) const
{
    return Vector3D(this->x() / other.x(), this->y() / other.y(), this->z() / other.z());
}

Geometry::Vector3D Geometry::Vector3D:: setVectorLength(double newLength) const
{
    return this->normalize().multiplyScalar( newLength );
}

Geometry::Vector3D Geometry::Vector3D::addScalar(double scalar) const {
    return Vector3D(this->x() + scalar, this->y() + scalar, this->z() + scalar);
}

Geometry::Vector3D Geometry::Vector3D::subtractScalar(double scalar) const {
    return Vector3D(this->x() - scalar, this->y() - scalar, this->z() - scalar);
}


Geometry::Vector3D Geometry::Vector3D::multiplyScalar(double scalar) const {
    return Vector3D(this->x() * scalar, this->y() * scalar, this->z() * scalar);
}

Geometry::Vector3D Geometry::Vector3D::divideScalar(double scalar) const {
    return Vector3D(this->x() / scalar, this->y() / scalar, this->z() / scalar);
}

double Geometry::Vector3D::distanceBetweenVectors(const Vector3D& other) const {
    double dx = this->mX - other.x();
    double dy = this->mY - other.y();
    double dz = this->mZ - other.z();
    return sqrt(dx*dx + dy*dy + dz*dz);
}

double Geometry::Vector3D :: angleBetweenVectors(const Vector3D &other) const
{
    double dotProductResult = this->dotProduct(other);
    double magnitudeResult = magnitude() * other.magnitude();
    std::cout << "1: " << dotProductResult << "2: " << magnitudeResult << std::endl;
    double angleradians = acos(dotProductResult / magnitudeResult);
    // converting radians to degrees
    return angleradians * (180.0 / M_PI);
}

void Geometry::Vector3D :: angleBetweenVectorAndAxis() const
{
    double magnitudeResult = magnitude();
    double alpha;
    double beta;
    double gamma;
    // Ensure the magnitude is not zero to avoid division by zero
    if (magnitudeResult != 0.0) {
        alpha = std::acos(this->x() / magnitude()) * (180.0 / M_PI);
        beta = std::acos(this->y() / magnitude()) * (180.0 / M_PI);
        gamma = std::acos(this->z() / magnitude()) * (180.0 / M_PI);
    } else {
        // Handle the case when the magnitude is zero
        alpha = beta = gamma = 0.0;
    }
    std::cout<<"alpha :"<<alpha<<"beta :"<<beta<<"gamma :"<<gamma<<std::endl;
}