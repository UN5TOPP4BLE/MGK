//
// Created by mateu on 08.11.2022.
//

#ifndef MGK_MATRIX3N_H
#define MGK_MATRIX3N_H


class Matrix3n {
private:

public:

    float matrixData[9]={0.0};

    Matrix3n();

    Matrix3n(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8);

    //Matrix3n& operator = (const R4DMatrix3n& value);

    ~Matrix3n();

};


#endif //MGK_MATRIX3N_H
