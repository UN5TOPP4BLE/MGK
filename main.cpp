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

struct Line{
    Vector vector;
    Vector point;
};

struct Plane {
    Vector normal;
    Vector point;
};

struct Sphere {
    Vector center;
    double radius;
};

struct Segment {
    Vector A;
    Vector B;
};

Line createLine(Vector p1, Vector p2);
Plane createPlane(Vector p1, Vector p2, Vector p3);
double lineLine(Line l1, Line l2);
double linePlane(Line l1, Plane p1);
Vector intersectionPointFromTwoLines(const Line& l1, const Line& l2);
Vector intersectionPointBetweenTwoPoints(const Segment& s1, const Segment& s2);
Line createLine(Vector p1, Vector p2);
Vector intersectionBetweenLineAndPlane(const Line& l, const Plane& p);
Line lineBetweenTwoPlanes(const Plane& p1, const Plane& p2, double x1, double y1, double z1, double w1, double x2, double y2, double z2, double w2);
void intersectionSphere(const Line& l, const Sphere& s);




int main() {


    //zadanie 1
    Line l1 = createLine(Vector(-2, 4, 0), Vector(1, 5, 5));
    Line l2 = createLine(Vector(-2, 4, 0), Vector(-1, -1, 3));
    Vector v1 = intersectionPointFromTwoLines(l1, l2);
    std::cout<<"Zadanie 1 - znajdz punkt przeciecia prostych: ";
    v1.show();

    //zadanie 2
    double a1 = l1.vector.angle(l2.vector);
    std::cout << "\nZadanie 2 - znajdz kat miedzy prostymi z zadania 1: " << a1;

    //zadanie 3
    Line l3 = createLine(Vector(-2, 2, -1), Vector(1, 1, 1));
    Plane p1 = createPlane(Vector(4, 0, 0), Vector(1, 0, 2), Vector(1, 2, 0));
    Vector v2 = intersectionBetweenLineAndPlane(l3, p1);
    std::cout<<"\nZadanie 3 - znajdz punkt przeciecia miedzy prosta a plaszczyzna: ";
    v2.show();

    //zadanie 4
    double a2 = l3.vector.angle(p1.normal);
    std::cout << "\nZadanie 4 - znajdz kat miedzy prosta a plaszczyzna z zadania 2: " << 180 - a2 << " stopni";

    //zadanie 5
    Plane p2 = createPlane(Vector(4, 0, 0), Vector(0, -8, 0), Vector(0, 0, 8));
    Plane p3 = createPlane(Vector(0, 0, -14), Vector(0, -3, -5), Vector(-3, 0, -2));
    Line intersectionLine = lineBetweenTwoPlanes(p2, p3, 2, -1, 1, -8, 4, 3, 1, 14); //
    Vector v3 = intersectionLine.point;
    Vector v4 = intersectionLine.vector;
    std::cout<<"\nZadanie 5 - znajdz prosta przeciecia plaszczyzn: ";
    std::cout<<"\npunkt: "; v3.show();
    std::cout<<"\nwektor: "; v4.show();



    //zadanie 6
    double a3 = p2.normal.calculateAngle(p1.normal);
    std::cout << "\nZadanie 6 - znajdz kat miedzy plaszczyznami z zadania 5: " << a3 << " stopni";

    //zadanie 7
    Segment s1 = {Vector(5, 5, 4), Vector(10, 10, 6)};
    Segment s2 = {Vector(5, 5, 5), Vector(10, 10, 3)};
    Vector v5 = intersectionPointBetweenTwoPoints(s1, s2);
    std::cout<<"\nZadanie 7 - znajdz punkt przeciecia dwoch odcinkow opisanych punktami: ";
    v5.show();

    //zadanie 8
    Line l4 = createLine(Vector(5, 3, -4), Vector(3, -1, -2));
    Sphere sphere1 = {Vector(0,0,0), sqrt(26.0)};
    std::cout<<"\nZadanie 8 - znajdz punkt przeciecia sfery: ";
    intersectionSphere(l4, sphere1);

    return 0;
}


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

Plane createPlane(Vector p1, Vector p2, Vector p3) {
    Vector vector1 = p1.copy();
    Vector vector2 = p2.copy();
    Vector vector3 = p3.copy();

    vector1.sub(p2);
    vector3.sub(p1);

    return {vector1.cross(vector3), p2};
}

