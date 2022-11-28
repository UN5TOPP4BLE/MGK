//
// Created by mateu on 07.10.2022.
//

#ifndef MGK_VECTOR_H
#define MGK_VECTOR_H


#include <string>

class Vector {

private:
    double x, y, z, w;

public:
    Vector(double x, double y, double z);

    Vector(double x, double y, double z, double w);

    virtual ~Vector();

    double getX() const;

    double getY() const;

    double getZ() const;

    double getW() const;

    void show();

    void set(double x1, double y1, double z1, double w1);

    void add(const Vector &v1);

    void sub(const Vector &v1);

    Vector multiply(double a) const;

    double dot(const Vector &v1) const;

    Vector cross(const Vector &v1) const;

    Vector normalise() const;

    bool isEqual(const Vector &v1) const;

    double length() const;

    double angle(const Vector &v1) const;

};


#endif //MGK_VECTOR_H
