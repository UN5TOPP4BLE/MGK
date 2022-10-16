//
// Created by mateu on 06.10.2022.
//

#include <string>
#include <iostream>
#include "Vector.h"
#include <cmath>

float vectorAngle(Vector v1, Vector v2) {
    Vector c(0,0,0);
    c.dot(v1, v2);

    float licznik = c.getX()+c.getY()+c.getZ();
    float mianownik = std::abs(v1.length() * v2.length());
    return acos(licznik/mianownik) * (180/M_PI);
}


int main()
{
    //tworzenie wektora A
    Vector a(1,2,3);
    std::cout<<"Wektor A: ";
    a.showVector();

    //tworzenie wektora B
    Vector b(4,5,6);
    std::cout<<"Wektor B: ";
    b.showVector();

    //dodawanie
    Vector c(0,0,0);
    std::cout<<"C = A + B: ";
    c.add(a);
    c.add(b);
    c.showVector();

    //dodawanie odwrotna kolejnosc
    c.setVector(0,0,0);
    std::cout<<"C = B + A: ";
    c.add(b);
    c.add(a);
    c.showVector();

    //odejmowanie
    c.setVector(a);
    c.sub(b);
    std::cout<<"C = A - B: ";
    c.showVector();

    //odejmowanie odwrotna kolejnosc
    c.setVector(b);
    c.sub(a);
    std::cout<<"C = B - A: ";
    c.showVector();

    //mnozenie przez liczbe
    c.setVector(a);
    c.multiply(2.5);
    std::cout<<"C = A * 2.5: ";
    c.showVector();

    c.setVector(a);
    c.multiply(0.3);
    std::cout<<"C = A * 0.3: ";
    c.showVector();

    c.setVector(a);
    c.multiply(-5);
    std::cout<<"C = A * -5: ";
    c.showVector();

    //dlugosc wektorow
    std::cout<<"Length of A: "<<a.length()<<"\n";
    std::cout<<"Length of B: "<<b.length()<<"\n";

    //normalizowanie wektora
    c.setVector(a);
    c.normalize();
    std::cout<<"Normalized A: ";
    c.showVector();

    //iloczyn skalarny
    c.dot(a,b);
    std::cout<<"C = A * B: ";
    c.showSumVector();

    //iloczyn wektorowy
    c.cross(a,b);
    std::cout<<"C = A x B: ";
    c.showVector();

    //kat pomiedzy wektorami
    std::cout<<"Kat pomiedzy A i B: "<<vectorAngle(a,b)<<" stopni\n\n\n";



    //podpunkt 3 z zadania
    std::cout<<"Znajdz kat pomiedzy wektorami:\n";
    a.setVector(0,3,0); std::cout<<"Wektor A: "; a.showVector();
    b.setVector(5,5,0); std::cout<<"Wektor B: "; b.showVector();

    std::cout<<"Kat pomiedzy A i B: "<<vectorAngle(a,b)<<" stopni\n\n";

    //podpunkt 4 z zadania
    std::cout<<"Znajdz wektor prostopadly do wektorow [4,5,1] i [4,1,3]\n";
    a.setVector(4,5,1);
    b.setVector(4,1,3);
    c.cross(a,b);
    std::cout<<"Wektor prostopadly ma wartosci "; c.showVector();

    c.normalize();
    std::cout<<"Wektor znormalizowany: "; c.showVector();

    return 0;
}