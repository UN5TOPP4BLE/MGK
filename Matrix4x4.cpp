//
// Created by mateu on 08.11.2022.
//

#include <cstring>
#include <iostream>
#include "Matrix4x4.h"

Matrix4x4::Matrix4x4() {

}

Matrix4x4::Matrix4x4(float e0, float e1, float e2, float e3, float e4, float e5, float e6, float e7, float e8, float e9,
                     float e10, float e11, float e12, float e13, float e14, float e15) {
    entries[0] = e0;
    entries[1] = e1;
    entries[2] = e2;
    entries[3] = e3;
    entries[4] = e4;
    entries[5] = e5;
    entries[6] = e6;
    entries[7] = e7;
    entries[8] = e8;
    entries[9] = e9;
    entries[10] = e10;
    entries[11] = e11;
    entries[12] = e12;
    entries[13] = e13;
    entries[14] = e14;
    entries[15] = e15;
}

Matrix4x4::Matrix4x4(const float *f) {
    memcpy(entries, f, 16 * sizeof(float));
}

Matrix4x4::Matrix4x4(const Matrix4x4 &mat) {
    memcpy(entries, mat.entries, 16 * sizeof(float));
}

Matrix4x4::~Matrix4x4() {

}

void Matrix4x4::set(int e, float value) {
    this->entries[e] = value;
}

void Matrix4x4::show() {
    std::cout << "| " << this->entries[0] << ", " << this->entries[1] << ", " << this->entries[2] << ", "
              << this->entries[3] << " |\n";
    std::cout << "| " << this->entries[4] << ", " << this->entries[5] << ", " << this->entries[6] << ", "
              << this->entries[7] << " |\n";
    std::cout << "| " << this->entries[8] << ", " << this->entries[9] << ", " << this->entries[10] << ", "
              << this->entries[11] << " |\n";
    std::cout << "| " << this->entries[12] << ", " << this->entries[13] << ", " << this->entries[14] << ", "
              << this->entries[15] << " |\n";

}

void Matrix4x4::add(const Matrix4x4& matrix2) {
    for (int i = 0; i < 16; i++) {
        this->entries[i] = this->entries[i] + matrix2.entries[i];
    }
}

void Matrix4x4::sub(const Matrix4x4& m2) {
    for (int i = 0; i < 16; i++) {
        this->entries[i] = this->entries[i] - m2.entries[i];
    }
}

void Matrix4x4::multiply(const float value) {
    for (int i = 0; i < 16; i++) {
        this->entries[i] *= value;
    }
}

