//
// Created by mateu on 08.11.2022.
//

#ifndef MGK_MATRIX4X4_H
#define MGK_MATRIX4X4_H


class Matrix4x4 {
public:
    float entries[16];

    Matrix4x4();

    Matrix4x4(float e0, float e1, float e2, float e3,
              float e4, float e5, float e6, float e7,
              float e8, float e9, float e10, float e11,
              float e12, float e13, float e14, float e15);

    Matrix4x4(const float *f);

    Matrix4x4(const Matrix4x4 &mat);

    ~Matrix4x4();

    void set(int e, float value);

    void show();

    void add(Matrix4x4 m1, Matrix4x4 m2);

    void sub(Matrix4x4 m1, Matrix4x4 m2);

    void multiply(Matrix4x4 m1, Matrix4x4 m2);

    void multiply(float value);

    void identity();

    void trans(Matrix4x4 m1);

    void inverse(Matrix4x4 m1);

    void det();

    float det(Matrix4x4 m);


};

#endif //MGK_MATRIX4X4_H
