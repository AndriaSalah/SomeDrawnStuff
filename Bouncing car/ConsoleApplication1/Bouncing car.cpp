#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <ctime>
#include <cstdio>
#include<synchapi.h>
#include<iostream>
#include<sstream>
using namespace std;
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")


void InitGraphics(int argc, char* argv[]);
void SetTransformations();
void OnDisplay();
float rz;
float angle = 0.0;
GLboolean direction;
int main(int argc, char* argv[]) {
    InitGraphics(argc, argv);
    return 0;
}

void InitGraphics(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1020, 720);
    glutCreateWindow("Bouncing car");
    glutDisplayFunc(OnDisplay);
    glutMainLoop();
}

void SetTransformations() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20, 200, -200, 200);
}

void OnDisplay() {

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    SetTransformations();
    // glRotatef(angle,0,0,1.0);
       //glScaled(-60, -60, 0);
    glTranslatef(rz, 0, 0);

    if (rz >= 180 || rz <= -50) {
        direction = !direction;
    }
    //
    //if (rz >= 500) {
    //
    //       rz = -1 * rz;
    //        glTranslatef(rz, 0, 0);
    //    }

    glLineWidth(4);

    glBegin(GL_POLYGON);
    //main body quad
    glColor3f(0.7, 0, 0);
    glVertex2i(10, -85);
    glVertex2i(10, 85);
    glVertex2i(100, 85);
    glVertex2i(100, -85);



    glEnd();
    glBegin(GL_POLYGON);
    //front bumber
    glVertex2i(100, 85);
    glVertex2i(110, 75);
    glVertex2i(115, 65);
    glVertex2i(118, 55);
    glVertex2i(120, 0);
    glVertex2i(118, -55);
    glVertex2i(115, -65);
    glVertex2i(110, -75);
    glVertex2i(100, -85);

    glEnd();

    glBegin(GL_LINE_STRIP);
    //fornt bumper lining
    glColor3f(0, 0, 0);
    glVertex2i(90, 75);
    glVertex2i(95, 70);
    glVertex2i(105, 50);
    glVertex2i(107, 0);
    glVertex2i(105, -50);
    glVertex2i(95, -70);
    glVertex2i(90, -75);

    glEnd();
    //rear bumper
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0, 0);
    glVertex2i(10, 85);
    glVertex2i(8, 75);
    glVertex2i(3, 65);
    glVertex2i(1, 55);
    glVertex2i(-1, 0);
    glVertex2i(1, -55);
    glVertex2i(3, -65);
    glVertex2i(8, -80);
    glVertex2i(10, -85);

    glEnd();
    //rear bumper lining
    glBegin(GL_LINE_STRIP);
    glColor3f(0, 0, 0);
    glVertex2i(14, 80);
    glVertex2i(12, 75);
    glVertex2i(7, 65);
    glVertex2i(5, 55);
    glVertex2i(3, 0);
    glVertex2i(5, -55);
    glVertex2i(7, -65);
    glVertex2i(12, -75);
    glVertex2i(14, -80);
    glEnd();


    //roof of the car
    glBegin(GL_QUADS);
    glColor3f(0.7, 0, 0);
    glVertex2i(35, 40);
    glVertex2i(55, 40);
    glVertex2i(55, -40);
    glVertex2i(35, -40);

    //rear window of the car
    glColor3f(0, 0.5, 0.5);
    glVertex2i(35, 30);
    glVertex2i(25, 30);
    glVertex2i(25, -30);
    glVertex2i(35, -30);

    //tires of the car
    glColor3f(0.5, 0.5, 0.5);
    glVertex2i(20, 85);
    glVertex2i(20, 90);
    glVertex2i(40, 90);
    glVertex2i(40, 85);

    glColor3f(0.5, 0.5, 0.5);
    glVertex2i(20, -85);
    glVertex2i(20, -90);
    glVertex2i(40, -90);
    glVertex2i(40, -85);

    glColor3f(0.5, 0.5, 0.5);
    glVertex2i(80, 85);
    glVertex2i(80, 90);
    glVertex2i(100, 90);
    glVertex2i(100, 85);

    glColor3f(0.5, 0.5, 0.5);
    glVertex2i(80, -85);
    glVertex2i(80, -90);
    glVertex2i(100, -90);
    glVertex2i(100, -85);

    glEnd();

    glBegin(GL_LINE_LOOP);
    // rear window lining
    glColor3f(0, 0, 0);
    glVertex2i(35, 30);
    glVertex2i(25, 30);
    glVertex2i(25, -30);
    glVertex2i(35, -30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    //roof lining
    glColor3f(0, 0, 0);
    glVertex2i(35, 40);
    glVertex2i(55, 40);
    glVertex2i(55, -40);
    glVertex2i(35, -40);

    glEnd();

    glBegin(GL_POLYGON);
    //side window 1
    glColor3f(0, 0.5, 0.5);
    glVertex2i(40, 40);
    glVertex2i(35, 65);
    glVertex2i(60, 65);
    glVertex2i(50, 40);

    glEnd();

    glBegin(GL_LINE_LOOP);
    //side window 1
    glColor3f(0, 0, 0);
    glVertex2i(40, 40);
    glVertex2i(35, 65);
    glVertex2i(60, 65);
    glVertex2i(50, 40);

    glEnd();

    glBegin(GL_POLYGON);
    //side window 2
    glColor3f(0, 0.5, 0.5);
    glVertex2i(40, -40);
    glVertex2i(35, -65);
    glVertex2i(60, -65);
    glVertex2i(50, -40);

    glEnd();

    glBegin(GL_LINE_LOOP);
    //side window 2 lining
    glColor3f(0, 0, 0);
    glVertex2i(40, -40);
    glVertex2i(35, -65);
    glVertex2i(60, -65);
    glVertex2i(50, -40);

    glEnd();

    glBegin(GL_POLYGON);
    //front window
    glColor3f(0, 0.5, 0.5);
    glVertex2i(55, 40);
    glVertex2i(70, 55);
    glVertex2i(74, 35);
    glVertex2i(77, 20);

    glVertex2i(79, 0);

    glVertex2i(77, -20);
    glVertex2i(74, -35);
    glVertex2i(70, -55);
    glVertex2i(55, -40);

    glEnd();

    glBegin(GL_LINE_LOOP);
    //front window lining
    glColor3f(0, 0, 0);
    glVertex2i(55, 40);
    glVertex2i(70, 55);
    glVertex2i(74, 35);
    glVertex2i(77, 20);
    glVertex2i(79, 0);
    glVertex2i(77, -20);
    glVertex2i(74, -35);
    glVertex2i(70, -55);
    glVertex2i(55, -40);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex2i(96, 70);
    glVertex2i(102, 75);
    glVertex2i(106, 70);
    glVertex2i(106, 55);
    glVertex2i(106, 50);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex2i(96, -70);
    glVertex2i(102, -75);
    glVertex2i(106, -70);
    glVertex2i(106, -55);
    glVertex2i(106, -50);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex2i(96, 70);
    glVertex2i(102, 75);
    glVertex2i(106, 70);
    glVertex2i(106, 55);
    glVertex2i(106, 50);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex2i(96, -70);
    glVertex2i(102, -75);
    glVertex2i(106, -70);
    glVertex2i(106, -55);
    glVertex2i(106, -50);

    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2i(109, 5);
    glVertex2i(111, 0);
    glVertex2i(109, -5);

    glEnd();

    glBegin(GL_LINES);
    glVertex2i(77, 35);
    glVertex2i(95, 55);
    glVertex2i(77, -35);
    glVertex2i(95, -55);
    glVertex2i(22, 35);
    glVertex2i(12, 55);
    glVertex2i(22, -35);
    glVertex2i(12, -55);


    glEnd();
    //if (rz >= 50) {
    //    rz += 0.01;
    //}
    //else {
    //    rz += 0.05;
    //}

    //if (rz >= 100) {
    //
    //    if (angle < 360) {
    //        angle+=0.1;
    //    }
    //}

       // rz += 0.05;

    if (!direction) {
        rz -= 0.03;
    }
    else {
        rz += 0.03;
    }

    glFlush();

    glutSwapBuffers();
    glutPostRedisplay();
}