void Matrix4x4::multiply(Matrix4x4 m1, Matrix4x4 m2) {
    this->entries[0] = m1.entries[0] * m2.entries[0] + m1.entries[1] * m2.entries[4] + m1.entries[2] * m2.entries[8] +
                       m1.entries[3] * m2.entries[12];
    this->entries[1] = m1.entries[0] * m2.entries[1] + m1.entries[1] * m2.entries[5] + m1.entries[2] * m2.entries[9] +
                       m1.entries[3] * m2.entries[13];
    this->entries[2] = m1.entries[0] * m2.entries[2] + m1.entries[1] * m2.entries[6] + m1.entries[2] * m2.entries[10] +
                       m1.entries[3] * m2.entries[14];
    this->entries[3] = m1.entries[0] * m2.entries[3] + m1.entries[1] * m2.entries[7] + m1.entries[2] * m2.entries[11] +
                       m1.entries[3] * m2.entries[15];

    this->entries[4] = m1.entries[4] * m2.entries[0] + m1.entries[5] * m2.entries[4] + m1.entries[6] * m2.entries[8] +
                       m1.entries[7] * m2.entries[12];
    this->entries[5] = m1.entries[4] * m2.entries[1] + m1.entries[5] * m2.entries[5] + m1.entries[6] * m2.entries[9] +
                       m1.entries[7] * m2.entries[13];
    this->entries[6] = m1.entries[4] * m2.entries[2] + m1.entries[5] * m2.entries[6] + m1.entries[6] * m2.entries[10] +
                       m1.entries[7] * m2.entries[14];
    this->entries[7] = m1.entries[4] * m2.entries[3] + m1.entries[5] * m2.entries[7] + m1.entries[6] * m2.entries[11] +
                       m1.entries[7] * m2.entries[15];

    this->entries[8] = m1.entries[8] * m2.entries[0] + m1.entries[9] * m2.entries[4] + m1.entries[10] * m2.entries[8] +
                       m1.entries[11] * m2.entries[12];
    this->entries[9] = m1.entries[8] * m2.entries[1] + m1.entries[9] * m2.entries[5] + m1.entries[10] * m2.entries[9] +
                       m1.entries[11] * m2.entries[13];
    this->entries[10] =
            m1.entries[8] * m2.entries[2] + m1.entries[9] * m2.entries[6] + m1.entries[10] * m2.entries[10] +
            m1.entries[11] * m2.entries[14];
    this->entries[11] =
            m1.entries[8] * m2.entries[3] + m1.entries[9] * m2.entries[7] + m1.entries[10] * m2.entries[11] +
            m1.entries[11] * m2.entries[15];

    this->entries[12] =
            m1.entries[12] * m2.entries[0] + m1.entries[13] * m2.entries[4] + m1.entries[14] * m2.entries[8] +
            m1.entries[15] * m2.entries[12];
    this->entries[13] =
            m1.entries[12] * m2.entries[1] + m1.entries[13] * m2.entries[5] + m1.entries[14] * m2.entries[9] +
            m1.entries[15] * m2.entries[13];
    this->entries[14] =
            m1.entries[12] * m2.entries[2] + m1.entries[13] * m2.entries[6] + m1.entries[14] * m2.entries[10] +
            m1.entries[15] * m2.entries[14];
    this->entries[15] =
            m1.entries[12] * m2.entries[3] + m1.entries[13] * m2.entries[7] + m1.entries[14] * m2.entries[11] +
            m1.entries[15] * m2.entries[15];
}

void Matrix4x4::identity() {
    memset(entries, 0, 16 * sizeof(float));
    this->entries[0] = 1.0;
    this->entries[5] = 1.0;
    this->entries[10] = 1.0;
    this->entries[15] = 1.0;

}

void Matrix4x4::trans(Matrix4x4 m1) {

    this->entries[1] = m1.entries[4];
    this->entries[2] = m1.entries[8];
    this->entries[3] = m1.entries[12];

    this->entries[4] = m1.entries[1];
    this->entries[6] = m1.entries[9];
    this->entries[7] = m1.entries[13];

    this->entries[8] = m1.entries[2];
    this->entries[9] = m1.entries[6];
    this->entries[11] = m1.entries[14];

    this->entries[12] = m1.entries[3];
    this->entries[13] = m1.entries[7];
    this->entries[14] = m1.entries[11];
}

