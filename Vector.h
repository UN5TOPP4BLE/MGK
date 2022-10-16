//
// Created by mateu on 07.10.2022.
//

#ifndef MGK_VECTOR_H
#define MGK_VECTOR_H


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

    void setX(float x);
    void setY(float y);
    void setZ(float z);

    ~Vector();

    void add(Vector v);
    void sub(Vector v);
    void multiply(float f);
    float length();
    void normalize();
    void dot(Vector v1, Vector v2);
    void cross(Vector v1, Vector v2);

    void setVector(float xx, float yy, float zz);
    void setVector(Vector v);
    void showVector();
    void showSumVector();
};


#endif //MGK_VECTOR_H
