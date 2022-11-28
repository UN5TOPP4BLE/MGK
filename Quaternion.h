//
// Created by mateu on 28.11.2022.
//

#ifndef MGK_QUATERNION_H
#define MGK_QUATERNION_H

#include "Vector.h"
#include <string>

class Quaternion {
private:
    double a;
    Vector v;

public:
    Quaternion(double a, const Vector &v);

    Quaternion(double a, double x, double y, double z);

    virtual ~Quaternion();

    double getA() const;

    double getX() const;

    double getY() const;

    double getZ() const;

    void setA(double a1);

    void set(double a1, double x1, double y1, double z1);

    void show();

    void add(Quaternion q1);

    void sub(Quaternion q1);

    Quaternion multiply(const Quaternion &q1);

    Quaternion divide(const Quaternion &q1);

    void rotationQuaternion(const Vector &os, double angle);

    void inverse();

    static Vector rotate(Vector v1, const Vector &os, double angle);


};

#endif //MGK_QUATERNION_H