void Matrix4x4::inverse() {

    float det = this->det();
    if (det != 0) {
        Matrix4x4 C(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

        C.entries[0] = this->entries[5] * this->entries[10] * this->entries[15] +
                       this->entries[9] * this->entries[14] * this->entries[7] +
                       this->entries[13] * this->entries[6] * this->entries[11] -
                       this->entries[7] * this->entries[10] * this->entries[13] -
                       this->entries[11] * this->entries[14] * this->entries[5] -
                       this->entries[15] * this->entries[6] * this->entries[9];

        C.entries[4] = -1 * (this->entries[4] * this->entries[10] * this->entries[15] +
                             this->entries[8] * this->entries[14] * this->entries[7] +
                             this->entries[12] * this->entries[6] * this->entries[11] -
                             this->entries[7] * this->entries[10] * this->entries[12] -
                             this->entries[11] * this->entries[14] * this->entries[4] -
                             this->entries[15] * this->entries[6] * this->entries[8]);

        C.entries[8] = this->entries[4] * this->entries[9] * this->entries[15] +
                       this->entries[8] * this->entries[13] * this->entries[7] +
                       this->entries[12] * this->entries[5] * this->entries[11] -
                       this->entries[7] * this->entries[9] * this->entries[12] -
                       this->entries[11] * this->entries[13] * this->entries[4] -
                       this->entries[15] * this->entries[5] * this->entries[8];

        C.entries[12] = -1 * (this->entries[4] * this->entries[9] * this->entries[14] +
                              this->entries[8] * this->entries[13] * this->entries[6] +
                              this->entries[12] * this->entries[5] * this->entries[10] -
                              this->entries[6] * this->entries[9] * this->entries[12] -
                              this->entries[10] * this->entries[13] * this->entries[4] -
                              this->entries[14] * this->entries[5] * this->entries[8]);

        C.entries[1] = -1 * (this->entries[1] * this->entries[10] * this->entries[15] +
                             this->entries[9] * this->entries[14] * this->entries[3] +
                             this->entries[13] * this->entries[2] * this->entries[11] -
                             this->entries[3] * this->entries[10] * this->entries[13] -
                             this->entries[11] * this->entries[14] * this->entries[1] -
                             this->entries[15] * this->entries[2] * this->entries[9]);

        C.entries[5] = this->entries[0] * this->entries[10] * this->entries[15] +
                       this->entries[8] * this->entries[14] * this->entries[3] +
                       this->entries[12] * this->entries[2] * this->entries[11] -
                       this->entries[3] * this->entries[10] * this->entries[12] -
                       this->entries[11] * this->entries[14] * this->entries[0] -
                       this->entries[15] * this->entries[2] * this->entries[8];

        C.entries[9] = -1 * (this->entries[0] * this->entries[9] * this->entries[15] +
                             this->entries[8] * this->entries[13] * this->entries[3] +
                             this->entries[12] * this->entries[1] * this->entries[11] -
                             this->entries[3] * this->entries[9] * this->entries[12] -
                             this->entries[11] * this->entries[13] * this->entries[0] -
                             this->entries[15] * this->entries[1] * this->entries[8]);

        C.entries[13] = this->entries[0] * this->entries[9] * this->entries[14] +
                        this->entries[8] * this->entries[13] * this->entries[2] +
                        this->entries[12] * this->entries[1] * this->entries[10] -
                        this->entries[2] * this->entries[9] * this->entries[12] -
                        this->entries[10] * this->entries[13] * this->entries[0] -
                        this->entries[14] * this->entries[1] * this->entries[8];

        C.entries[2] = this->entries[1] * this->entries[6] * this->entries[15] +
                       this->entries[5] * this->entries[14] * this->entries[3] +
                       this->entries[13] * this->entries[2] * this->entries[7] -
                       this->entries[3] * this->entries[6] * this->entries[13] -
                       this->entries[7] * this->entries[14] * this->entries[1] -
                       this->entries[15] * this->entries[2] * this->entries[5];

        C.entries[6] = -1 * (this->entries[0] * this->entries[6] * this->entries[15] +
                             this->entries[4] * this->entries[14] * this->entries[3] +
                             this->entries[12] * this->entries[2] * this->entries[7] -
                             this->entries[3] * this->entries[6] * this->entries[12] -
                             this->entries[7] * this->entries[14] * this->entries[0] -
                             this->entries[15] * this->entries[2] * this->entries[4]);

        C.entries[10] = this->entries[0] * this->entries[5] * this->entries[15] +
                        this->entries[4] * this->entries[13] * this->entries[3] +
                        this->entries[12] * this->entries[1] * this->entries[7] -
                        this->entries[3] * this->entries[5] * this->entries[12] -
                        this->entries[7] * this->entries[13] * this->entries[0] -
                        this->entries[15] * this->entries[1] * this->entries[4];

        C.entries[14] = -1 * (this->entries[0] * this->entries[5] * this->entries[14] +
                              this->entries[4] * this->entries[13] * this->entries[2] +
                              this->entries[12] * this->entries[1] * this->entries[6] -
                              this->entries[2] * this->entries[5] * this->entries[12] -
                              this->entries[6] * this->entries[13] * this->entries[0] -
                              this->entries[14] * this->entries[1] * this->entries[4]);

        C.entries[3] = this->entries[1] * this->entries[6] * this->entries[11] +
                       this->entries[5] * this->entries[10] * this->entries[3] +
                       this->entries[9] * this->entries[2] * this->entries[7] -
                       this->entries[3] * this->entries[6] * this->entries[9] -
                       this->entries[7] * this->entries[10] * this->entries[1] -
                       this->entries[11] * this->entries[2] * this->entries[5];


        C.entries[7] = this->entries[0] * this->entries[6] * this->entries[11] +
                       this->entries[4] * this->entries[10] * this->entries[3] +
                       this->entries[8] * this->entries[2] * this->entries[7] -
                       this->entries[3] * this->entries[6] * this->entries[8] -
                       this->entries[7] * this->entries[10] * this->entries[0] -
                       this->entries[11] * this->entries[2] * this->entries[4];

        C.entries[11] = -1 * (this->entries[0] * this->entries[5] * this->entries[11] +
                              this->entries[4] * this->entries[9] * this->entries[3] +
                              this->entries[8] * this->entries[1] * this->entries[7] -
                              this->entries[3] * this->entries[5] * this->entries[8] -
                              this->entries[7] * this->entries[9] * this->entries[0] -
                              this->entries[11] * this->entries[1] * this->entries[4]);


        C.entries[15] = this->entries[0] * this->entries[5] * this->entries[10] +
                        this->entries[4] * this->entries[9] * this->entries[2] +
                        this->entries[8] * this->entries[1] * this->entries[6] -
                        this->entries[2] * this->entries[5] * this->entries[8] -
                        this->entries[6] * this->entries[9] * this->entries[0] -
                        this->entries[10] * this->entries[1] * this->entries[4];

        for (int i = 0; i < 16; i++) {
            this->entries[i] = C.entries[i] / det;

        }


    } else std::cout << "Wyznacznik rowny 0, brak macierzy odwrotnej\n";
}

float Matrix4x4::det() {
    return this->entries[0] * this->entries[5] * this->entries[10] * this->entries[15] +
           this->entries[0] * this->entries[6] * this->entries[11] * this->entries[13] +
           this->entries[0] * this->entries[7] * this->entries[9] * this->entries[14] +
           this->entries[1] * this->entries[4] * this->entries[11] * this->entries[14] +
           this->entries[1] * this->entries[6] * this->entries[8] * this->entries[15] +
           this->entries[1] * this->entries[7] * this->entries[10] * this->entries[12] +
           this->entries[2] * this->entries[4] * this->entries[9] * this->entries[15] +
           this->entries[2] * this->entries[5] * this->entries[11] * this->entries[12] +
           this->entries[2] * this->entries[7] * this->entries[8] * this->entries[13] +
           this->entries[3] * this->entries[4] * this->entries[10] * this->entries[13] +
           this->entries[3] * this->entries[5] * this->entries[8] * this->entries[14] +
           this->entries[3] * this->entries[6] * this->entries[9] * this->entries[12] -
           this->entries[0] * this->entries[5] * this->entries[11] * this->entries[14] -
           this->entries[0] * this->entries[6] * this->entries[9] * this->entries[15] -
           this->entries[0] * this->entries[7] * this->entries[10] * this->entries[13] -
           this->entries[1] * this->entries[4] * this->entries[10] * this->entries[15] -
           this->entries[1] * this->entries[6] * this->entries[11] * this->entries[12] -
           this->entries[1] * this->entries[7] * this->entries[8] * this->entries[14] -
           this->entries[2] * this->entries[4] * this->entries[11] * this->entries[13] -
           this->entries[2] * this->entries[5] * this->entries[8] * this->entries[15] -
           this->entries[2] * this->entries[7] * this->entries[9] * this->entries[12] -
           this->entries[3] * this->entries[4] * this->entries[9] * this->entries[14] -
           this->entries[3] * this->entries[5] * this->entries[10] * this->entries[12] -
           this->entries[3] * this->entries[6] * this->entries[8] * this->entries[13];
}