double lineLine(Line l1, Line l2) {
    Vector p1 = l1.point;
    Vector p2 = l2.point;
    Vector v1 = l1.vector;
    Vector v2 = l2.vector;

    p2.sub(p1);
    Vector p2xv2 = p2.cross(v2);
    Vector v1xv2 = v1.cross(v2);
    double numerator = p2xv2.dot(v1xv2);
    double v1xv2len = pow(v1xv2.length(), 2);
    return numerator / v1xv2len;
}

Vector intersectionPointFromTwoLines(const Line& l1, const Line& l2) {
    double t1 = lineLine(l1, l2);
    double t2 = lineLine(l2, l1);
    Vector p1 = l1.point;
    Vector v1 = l1.vector;
    Vector point1 = p1;

    point1.add(v1.multiply(t1));

    Vector point2 = l2.point;
    Vector v2 = l2.vector;
    point2.add(v2.multiply(t2));

    Vector n = point2;
    n.sub(point1);

    if(n.isEqual(Vector(0,0,0))){
        return point1;
    }

}

Vector intersectionPointBetweenTwoPoints(const Segment& s1, const Segment& s2) {
    Line l1 = createLine(s1.A, s1.B);
    Line l2 = createLine(s2.A, s2.B);

    Vector p = intersectionPointFromTwoLines(l1, l2);

    if( p.getX() >= s1.A.getX() && p.getX() <= s1.B.getX() &&
        p.getY() >= s1.A.getY() && p.getY() <= s1.B.getY() &&
        p.getZ() >= s1.A.getZ() && p.getZ() <= s1.B.getZ() &&
        p.getX() >= s2.A.getX() && p.getX() <= s2.B.getX() &&
        p.getY() >= s2.A.getY() && p.getY() <= s2.B.getY() &&
        p.getZ() >= s2.A.getZ() && p.getZ() <= s2.B.getZ())
        return p;
}


double linePlane(Line l1, Plane p1) {
    Vector p = l1.point;
    Vector q = p1.point;
    Vector v = l1.vector;
    Vector n = p1.normal;

    Vector minusN = n.multiply(-1);
    p.sub(q);
    double numerator = minusN.dot(p);
    double divisor = n.dot(v);

    return numerator / divisor;
}

Line createLine(Vector p1, Vector p2){
    Vector vector = p1.copy();
    vector.sub(p2);

    return {vector, p2};
}



Vector intersectionBetweenLineAndPlane(const Line& l, const Plane& p) {
    double t = linePlane(l, p);

    Vector point = l.point;
    Vector vector = l.vector;

    point.add(vector.multiply(t));
    return point;
}

Line lineBetweenTwoPlanes(const Plane& p1, const Plane& p2, double x1 = 2, double y1 = -1, double z1 = 1, double w1 = -8,
                          double x2 = 4, double y2 = 3, double z2 = 1, double w2 = 14){
    Vector q1 = p1.point;
    Vector q2 = p2.point;
    Vector n1 = p1.normal;
    Vector n2 = p2.normal;

    Vector n3 = n1.cross(n2);

    double x = 0;
    double z = ((y2/y1)*w1 -w2)/(z2 - z1*y2/y1);
    double y = (-z1*z -w1) / y1;

    n3.set(n3.getX()/288, n3.getY()/288, n3.getZ()/288, 0);

    return {n3, Vector(z,y,z)};

}

void intersectionSphere(const Line& l, const Sphere& s) {
    Vector v = l.vector;
    Vector e = l.point;
    Vector center = s.center;
    double r = s.radius;
    Vector e_c = e;
    e_c.sub(center);

    double a = pow(v.length(), 2);
    double b = 2 * e_c.dot(v);
    double c = pow(e_c.length(),2) - r*r;

    double delta = b * b - 4 * a * c;
    double t1, t2;

    if (delta > 0) {
        t1 = (-b + sqrt(delta)) / (2 * a);
        t2 = (-b - sqrt(delta)) / (2 * a);

        Vector point1 = l.point;
        Vector point2 = l.point;
        Vector vector = l.vector;
        point1.add(vector.multiply(t1));
        point2.add(vector.multiply(t2));

        std::cout<<"\npunkt 1: "; point1.show();
        std::cout<<"\npunkt 2: "; point2.show();
    }
    else if(delta == 0) {
        t1 = -b/(2*a);
        Vector point = l.point;
        Vector vector = l.vector;

        point.add(vector.multiply(t1));
        std::cout<<"\npunkt 1: "; point.show();
    }
    else {
        std::cout<<"\nbrak punktow";
    }
}