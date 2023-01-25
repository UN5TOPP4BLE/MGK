//
// Created by mateu on 06.10.2022.
//

#include "Quaternion.h"
#include "Matrix.h"
#include "Vector.h"

#include <iostream>
#include <string>
#include <vector>


struct Plane {
    Vector normal, point;
};

struct Cube {
    Vector a,b,c,d,e,f,g,h;
    std::vector <Plane> planes;
};

struct Line{
    Line() : point(point), vector(vector) {}
    Line(Vector p, Vector v) : point(p), vector(v) {}
    Vector point, vector;
};

Line createLine(Vector p1, Vector p2);
Plane createPlane(Vector p1, Vector p2, Vector p3);
Cube createCube(Vector a, Vector b, Vector c, Vector d, Vector e ,Vector f, Vector g, Vector h);
double calculateTLinePlane(Line l1, Plane p1);
Vector calculateIntersectionLinePlane(const Line& l, const Plane& p);
bool checkCollisionInCube(Vector test, Cube b);
bool CubeCollisionCheck(const Cube& b, const Line& l);
Cube rotateCube(Cube Cube, double angle, const Vector& axis);





int main() {

    Vector cp1 = Vector(10,10,10);
    Vector cp2 = Vector(10, 10, -10);
    Vector cp3 = Vector(10, -10, 10);
    Vector cp4 = Vector(10, -10, -10);
    Vector cp5 = Vector(-10,10,10);
    Vector cp6 = Vector(-10,10,-10);
    Vector cp7 = Vector(-10,-10,10);
    Vector cp8 = Vector(-10,-10,-10);

    Cube c1 = createCube(cp1, cp2, cp3, cp4,cp5, cp6, cp7, cp8);

    //obrot szescianu x - pitch, y - roll, z - yaw
    struct Cube c2 = rotateCube(c1, 45, Vector(1, 0, 1));

    //tablica linii
    Line l1Array[60][60];

    int wiersz = 30;
    int nrWiersza = 30;
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            //pierwszy parametr jest odlegloscia od kamery, drugi przesuniecie prawo/lewo, trzeci przesuniecie gora/dol
            l1Array[i][j] = createLine(Vector(-500, 0, 0), Vector(30, wiersz, nrWiersza));
            wiersz--;
        }
        wiersz = 30;
        nrWiersza--;

    }

    bool cubeDrawArray[60][60];

    //sprawdzenie i ustalenie czy mamy rysowac w tym punkcie 0 lub .
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            cubeDrawArray[i][j] = CubeCollisionCheck(c2, l1Array[i][j]);
        }
    }

    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            if(cubeDrawArray[i][j])
                std::cout<<" 0";
            else
                std::cout<<" .";
        }
    }

    return 0;
}


Line createLine(Vector p1, Vector p2){
    Vector vector = p1.copy();
    vector.sub(p2);
    return {p2, vector};
}

Plane createPlane(Vector p1, Vector p2, Vector p3) {
    Vector vector1 = p1.copy();
    Vector vector2 = p2.copy();
    Vector vector3 = p3.copy();
    vector1.sub(p2);
    vector3.sub(p1);

    return {vector1.cross(vector3), p2};
}

Cube createCube(Vector a, Vector b, Vector c, Vector d, Vector e ,Vector f, Vector g, Vector h) {
    Plane front = createPlane(a, c, d);
    Plane right = createPlane(a, b, e);
    Plane back = createPlane(e, f, h);
    Plane left = createPlane(c, g, h);
    Plane down = createPlane(a, c, e);
    Plane up = createPlane(b, d, f);

    std::vector <Plane> planes;

    planes.push_back(front);
    planes.push_back(right);
    planes.push_back(back);
    planes.push_back(left);
    planes.push_back(down);
    planes.push_back(up);

    return {a, b, c, d, e, f, g, h, planes};
}

double calculateTLinePlane(Line l1, Plane p1) {
    Vector p = l1.point;
    Vector q = p1.point;
    Vector v = l1.vector;
    Vector n = p1.normal;

    Vector minusN = n.multiply(-1);
    p.sub(q);
    double numerator = minusN.dot(p);
    double divisor = n.dot(v);

    if(divisor == 0){
        throw std::invalid_argument( "divisor is equal 0" );
    }

    return numerator / divisor;

}

Vector calculateIntersectionLinePlane(const Line& l, const Plane& p) {
    try {
        double t = calculateTLinePlane(l, p);

        Vector point = l.point;
        Vector vector = l.vector;

        point.add(vector.multiply(t));
        return point;
    }
    catch (const std::invalid_argument& e) {
        return {10000, 10000, 10000};
    }
}

bool checkCollisionInCube(Vector test, Cube b) {
    Vector u = b.a.copy(); u.sub(b.e); double ux = u.dot(test);
    Vector v = b.a.copy(); v.sub(b.b); double up1 = u.dot(b.a);
    Vector w = b.a.copy(); w.sub(b.c); double up2 = u.dot(b.e);

    double vx =  v.dot(test);
    double wx =  w.dot(test);

    double vp1 = v.dot(b.a);
    double wp1 = w.dot(b.a);

    double vp4 = v.dot(b.b);
    double wp5 = w.dot(b.c);

    double maxDifferenceTolerance = 0.001;

    bool first = (up1 + maxDifferenceTolerance >= ux && ux + maxDifferenceTolerance >= up2) || (up1 <= ux + maxDifferenceTolerance && ux <= up2 + maxDifferenceTolerance);
    bool second = (vp1 + maxDifferenceTolerance >= vx && vx + maxDifferenceTolerance >= vp4) || (vp1 <= vx + maxDifferenceTolerance && vx <= vp4 + maxDifferenceTolerance);
    bool third = (wp1 + maxDifferenceTolerance >= wx && wx + maxDifferenceTolerance >= wp5) || (wp1 <= wx + maxDifferenceTolerance && wx <= wp5 + maxDifferenceTolerance);

    if (first && second && third)
        return true;
    else
        return false;
}

bool CubeCollisionCheck(const Cube& b, const Line& l) {
    Vector test = Vector(0,0,0);
    std::string temp = "";
    for (int i=0; i<6; i++) {
        test = calculateIntersectionLinePlane(l, b.planes.at(i));
        if(!test.isEqual(Vector(10000,10000,10000))) {
            if(checkCollisionInCube(test, b)) {

                return true;
            }
        }
    }
    return false;
}


Cube rotateCube(Cube Cube, double angle, const Vector& axis) {
    Vector a = Quaternion::rotate(Cube.a, angle, axis);
    Vector b = Quaternion::rotate(Cube.b, angle, axis);
    Vector c = Quaternion::rotate(Cube.c, angle, axis);
    Vector d = Quaternion::rotate(Cube.d, angle, axis);
    Vector e = Quaternion::rotate(Cube.e, angle, axis);
    Vector f = Quaternion::rotate(Cube.f, angle, axis);
    Vector g = Quaternion::rotate(Cube.g, angle, axis);
    Vector h = Quaternion::rotate(Cube.h, angle, axis);

    Plane acd = createPlane(a, c, d);
    Plane abe = createPlane(a, b, e);
    Plane efh = createPlane(e, f, h);
    Plane cgh = createPlane(c, g, h);
    Plane ace = createPlane(a, c, e);
    Plane bdf = createPlane(b, d, f);
    
    std::vector <Plane> planes;
    planes.push_back(acd);
    planes.push_back(abe);
    planes.push_back(efh);
    planes.push_back(cgh);
    planes.push_back(ace);
    planes.push_back(bdf);
    return {a,b,c,d,e,f,g,h,planes};
}