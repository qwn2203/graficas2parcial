#ifndef OP3D_H
#define OP3D_H

#include <stdlib.h>
#include <stdio.h>

#include <stack>
#include <iostream>

using namespace std;

class matriz
{
    public:
        matriz();
        ~matriz();
        float M[4][4];

};

class op3d
{
    public:
        op3d();
        ~op3d();

        stack<matriz *> mystack;

        void LoadIdentity(float M[][4]);

        float A[4][4],R[4][4],T[4][4],E[4][4];

        void escalar(float x, float y, float z);
        void trasladar(float x, float y, float z);

        void rotarX(float angle);
        void rotarY(float angle);
        void rotarZ(float angle);
        void rotarxyz(float angle);

        void push();
        void pop();

};

#endif // OP3D_H
