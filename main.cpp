//
// Created by mateu on 06.10.2022.
//

#include <string>
#include <iostream>
#include "Vector.h"
#include "Matrix4x4.h"
#include <cmath>
#include "Quaternion.h"

//float vectorAngle(Vector v1, Vector v2) {
//    Vector c(0, 0, 0);
//    c.dot(v1, v2);
//
//    float licznik = c.getX() + c.getY() + c.getZ();
//    float mianownik = std::abs(v1.length() * v2.length());
//    return acos(licznik / mianownik) * (180 / M_PI);
//}

Vector rotatePoint(Quaternion q1, Vector v1, Vector axisV, double angle) {
    q1.rotationQuaternion(v1, angle);
    q1.inverse();
    Vector v2 = Quaternion::rotate(v1, axisV, angle);
    return v2;
}

int main() {

    Quaternion q1 = Quaternion(1, 2, 3, 4);
    std::cout << "Q1: ";
    q1.show();

    Quaternion q2 = Quaternion(2, 3, 4, 5);
    std::cout << "Q2: ";
    q2.show();

    Quaternion q0 = Quaternion(0, 0, 0, 0);

    //dodawanie
    std::cout << "Q1 + Q2:  ";
    q0.add(q1);
    q0.add(q2);
    q0.show();

    //odejmowanie
    std::cout << "Q2 - Q1:  ";
    q0.set(0, 0, 0, 0);
    q0.add(q2);
    q0.sub(q1);
    q0.show();

    //mnozenie
    std::cout << "Q1 * Q2:  ";
    q0 = q1.multiply(q2);
    q0.show();
    std::cout << "Q2 * Q1:  ";
    q0 = q2.multiply(q1);
    q0.show();

    //dzielenie
    std::cout << "Q1 / Q2:  ";
    q0 = q1.divide(q2);
    q0.show();
    std::cout << "Q2 / Q1:  ";
    q0 = q2.divide(q1);
    q0.show();

    //obrot punktu [-1,-1,-1] wokol osi X o 270 stopni
    q0.set(0, 0, 0, 0);
    Vector v1 = Vector(-1, -1, -1);
    Vector axis = Vector(1, 0, 0);
    Vector v2 = rotatePoint(q0, v1, axis, 270);
    v1.show();
    std::cout << " obrocony o 270 stopni wokol osi X ma wspolrzedne  ";
    v2.show();



    return 0;


//
//    Matrix4x4 m00(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
//    Matrix4x4 m01(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
//    Matrix4x4 m02(-16, -15, -14, -13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1);
//    Matrix4x4 m03(1, 2, 3, 4, 2, 3, 1, 2, 1, 1, 1, -1, 1, 0, -2, -6);
//
//    std::cout << "M01: \n";
//    m01.show();
//    std::cout << "M02: \n";
//    m02.show();
//    std::cout << "M03: \n";
//    m03.show();
//
//    std::cout << "M01 + MO2 = \n";
//    m01.add(m02);
//    m01.show();
//
//    std::cout << "M01 - MO2 = \n";
//    m01.sub(m02);
//    m01.show();
//
//    std::cout << "M01 * 3.25 = \n";
//    m01.multiply(3.25);
//    m01.show();
//
//    std::cout << "M01 / 1.625 = \n";
//    m01.multiply(1 / 1.625);
//    m01.show();
//
//    std::cout << "M01 * M02 = \n";
//    Matrix4x4 m01copy(m01);
//    m01copy.multiply(m01, m02);
//    m01copy.show();
//
//    std::cout << "M01 * M02 = \n";
//    Matrix4x4 m02copy(m02);
//    m02copy.multiply(m02, m01);
//    m02copy.show();
//
//    std::cout << "M01 jako macierz jednostkowa: \n";
//    m01.identity();
//    m01.show();
//
//    std::cout << "M02 jako macierz transponowana: \n";
//    m02.trans(m02);
//    m02.show();
//
//    std::cout << "Wyznacznik macierzy M03: \n";
//    std::cout << m03.det() << "\n\n";
//
//    std::cout << "M03 jako macierz odwrotna: \n";
//    m03.inverse();
//    m03.show();
//
//    std::cout << "Translacja macierzy M01 o wektor [3,8,-25]: \n";
//    m01.translate(3,8,-25);
//    m01.show();
//
//    std::cout << "Przeskalowanie macierzy M01 na [3.5,0.01,-999]: \n";
//    m01.scale(3.5, 0.01, -999);
//    m01.show();
//
//
//    //ZADANIA KONTROLNE
//
//    std::cout<<"\n\n";
//    std::cout<<"Wektor [1,0,0,1] obroc o 90 stopni wokol osi Y\n";
//    Matrix4x4 m05(1,0,0,1);
//    Matrix4x4 mRot(m05);
//    mRot.createRotation('y', 90);
//    m05.multiply(mRot,m05);
//    m05.showVector();
//
//
//
//
//
//

//ZADANIE 1 - WEKTORY
//------------------------------------------------
//    //tworzenie wektora A
//    Vector a(1,2,3);
//    std::cout<<"Wektor A: ";
//    a.showVector();
//
//    //tworzenie wektora B
//    Vector b(4,5,6);
//    std::cout<<"Wektor B: ";
//    b.showVector();
//
//    //dodawanie
//    Vector c(0,0,0);
//    std::cout<<"C = A + B: ";
//    c.add(a);
//    c.add(b);
//    c.showVector();
//
//    //dodawanie odwrotna kolejnosc
//    c.setVector(0,0,0);
//    std::cout<<"C = B + A: ";
//    c.add(b);
//    c.add(a);
//    c.showVector();
//
//    //odejmowanie
//    c.setVector(a);
//    c.sub(b);
//    std::cout<<"C = A - B: ";
//    c.showVector();
//
//    //odejmowanie odwrotna kolejnosc
//    c.setVector(b);
//    c.sub(a);
//    std::cout<<"C = B - A: ";
//    c.showVector();
//
//    //mnozenie przez liczbe
//    c.setVector(a);
//    c.multiply(2.5);
//    std::cout<<"C = A * 2.5: ";
//    c.showVector();
//
//    c.setVector(a);
//    c.multiply(0.3);
//    std::cout<<"C = A * 0.3: ";
//    c.showVector();
//
//    c.setVector(a);
//    c.multiply(-5);
//    std::cout<<"C = A * -5: ";
//    c.showVector();
//
//    //dlugosc wektorow
//    std::cout<<"Length of A: "<<a.length()<<"\n";
//    std::cout<<"Length of B: "<<b.length()<<"\n";
//
//    //normalizowanie wektora
//    c.setVector(a);
//    c.normalize();
//    std::cout<<"Normalized A: ";
//    c.showVector();
//
//    //iloczyn skalarny
//    c.dot(a,b);
//    std::cout<<"C = A * B: ";
//    c.showSumVector();
//
//    //iloczyn wektorowy
//    c.cross(a,b);
//    std::cout<<"C = A x B: ";
//    c.showVector();
//
//    //kat pomiedzy wektorami
//    std::cout<<"Kat pomiedzy A i B: "<<vectorAngle(a,b)<<" stopni\n\n\n";
//
//
//
//    //podpunkt 3 z zadania
//    std::cout<<"Znajdz kat pomiedzy wektorami:\n";
//    a.setVector(0,3,0); std::cout<<"Wektor A: "; a.showVector();
//    b.setVector(5,5,0); std::cout<<"Wektor B: "; b.showVector();
//
//    std::cout<<"Kat pomiedzy A i B: "<<vectorAngle(a,b)<<" stopni\n\n";
//
//    //podpunkt 4 z zadania
//    std::cout<<"Znajdz wektor prostopadly do wektorow [4,5,1] i [4,1,3]\n";
//    a.setVector(4,5,1);
//    b.setVector(4,1,3);
//    c.cross(a,b);
//    std::cout<<"Wektor prostopadly ma wartosci "; c.showVector();
//
//    c.normalize();
//    std::cout<<"Wektor znormalizowany: "; c.showVector();

    return 0;
}