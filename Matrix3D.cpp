//
// Created by Shimmy on 12/9/2018.
//
#include <iostream>
#include "Matrix3D.h"

#define BAD_INDEX "Not a valid index."
#define WHITESPACE " "
#define DIV_BY_ZERO "Division by zero error."

using namespace std;

// --------------------------------------------------------------------------------------
// This file contains the implementation of the class Matrix3D.
// --------------------------------------------------------------------------------------

/** the following functions are all implementations of the functions declared in Matrix3D.h, as such
 * all documentation of functions are same as in Matrix3D.h.
 */

Matrix3D::Matrix3D()
{
    this->_first = Vector3D();
    this->_second = Vector3D();
    this->_third = Vector3D();
}

Matrix3D::Matrix3D(double num)
{
    this->_first = Vector3D(num, 0, 0);
    this->_second = Vector3D(0, num, 0);
    this->_third = Vector3D(0, 0, num);
}

Matrix3D::Matrix3D(double a, double b, double c, double d, double e, double f, double g, double h,
                   double i)
{
    this->_first = Vector3D(a, b, c);
    this->_second = Vector3D(d, e, f);
    this->_third = Vector3D(g, h, i);
}

Matrix3D::Matrix3D(double arr[9])
{
    this->_first = Vector3D(arr[0], arr[1], arr[2]);
    this->_second = Vector3D(arr[3], arr[4], arr[5]);
    this->_third = Vector3D(arr[6], arr[7], arr[8]);
}

Matrix3D::Matrix3D(double arr[3][3])
{
    this->_first = Vector3D(arr[0]);
    this->_second = Vector3D(arr[1]);
    this->_third = Vector3D(arr[2]);
}

Matrix3D::Matrix3D(Vector3D &v1, Vector3D &v2, Vector3D &v3)
{
    this->_first = Vector3D(v1);
    this->_second = Vector3D(v2);
    this->_third = Vector3D(v3);
}

Matrix3D::Matrix3D(const Matrix3D &other)
{
    this->_first = other._first;
    this->_second = other._second;
    this->_third = other._third;
}

Matrix3D Matrix3D::operator+(const Matrix3D &other)
{
    Matrix3D result = Matrix3D();
    result._first = this->_first + other._first;
    result._second = this->_second + other._second;
    result._third = this->_third + other._third;
    return result;
}

Matrix3D Matrix3D::operator-(const Matrix3D &other)
{
    Matrix3D result = Matrix3D();
    result._first = this->_first - other._first;
    result._second = this->_second - other._second;
    result._third = this->_third - other._third;
    return result;
}

Matrix3D& Matrix3D::operator+=(const Matrix3D &other)
{
    this->_first += other._first;
    this->_second += other._second;
    this->_third += other._third;
    return *this;
}

Matrix3D& Matrix3D::operator-=(const Matrix3D &other)
{
    this->_first -= other._first;
    this->_second -= other._second;
    this->_third -= other._third;
    return *this;
}

Matrix3D& Matrix3D::operator*=(double num)
{
    this->_first *= num;
    this->_second *= num;
    this->_third *= num;
    return *this;
}

Matrix3D& Matrix3D::operator/=(double num)
{
    if (num != 0)
    {
        this->_first /= num;
        this->_second /= num;
        this->_third /= num;
    }
    else
    {
        cerr << DIV_BY_ZERO;
    }
    return *this;
}

Vector3D Matrix3D::operator*(const Vector3D &v)
{
    double first = this->_first * v;
    double second = this->_second * v;
    double third = this->_third * v;
    return Vector3D(first, second, third);
}

Matrix3D& Matrix3D::operator*=(const Matrix3D &other)
{
    Vector3D col1 = other.column(0);
    Vector3D col2 = other.column(1);
    Vector3D col3 = other.column(2);
    this->_first = Vector3D(this->_first * col1, this->_first * col2, this->_first * col3);
    this->_second = Vector3D(this->_second * col1, this->_second * col2, this->_second * col3);
    this->_second = Vector3D(this->_second * col1, this->_second * col2, this->_second * col3);
    return *this;
}

Matrix3D Matrix3D::operator*(const Matrix3D &other)
{
    Matrix3D result = Matrix3D(*this);
    result *= other;
    return result;
}

ostream &operator<<(ostream &out, const Matrix3D &m)
{
    out << m._first << endl;
    out << m._second << endl;
    out << m._third;
    return out;
}

istream &operator>>(istream &in, Matrix3D &m)
{
    in >> m._first;
    in >> m._second;
    in >> m._third;
    return in;
}

Vector3D Matrix3D::operator[](int i) const
{
    if (i == 0)
    {
        return this->_first;
    }
    if (i == 1)
    {
        return this->_second;
    }
    if (i == 2)
    {
        return this->_third;
    }
    cerr << BAD_INDEX;
    return Vector3D();
}

Vector3D& Matrix3D::operator[](int i)
{
    if (i == 0)
    {
        return this->_first;
    }
    if (i == 1)
    {
        return this->_second;
    }
    if (i == 2)
    {
        return this->_third;
    }
    cerr << BAD_INDEX;
    return this->_first;
}

Matrix3D& Matrix3D::operator=(const Matrix3D &other)
{
    this->_first = other._first;
    this->_second = other._second;
    this->_third = other._third;
    return *this;
}

Vector3D Matrix3D::row(short i) const
{
    if (i == 0)
    {
        return this->_first;
    }
    if (i == 1)
    {
        return this->_second;
    }
    if (i == 2)
    {
        return this->_third;
    }
    cerr << BAD_INDEX;
    return Vector3D(0, 0, 0);
}

Vector3D Matrix3D::column(short i) const
{
    if (i == 0)
    {
        return Vector3D(this->_first[0], this->_second[0], this->_third[0]);
    }
    if (i == 1)
    {
        return Vector3D(this->_first[1], this->_second[1], this->_third[1]);
    }
    if (i == 2)
    {
        return Vector3D(this->_first[2], this->_second[2], this->_third[2]);
    }
    cerr << BAD_INDEX;
    return Vector3D(0, 0, 0);
}

double Matrix3D::trace()
{
    return this->_first[0] + this->_second[1] + this->_third[2];
}

double Matrix3D::_det2X2(double left_top, double right_top, double left_bottom,
                         double right_bottom)
{
    return (left_top * right_bottom) - (left_bottom * right_top);
}

double Matrix3D::determinant()
{
    double first = this->_first[0] * _det2X2(this->_second[1], this->_second[2],
                                             this->_third[1], this->_third[2]);
    double second = this->_first[1] * _det2X2(this->_second[0], this->_second[2],
                                              this->_third[0], this->_third[2]);
    double third = this->_first[2] * _det2X2(this->_second[0], this->_second[1],
                                             this->_third[0], this->_third[1]);
    return first - second + third;
}