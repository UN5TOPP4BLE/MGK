//
// Created by mateu on 07.10.2022.
//

#include "Vector.h"
#include <iostream>
#include <cmath>

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

void Vector::multiply(float f) {
    this->x *= f;
    this->y *= f;
    this->z *= f;
}

void Vector::setVector(Vector v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}

float Vector::length() {
    return sqrt(this->x * this->x +
                this->y * this->y +
                this->z * this->z);
}

void Vector::normalize() {
    float l = this->length();
    if(l!=0) {
        this->multiply(1/l);
    }
    else std::cout << "Nie mozna dzielic przez 0\n";
}

void Vector::dot(Vector v1, Vector v2) {
    this->x = v1.x * v2.x;
    this->y = v1.y * v2.y;
    this->z = v1.z * v2.z;
}

void Vector::cross(Vector v1, Vector v2) {
    this->x = v1.y * v2.z - v1.z * v2.y;
    this->y = v1.z * v2.x - v1.x * v2.z;
    this->z = v1.x * v2.y - v1.y * v2.x;
}

void Vector::showSumVector() {
    std::cout<<"["<<this->x<<", "<<this->y<<", "<<this->z<<"] = "<<(float)this->x + (float)this->y + (float)this->z<<"\n";
}
