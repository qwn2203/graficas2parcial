/* Parcial 2 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include "op3d.h"
#include "pyramid.h"

op3d miOp3d;
pyramid miPiramide(&miOp3d);


void printLabels(){
    //LETRA x
    glColor3d(1.0f, 1.1f, 0.0f);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'X');
    glRasterPos3f(10,0,0);
    //LETRA y
    glColor3d(1.0f, 1.1f, 0.0f);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Y');
    glRasterPos3f(0,10,0);
    //LETRA Z
    glColor3d(1.0f, 1.1f, 0.0f);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Z');
    glRasterPos3f(0,0,10);
}
void drawAxis(){

    //X
    glColor3d(1.0, 0.0, 0.0);
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex3f(-9.0,0.0,0.0);
        glVertex3f(9.0,0.0,0.0);
    glEnd();
    //Y
    glColor3f(0.0f,1.0f,0.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0,-9.0,0.0);
        glVertex3f(0.0,9.0,0.0);
    glEnd();
    //Z
    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0,0.0,-9.0);
        glVertex3f(0.0,0.0,9.0);
    glEnd();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //miOp3d.LoadIdentity();

    miOp3d.push();
    printLabels();
    drawAxis();

    //ROSA
    glColor3f(1.0f,0.0f,1.0f);

    miPiramide.draw();


    glFlush();

}
void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1,1,1,0,0,0,0,1,0);
    glClearColor(0,0,0,0);
}

static void key(unsigned char key, int x, int y){
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("PARCIAL 2");
    init(); /* fija o establece los atributos */
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}
