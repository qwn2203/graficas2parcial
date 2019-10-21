#include "pyramid.h"

pyramid::pyramid(op3d *data){
    uOp3d = data;
}

pyramid::~pyramid(){
    uOp3d = NULL;
}
void pyramid::draw(){
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<3;j++){
            pointsChange[i][j] = points[i][j];
        }
    }
    glBegin(GL_LINE_LOOP);
        for(i=0;i<=3;i++){
            glVertex3f(points[i][0],points[i][1],points[i][2]);
        }
    glEnd();
    glBegin(GL_LINES);
        for(i=0;i<=5;i++){
            glVertex3f(points[4][0],points[4][1],points[4][2]);
            glVertex3f(points[i][0],points[i][1],points[i][2]);
        }
    glEnd();
}
