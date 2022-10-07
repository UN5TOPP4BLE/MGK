//
// Created by mateu on 07.10.2022.
//

#include "Vector.h"
#include <iostream>

void Vector::add(Vector v)
{
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
}

void Vector::sub(Vector v)
{
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
}

Vector::Vector() {

}

Vector::Vector(Vector p1, Vector p2) {

}


Vector::~Vector() {

}

float Vector::getX() const {
    return x;
}

float Vector::getY() const {
    return y;
}

float Vector::getZ() const {
    return z;
}

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) {}

void Vector::showVector() {
    std::cout<<"["<<this->x<<", "<<this->y<<", "<<this->z<<"]\n";
}

void Vector::setX(float x) {
    Vector::x = x;
}

void Vector::setY(float y) {
    Vector::y = y;
}

void Vector::setZ(float z) {
    Vector::z = z;
}

void Vector::setVector(float xx, float yy, float zz) {
    this->x = xx;
    this->y = yy;
    this->z = zz;
}

void Vector::dot(float f) {
    this->x *= f;
    this->y *= f;
    this->z *= f;
}

void Vector::setVector(Vector v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}
