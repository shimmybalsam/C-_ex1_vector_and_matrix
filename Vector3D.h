//
// Created by Shimmy on 12/9/2018.
//

#ifndef EX1_VECTOR3D_H
#define EX1_VECTOR3D_H

#include <iostream>

using namespace std;

/**
 *  A Vecto3D class.
 *  This class represents a vector of shape 3X1.
 */
class Vector3D
{
public:
    /**
     * Default constructor, initializes vector to be all zeros.
     */
    Vector3D();

    /**
     * A constructor, initializes the vector to be (a,b,c)
     * @param a, of type double, the first point in vector
     * @param b, of type double, the second point in vector
     * @param c, of type double, the third point in vector
     */
    Vector3D(double a, double b, double c);

    /**
     * A construcor, initizes the vector with a given array's data
     * @param arr the given array
     */
    explicit Vector3D(double arr[3]);

    /**
     * copy constuctor
     * @param v, another vector to be copied from.
     */
    Vector3D(const Vector3D &v);

    /**
     * overloads the + operator and calculates the addition of 2 vectors
     * @param other another vector to be added to first vector
     * @return a new vector which is the result of the addition.
     */
    Vector3D operator+(const Vector3D& other) const;

    /**
     * overloads the - operator and calculates the substraction of 2 vectors
     * @param other another vector to be subtracted from the first vector
     * @return a new vector which is the result of the substraction.
     */
    Vector3D operator-(const Vector3D& other) const;

    /**
     * overloads the += operator and calculates the addition of current vector and another vector
     * @param other another vector to be added to current vector
     * @return pointer to this, as in current vector, after the addition
     */
    Vector3D& operator+=(const Vector3D& other);

    /**
     * overloads the += operator and calculates the addition of a constant to current vector
     * @param num, the constant value to be added to all points in current vector
     * @return pointer to this, as in current vector, after the addition
     */
    Vector3D& operator+=(double num);

    /**
     * overloads the -= operator and calculates the substraction of another vector from cur vector
     * @param other, the vector to be substracted from current vector
     * @return pointer to this, as in current vector, after the substraction
     */
    Vector3D& operator-=(const Vector3D& other);

    /**
     * overloads the -= operator and calculates the substraction of a constant form current vector
     * @param num, the constant value to be substracted from all points in current vector
     * @return pointer to this, as in current vector, after the substraction
     */
    Vector3D& operator-=(double num);

    /**
     * overloads the - operator and calculates the negetive value of current vector
     * @return pointer to this, as in current vector, after the negation
     */
    Vector3D& operator-();

    /**
     * overloads the *= operator and calculates the multiplication of current vector and a scalar
     * @param num, the scalar to be multiply all points in current vector
     * @return pointer to this, as in current vector, after the multiplication
     */
    Vector3D& operator*=(double num);

    /**
     * overloads the /= operator and calculates the division of current vector by a scalar
     * @param num, the scalar to be divided by
     * @return pointer to this, as in current vector, after the division
     */
    Vector3D& operator/=(double num);

    /**
     * overloads the * operator and calculates the multiplication of a vector and a scalar
     * @param num, the scalar to be multiplied by
     * @return pointer to new vector, which is the result after the multiplication
     */
    Vector3D& operator*(double num);

    /**
     * overloads the / operator and calculates the division of a vector by a scalar
     * @param num, the scalar to be divided by
     * @return pointer to new vector, which is the result after the division
     */
    Vector3D& operator/(double num);

    /**
     * overloads the * operator and calculates the multiplication of a scalar and a vector
     * specifically when the scalar is the left argument and the vector is on the right.
     * @param num the scalar to be multiplied by
     * @param v the vector being multiplied
     * @return vector, which is the result after the multiplication
     */
    friend Vector3D operator*(double num, const Vector3D& v);

    /**
     * overloads the * operator and calculates the multiplication of 2 vectors, the first being
     * this, as in current vector
     * @param other second vector to be multiplied with
     * @return the result of the vectors' multiplication
     */
    double operator*(const Vector3D& other) const;

    /**
     * overloads the | operator, calculating the distance between 2 vectors
     * @param other second vector to check distance from
     * @return distance
     */
    double operator|(const Vector3D& other) const;

    /**
     * calculates the angle between two vectors
     * @param other second vector
     * @return the angle
     */
    double operator^(const Vector3D& other) const;

    /**
     * overloads the << operator and prints out to stream the vectors values
     * @param out the stream of output
     * @param v the vector to be outputed
     * @return out, as in the stream after output was added
     */
    friend ostream &operator<<(ostream &out, const Vector3D &v);

    /**
     * overloads the >> operator and gets to stream the user input
     * @param in the stream of input
     * @param v the vector to which the input should be added to
     * @return in, as in the stream after input was added
     */
    friend istream &operator>>(istream &in, Vector3D &v);

    /**
     * overloads the [] operator allowing access to point in vector
     * @param i which point in vector for access
     * @return value in point i
     */
    double operator[](int i) const;

    /**
     * overloads the [] operator allowing access to point in vector
     * @param i which point in vector for access
     * @return reference to value in point i
     */
    double &operator[](int i);

    /**
     * overloads the = operator, copying value from other vector to current vector
     * @param other vector to be copied from
     * @return pointer to this, as in current vector after the copy was done
     */
    Vector3D& operator=(const Vector3D& other);

    /**
     * calculates the norm of a vector, as in its distance from 0
     * @return the calculated norm
     */
    double norm() const;

    /**
     * calculates the distance between 2 vectors, the first of which being this, as in cur vector
     * @param other second vector to check distance from
     * @return distance
     */
    double dist(const Vector3D &other) const;

private:
    double _vec[3]; /** the vector's data structure */
};

#endif //EX1_VECTOR3D_H
