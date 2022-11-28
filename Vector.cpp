//
// Created by mateu on 07.10.2022.
//

#include "Vector.h"
#include <iostream>
#include <cmath>

Vector::Vector(double x, double y, double z) : x(x), y(y), z(z), w(0) {}

Vector::Vector(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}

Vector::~Vector() = default;

void Vector::set(double x1, double y1, double z1, double w1) {
    this->x = x1;
    this->y = y1;
    this->z = z1;
    this->w = w1;
}

void Vector::show() {
    std::cout << "[" << this->x << ", " << this->y << ", " << this->z << "]";
}

Vector Vector::normalise() const {
    double mianownik = this->length();
    if (mianownik != 0.0) return {x / mianownik, y / mianownik, z / mianownik, w / mianownik};
}

double Vector::getX() const {
    return x;
}

double Vector::getY() const {
    return y;
}

double Vector::getZ() const {
    return z;
}

double Vector::getW() const {
    return w;
}


void Vector::add(const Vector &v1) {
    x += v1.x;
    y += v1.y;
    z += v1.z;
    w += v1.w;
}

void Vector::sub(const Vector &v1) {
    x -= v1.x;
    y -= v1.y;
    z -= v1.z;
    w -= v1.w;
}

Vector Vector::multiply(double a) const {
    return {a * x, a * y, a * z, a * w};
}

double Vector::dot(const Vector &v1) const {
    return x * v1.x + y * v1.y + z * v1.z + w * v1.w;
}

Vector Vector::cross(const Vector &v1) const {
    //w musi byc rowne 0
    if (v1.getW() == 0 && w == 0) {
        return {y * v1.z - z * v1.y, z * v1.x - x * v1.z, x * v1.y - y * v1.x, 0};
    } else std::cout << "W rozne od 0!\n";
}

double Vector::angle(const Vector &v1) const {
    return acos(this->dot(v1) / (this->length() * v1.length())) * 180 / M_PI;
}

double Vector::length() const {
    return sqrt(x * x + y * y + z * z + w * w);
}

bool Vector::isEqual(const Vector &v1) const {
    //czy ktorakolwiek wartosc jest inna
    if (x != v1.x || y != v1.y || z != v1.z || w != v1.w) return false;
    else return true;
}


