//
// Created by mateu on 08.11.2022.
//

#include <cstring>
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
    entries[10] = e1;
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
