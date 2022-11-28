//
// Created by mateu on 28.11.2022.
//

#include "Quaternion.h"
#include <cmath>
#include <iostream>

Quaternion::Quaternion(double a, const Vector &v) : a(a), v(v) {}

Quaternion::Quaternion(double a, double x, double y, double z) : a(a), v(Vector(x, y, z)) {}

Quaternion::~Quaternion() {

}

void Quaternion::show() {
    std::string s[3] = {" + ", " + ", " + "};

    if (v.getX() < 0.0) s[0] = " - ";
    if (v.getY() < 0.0) s[1] = " - ";
    if (v.getZ() < 0.0) s[2] = " - ";

    std::cout << a << s[0] << std::abs(v.getX()) << "i" <<
              s[1] << std::abs(v.getY()) << "j"
              << s[2] << std::abs(v.getZ()) << "k\n\n";

}

void Quaternion::set(double a1, double x1, double y1, double z1) {
    Vector v2 = Vector(x1, y1, z1);
    this->a = a1;
    this->v = v2;
}

void Quaternion::add(Quaternion q1) {
    this->a += q1.a;
    this->v.add(q1.v);
}

void Quaternion::sub(Quaternion q1) {
    this->a -= q1.a;
    this->v.sub(q1.v);
}

Quaternion Quaternion::multiply(const Quaternion &q1) {
    double t1 = this->a * q1.a - this->v.dot(q1.v);

    Vector t2 = q1.v.multiply(this->a);
    t2.add(this->v.multiply(q1.a));
    t2.add(this->v.cross(q1.v));

    return {t1, t2};
}

Quaternion Quaternion::divide(const Quaternion &q1) {
    double a1 = this->a;
    Vector v1 = this->v;

    double a2 = q1.a;
    Vector v2 = q1.v;

    double mianownik = a2 * a2 + v2.dot(v2);

    if (mianownik == 0) std::cout << "Mianownik jest rowny 0";
    else {

        double licznik = a1 * a2 + v1.dot(v2);

        licznik /= mianownik;

        Vector v3 = v2.multiply(a1);
        Vector v4 = v1.multiply(a2);
        Vector v5 = v1.cross(v2);
        v4.sub(v3);
        v4.sub(v5);

        return {licznik, v4.multiply(1 / mianownik)};
    }
}


void Quaternion::rotationQuaternion(const Vector &os, double angle) {
    double fP = cos(M_PI * angle / 360.0);
    double a = os.getX(), b = os.getY(), c = os.getZ();

    double multiplier = sin(M_PI * angle / 360.0) / sqrt(a * a + b * b + c * c);

    this->a = fP;
    this->v = os.multiply(multiplier);

}

void Quaternion::inverse() {
    Vector v = this->v;
    this->v = v.multiply(-1);
}

Vector Quaternion::rotate(Vector v1, const Vector &os, double angle) {
    Quaternion q1 = Quaternion(0, 0, 0, 0);
    q1.rotationQuaternion(os, angle);

    Quaternion q2 = q1;
    q2.inverse();

    Quaternion q3 = Quaternion(0, v1);

    Quaternion q4 = q1.multiply(q3);
    Quaternion q5 = q4.multiply(q2);

    return {q5.v};
}

double Quaternion::getA() const {
    return a;
}

double Quaternion::getX() const {
    return v.getX();
}

double Quaternion::getY() const {
    return v.getY();
}

double Quaternion::getZ() const {
    return v.getZ();
}

void Quaternion::setA(double a1) {
    this->a = a1;
}