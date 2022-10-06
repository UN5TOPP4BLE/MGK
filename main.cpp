//
// Created by mateu on 06.10.2022.
//

#include <string>
#include <iostream>



class Vector
{
public:
   float x=0.0,y=0.0,z=0.0;

    Vector();

    Vector(float x, float y, float z);

    Vector(Vector p1, Vector p2);

    float getX() const;

    float getY() const;

    float getZ() const;

    ~Vector();

    void add(Vector v);
    void sub(Vector v);

    void showVector();
};

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


int main()
{
    std::cout<<"Hello world "<<std::endl;

    Vector a(1.0,2.0,3.0);
    a.showVector();

    Vector b(4.0,5.0,6.0);
    b.showVector();

    a.add(b);
    a.showVector();

    a.sub(b);
    a.showVector();

    return 0;
}