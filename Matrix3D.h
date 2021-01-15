//
// Created by Shimmy on 12/9/2018.
//

#ifndef EX1_MATRIX3D_H
#define EX1_MATRIX3D_H

#include "Vector3D.h"
#include <iostream>

using namespace std;

/**
 *  A Matrix3D class.
 *  This class represents a Matrix of shape 3X3.
 */
class Matrix3D
{
public:

    /**
     * Default constructor, initializes matrix to be all zeros.
     */
    Matrix3D();

    /**
     * constuctor, initializes diagnol to be with value num and all other points to be zero
     * @param num value to put on the diagnol
     */
    explicit Matrix3D(double num);

    /**
     * constructor, initilizes matrix with given values
     * @param a top vec left val
     * @param b top vec middle val
     * @param c top vec right val
     * @param d middle vec left val
     * @param e middle vec mid val
     * @param f middle vec right val
     * @param g bottom vec left val
     * @param h bottom vec mid val
     * @param i bottom vec right val
     */
    Matrix3D(double a, double b, double c, double d, double e, double f, double g, double h,
             double i);

    /**
     * constuctor, initializes matrix with given array values
     * @param arr given array
     */
    explicit Matrix3D(double arr[9]);

    /**
     * constuctor, initializes matrix with given array values
     * @param arr given array of arrays
     */
    explicit Matrix3D(double arr[3][3]);

    /**
     * constuctor, initializes matrix with given vectors
     * @param v1 first vec
     * @param v2 second vec
     * @param v3 third vec
     */
    Matrix3D(Vector3D &v1, Vector3D &v2, Vector3D &v3);

    /**
     * copy constructor
     * @param other matrix to compy from
     */
    Matrix3D(const Matrix3D &other);

    /**
     * overloads the + operator and calculates the addition of 2 matrices
     * @param other another matrix to be added to first matrix
     * @return a new matrix which is the result of the addition.
     */
    Matrix3D operator+(const Matrix3D &other);

    /**
     * overloads the - operator and calculates the substraction of 2 matrices
     * @param other another matrix to be subtracted from the first matrix
     * @return a new matrix which is the result of the substraction.
     */
    Matrix3D operator-(const Matrix3D &other);

    /**
     * overloads the += operator and calculates the addition of current matrix and another matrix
     * @param other another matrix to be added to current matrix
     * @return pointer to this, as in current matrix, after the addition
     */
    Matrix3D &operator+=(const Matrix3D &other);

    /**
     * overloads the -= operator and calculates the substraction of another matrix from cur matrix
     * @param other, the matrix to be substracted from current matrix
     * @return pointer to this, as in current vector, after the substraction
     */
    Matrix3D &operator-=(const Matrix3D &other);

    /**
     * overloads the *= operator and calculates the multiplication of current matrix and a scalar
     * @param num, the scalar to be multiply all points in current matrix
     * @return pointer to this, as in current matrix, after the multiplication
     */
    Matrix3D &operator*=(double num);

    /**
     * overloads the /= operator and calculates the division of current matrix by a scalar
     * @param num, the scalar to be divided by
     * @return pointer to this, as in current matrix, after the division
     */
    Matrix3D &operator/=(double num);

    /**
     * overloads the *= operator and calculates the multiplication of 2 matrices,
     * the first being this
     * @param other the second matrix, that to be multiplied with
     * @return pointer to this, as the result after the matrices multiplication
     */
    Matrix3D &operator*=(const Matrix3D &other);

    /**
     * overloads the *= operator and calculates the multiplication of a matrix and a vector
     * @param v the vector to be multiplied with
     * @return a new vector which is the result of the multiplication
     */
    Vector3D operator*(const Vector3D &v);

    /**
     * overloads the * operator and calculates the multiplication of 2 matrices
     * @param other the second matrix, that to be multiplied with
     * @return a new matrix which is the result of the matrices multiplication
     */
    Matrix3D operator*(const Matrix3D &other);

    /**
     * overloads the << operator and prints out to stream the matrix values
     * @param out the stream of output
     * @param m the matrix to be outputed
     * @return out, as in the stream after output was added
     */
    friend ostream &operator<<(ostream &out, const Matrix3D &m);

    /**
     * overloads the >> operator and gets to stream the user input
     * @param in the stream of input
     * @param m the matrix to which the input should be added to
     * @return in, as in the stream after input was added
     */
    friend istream &operator>>(istream &in, Matrix3D &m);

    /**
     * overloads the [] operator allowing access to vector in matrix
     * @param i which vector in matrix to access
     * @return vector in place i
     */
    Vector3D operator[](int i) const;

    /**
     * overloads the [] operator allowing access to vector in matrix
     * @param i which vector in matrix to access
     * @return reference to vector i
     */
    Vector3D &operator[](int i);

    /**
     * verloads the = operator, copying values from other matrix to current matrix
     * @param other matrix to be copied from
     * @return pointer to this, as in current matrix after the copy was done
     */
    Matrix3D &operator=(const Matrix3D &other);

    /**
     * getting a specific row in matrix
     * @param i which row to get
     * @return a vector of said row's values
     */
    Vector3D row(short i) const;

    /**
     *
     * getting a specific column in matrix
     * @param i which column to get
     * @return a vector of said column's values
     */
    Vector3D column(short i) const;

    /**
     * calculates the trace of the matrix, as in the sum of its diagnol
     * @return the calculated trace
     */
    double trace();

    /**
     * calculates the determenant of a matrix
     * @return the calculated det
     */
    double determinant();

private:
    Vector3D _first; /** first vector in matrix */
    Vector3D _second; /** second vector in matrix */
    Vector3D _third; /** third vector in matrix */

    /**
     * helper function for calculating large determenants, this func calculates the det of matrix
     * of size 2X2
     * @param left_top top left point
     * @param right_top top right point
     * @param left_bottom bottom left point
     * @param right_bottom bottom right point
     * @return determinant by given points
     */
    double _det2X2(double left_top, double right_top, double left_bottom, double right_bottom);
};

#endif //EX1_MATRIX3D_H
