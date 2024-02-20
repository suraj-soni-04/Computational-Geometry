#pragma once
class Matrix
{
public:
    Matrix();
    Matrix(double, double , double , double , double , double , double , double , double );
    ~Matrix()=default;

    double getElement(int row, int col) const;

private:
    double matrix[3][3];
};
