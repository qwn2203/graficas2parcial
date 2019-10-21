#include "op3d.h"
#include "math.h"
#include <stack>
#include <iostream>

#define GL_PI 3.1416


using namespace std;

op3d::op3d()
{
    //ctor
}

op3d::~op3d()
{
    //dtor
}
matriz::~matriz()
{
    //dtor
}

matriz::matriz(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(i==j){
                M[i][j] = 1;
            }
            else{
                M[i][j] = 0;
            }
        }
    }
}

void op3d::LoadIdentity(float M[4][4]){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(i==j){
                M[i][j] = 1;
            }
            else{
                M[i][j] = 0;
            }
        }
    }
}

void op3d::push(){
    matriz *tmp;
    int i,j;
    tmp = new matriz();
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            tmp -> M[i][j] = A[i][j];
            //(*tmp)[M[i][j]]= A[i][j];
        }
    }
    mystack.push(tmp);
    tmp = NULL;
}

void op3d::pop(){
    matriz *tmp;
    tmp = mystack.top();
    int i,j;
    if(tmp){
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                A[i][j] = tmp -> M[i][j];
            }
        }
    }
    delete(tmp);
    mystack.pop();
}

void op3d::trasladar(float tx, float ty, float tz){
    float tM[4][4];
    LoadIdentity(T);
    T[0][4] = tx;
    T[1][4] = ty;
    T[2][4] = tz;

    for (int i=0; i< 4; i++){
        for (int j=0; j<4; j++){
            float temp = 0;
            for (int k=0; k<4; k++){
                temp += T[i][k]*A[k][j]; //-----> crear matriz temporal
            }
            tM[i][j] = temp;
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            A[i][j] = tM[i][j];
        }
    }
}

void op3d::escalar(float sx, float sy, float sz){
    float tM[4][4];
    LoadIdentity(E);
    E[0][0] = sx;
    E[1][1] = sy;
    E[2][2] = sz;

    for (int i=0; i< 4; i++){
        for (int j=0; j<4; j++){
            float temp = 0;
            for (int k=0; k<4; k++){
               temp += E[i][k]*A[k][j];
            }
            tM[i][j] = temp;
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            A[i][j] = tM[i][j];
        }
    }

}

void op3d::rotarX(float angle){
    float tM[4][4];
    float m = angle * (float(GL_PI)/float(180));
    LoadIdentity(R);
    R[1][1] = cos(m);
    R[1][2] = -sin(m);
    R[2][1] = sin(m);
    R[2][2] = cos(m);

    for (int i=0; i< 4; i++){
        for (int j=0; j<4; j++){
            float temp = 0;
            for (int k=0; k<4; k++){
                temp += R[i][k]*A[k][j];
            }
            tM[i][j] = temp;
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            A[i][j] = tM[i][j];
        }
    }
}

void op3d::rotarY(float angle){
    float tM[4][4];
    float m = angle * (float(GL_PI)/float(180));
    LoadIdentity(R);
    R[0][0] = cos(m);
    R[0][2] = sin(m);
    R[2][0] = -sin(m);
    R[2][2] = cos(m);

    for (int i=0; i< 4; i++){
        for (int j=0; j<1; j++){
            float temp = 0;
            for (int k=0; k<4; k++){
                temp += R[i][k]*A[k][j];
            }
            tM[i][j] = temp;
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            A[i][j] = tM[i][j];
        }
    }
}

void op3d::rotarZ(float angle){
    float tM[4][4];
    float m = angle * (float(GL_PI)/float(180));
    LoadIdentity(R);
    R[0][0] = cos(m);
    R[0][1] = -sin(m);
    R[1][0] = sin(m);
    R[1][1] = cos(m);

    for (int i=0; i< 4; i++){
        for (int j=0; j<1; j++){
            float temp = 0;
            for (int k=0; k<4; k++){
                temp += R[i][k]*A[k][j];
            }
        }
    }
     for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            A[i][j] = tM[i][j];
        }
    }
}
