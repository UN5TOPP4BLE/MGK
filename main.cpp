//
// Created by mateu on 06.10.2022.
//

#include <string>
#include <iostream>
#include "Vector.h"



int main()
{
    std::cout<<"Hello world "<<std::endl;

    Vector a(1.0,2.0,3.0);
    std::cout<<"Wektor A: ";
    a.showVector();

    Vector b(4.0,5.0,6.0);
    std::cout<<"Wektor B: ";
    b.showVector();

    a.add(b);
    a.showVector();

    a.sub(b);
    a.showVector();

    return 0;
}