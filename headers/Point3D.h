#pragma once

class Point3D
{
public:
    Point3D();
    Point3D(double, double, double);
    ~Point3D()=default;

    double getX() const;
    double getY() const; 
    double getZ() const;

    void setX(double);
    void setY(double);
    void setZ(double);

    bool operator==(const Point3D &) const;
    bool operator<(const Point3D &) const;

protected:
    double mX;
    double mY;
    double mZ;
};
