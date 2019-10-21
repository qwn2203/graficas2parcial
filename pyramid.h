#ifndef PYRAMID_H
#define PYRAMID_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include "op3d.h"

#include <iostream>

using namespace std;

class pyramid{
    private:
        op3d *uOp3d;
        float points[5][3] =
        {
            {0.0,0.0,0.0},
            {0.0,0.0,5.0},
            {5.0,0.0,5.0},
            {5.0,0.0,0.0},
            {0.0,5.0,0.0}
        };

    public:
        pyramid(op3d *);
        ~pyramid();
        float pointsChange[5][3] =
        {
            {0.0,0.0,0.0},
            {0.0,0.0,5.0},
            {5.0,0.0,5.0},
            {5.0,0.0,0.0},
            {0.0,5.0,0.0}
        };
        void draw();
};
#endif // pyramid.h
