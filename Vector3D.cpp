//
// Created by Shimmy on 12/9/2018.
//
#include <iostream>
#include <cmath>
#include "Vector3D.h"

#define DIV_BY_ZERO "Division by zero error."
#define WHITESPACE " "
#define BAD_INDEX "Not a valid index."
#define VEC_LEN 3

using namespace std;

// --------------------------------------------------------------------------------------
// This file contains the implementation of the class Vector3D.
// --------------------------------------------------------------------------------------

/** the following functions are all implementations of the functions declared in Vector3D.h, as such
 * all documentation of functions are same as in Vector3D.h.
 */

Vector3D::Vector3D()
{
    this->_vec[0] = 0;
    this->_vec[1] = 0;
    this->_vec[2] = 0;
}

Vector3D::Vector3D(double a, double b, double c)
{
    this->_vec[0] = a;
    this->_vec[1] = b;
    this->_vec[2] = c;
}

Vector3D::Vector3D(double arr[3])
{
    for (int i = 0; i < VEC_LEN; i++)
    {
        this->_vec[i] = arr[i];
    }
}

Vector3D::Vector3D(const Vector3D &v)
{
    for (int i = 0; i < VEC_LEN; i++)
    {
        this->_vec[i] = v._vec[i];
    }
}

Vector3D Vector3D::operator+(const Vector3D &other) const
{
    Vector3D ret(*this);
    for (int i = 0; i < VEC_LEN; i++)
    {
        ret._vec[i] += other._vec[i];
    }
    return ret;

}

Vector3D Vector3D::operator-(const Vector3D &other) const
{
    Vector3D ret = Vector3D();
    for (int i = 0; i < VEC_LEN; i++)
    {
        ret._vec[i] = this->_vec[i] - other._vec[i];
    }
    return ret;

}

Vector3D& Vector3D::operator=(const Vector3D &other)
{
    for (int i = 0; i < VEC_LEN; i++)
    {
        this->_vec[i] = other._vec[i];
    }
    return *this;
}

Vector3D& Vector3D::operator+=(const double num)
{
    for (int i = 0; i < VEC_LEN; i++)
    {
        this->_vec[i] = this->_vec[i] + num;
    }
    return *this;
}

Vector3D& Vector3D::operator+=(const Vector3D &other)
{
    for (int i = 0; i < VEC_LEN; i++)
    {
        this->_vec[i] = this->_vec[i] + other._vec[i];
    }
    return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D &other)
{
    for (int i = 0; i < VEC_LEN; i++)
    {
        this->_vec[i] = this->_vec[i] - other._vec[i];
    }
    return *this;
}

Vector3D& Vector3D::operator-=(double num)
{
    for (int i = 0; i < VEC_LEN; i++)
    {
        this->_vec[i] = this->_vec[i] - num;
    }
    return *this;
}

Vector3D& Vector3D::operator-()
{
    for (int i = 0; i < VEC_LEN; i++)
    {
        this->_vec[i] = this->_vec[i] * (-1);
    }
    return  *this;
}


Vector3D& Vector3D::operator*=(double num)
{
    for (int i = 0; i < VEC_LEN; i++)
    {
        this->_vec[i] = this->_vec[i] * num;
    }
    return *this;
}

Vector3D& Vector3D::operator/=(double num)
{
    if (num != 0)
    {
        for (int i = 0; i < VEC_LEN; i++)
        {
            this->_vec[i] = this->_vec[i] / num;
        }
        return *this;
    }
    else
    {
        cerr << DIV_BY_ZERO << endl;
        return *this;
    }
}

Vector3D& Vector3D::operator*(double num)
{
    for (int i = 0; i < VEC_LEN; i++)
    {
        this->_vec[i] = this->_vec[i] * num;
    }
    return *this;
}

Vector3D& Vector3D::operator/(double num)
{
    if (num!= 0)
    {
        for (int i = 0; i < VEC_LEN; i++)
        {
            this->_vec[i] = this->_vec[i] / num;
        }
    }
    else
    {
        cerr << DIV_BY_ZERO;
    }
    return *this;
}

Vector3D operator*(double num, const Vector3D &v)
{
    Vector3D temp = v;
    return temp*num;
}

double Vector3D::operator*(const Vector3D &other) const
{
    double sum = 0;
    for (int i = 0; i < VEC_LEN; i++)
    {
        sum += this->_vec[i] * other._vec[i];
    }
    return sum;
}

double Vector3D::operator[](int i) const
{
    if (i >= 0 and i < VEC_LEN)
    {
        return _vec[i];

    }
    else
    {
        cerr << BAD_INDEX;
        return 0;
    }
}

double &Vector3D::operator[](int i)
{
    if (i >= 0 and i < VEC_LEN)
    {
        return _vec[i];

    }
    else
    {
        cerr << BAD_INDEX;
        return _vec[0];

    }
}

double Vector3D::operator|(const Vector3D &other) const
{
    Vector3D temp = *this - other;
    double inner = 0;
    for (int i = 0; i < VEC_LEN; i++)
    {
        inner += pow(temp._vec[i], 2);
    }
    return sqrt(inner);
}

double Vector3D::operator^(const Vector3D &other) const
{
    double numerator = *this * other;
    double denominator = this->norm() * other.norm();
    if (denominator != 0)
    {
        return acos(numerator / denominator);
    }
    else
    {
        cerr << DIV_BY_ZERO;
        return 0;
    }

}

ostream &operator<<(ostream &out, const Vector3D &v)
{
    out << v._vec[0] << WHITESPACE;
    out << v._vec[1] << WHITESPACE;
    out << v._vec[2];
    return out;
}


istream &operator>>(istream &in, Vector3D &v)
{
    in >> v._vec[0];
    in >> v._vec[1];
    in >> v._vec[2];
    return in;
}

double Vector3D::norm() const
{
    double inner = pow(this->_vec[0], 2) + pow(this->_vec[1], 2) + pow(this->_vec[2], 2);
    return sqrt(inner);
}

double Vector3D::dist(const Vector3D &other) const
{
    return *this | other;
}