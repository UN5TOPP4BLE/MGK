//
// Created by mateu on 06.10.2022.
//

#include <string>
#include <iostream>
#include "Vector.h"



int main()
{
    Vector a(1.0,2.0,3.0);
    std::cout<<"Wektor A: ";
    a.showVector();

    Vector b(4.0,5.0,6.0);
    std::cout<<"Wektor B: ";
    b.showVector();

    Vector c(0,0,0);
    std::cout<<"C = A + B: ";
    c.add(a);
    c.add(b);
    c.showVector();

    c.setVector(0,0,0);
    std::cout<<"C = B + A: ";
    c.add(b);
    c.add(a);
    c.showVector();

    c.setVector(a);
    c.sub(b);
    std::cout<<"C = A - B: ";
    c.showVector();

    c.setVector(b);
    c.sub(a);
    std::cout<<"C = B - A: ";
    c.showVector();

    c.setVector(a);
    c.dot(2.5);
    std::cout<<"C = A * 2.5: ";
    c.showVector();

    c.setVector(a);
    c.dot(0.3);
    std::cout<<"C = A * 0.3: ";
    c.showVector();

    c.setVector(a);
    c.dot(-5);
    std::cout<<"C = A * -5: ";
    c.showVector();

    return 0;
}