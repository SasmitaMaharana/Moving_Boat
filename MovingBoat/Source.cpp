/*
y -> Early Morning
m -> Morning
a -> Afternoon
e -> Evening
n -> Night
d -> Mid Night
Num 6 -> Moving Ship Fwd
Num 4 -> Moving Ship bckwd
Esc -> Exit
*/


#include <windows.h>


#include <stdio.h>

#include <glut.h>


#include<iostream>


using namespace std;

float pos = 0, x = 0, col = 0, i, p, c, cf = 0, pr, pl = 0, p2 = 0;
float xx = 0.0, y = 0.0;
int screen = 0;
int wingRotateAngle = 0;
//Introduction Page



void water()
{
    glBegin(GL_POLYGON);
    glColor3f(0.2 + col, 0.2 + col, 0.6 + col);
    glVertex2f(00, 00);
    glVertex2f(00, 300);
    glVertex2f(1024, 300);
    glVertex2f(1024, 00);
    glEnd();
}

void mountain2()
{
    float a, b;
    glColor3f(0.6 + col, 0.4 + col, 0.2 + col);
    for (a = 0, b = 300; a < 1025; a = a + 80)
    {
        glBegin(GL_POLYGON);
        glVertex2f(-40 + a, b);
        glVertex2f(10 + a, b + 140);
        glVertex2f(60 + a, b);
        glEnd();
    }
}

void mountain()
{
    float a, b;
    glColor3f(0.8 + col, 0. + col, 0.4 + col);
    for (a = 0, b = 300; a < 1025; a = a + 80)
    {
        glBegin(GL_POLYGON);
        glVertex2f(0 + a, b);
        glVertex2f(50 + a, b + 100);
        glVertex2f(100 + a, b);
        glEnd();
    }
}

void mountain3()
{
    float a, b;
    glColor3f(0.4 + col, 0.2 + col, 0.0 + col);
    for (a = 0, b = 350; a < 1025; a = a + 80)
    {
        glBegin(GL_POLYGON);
        glVertex2f(0 + a, b);
        glVertex2f(50 + a, b + 180);
        glVertex2f(100 + a, b);
        glEnd();
    }
}


//breshnman circle agrithm
int pntX1, pntY1, r;

void plot(int x, int y)
{
    glBegin(GL_POLYGON);
    glVertex2i(x + pntX1, y + pntY1);
    glEnd();
}


void Bresenham1(int xc, int yc, int r)
{
    // int xc = 200, yc = 150, r = 100;
    int x = 0, y = r;
    int d = 3 - 2 * r;

    glBegin(GL_POLYGON);
    glVertex2f(xc + x, yc + y);
    glVertex2f(xc + x, yc - y);
    glVertex2f(xc - x, yc + y);
    glVertex2f(xc - x, yc - y);
    glVertex2f(xc + y, yc + x);
    glVertex2f(xc + y, yc - x);
    glVertex2f(xc - y, yc + x);
    glVertex2f(xc - y, yc - x);
    while (x < y)
    {
        if (d < 0)
        {
            d += 4 * x + 6;
        }
        else
        {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
        glVertex2f(xc + x, yc + y);
        glVertex2f(xc + x, yc - y);
        glVertex2f(xc - x, yc + y);
        glVertex2f(xc - x, yc - y);
        glVertex2f(xc + y, yc + x);
        glVertex2f(xc + y, yc - x);
        glVertex2f(xc - y, yc + x);
        glVertex2f(xc - y, yc - x);
    }
    glEnd();
    glFlush();
}
//endf algrithm

void Bresenham(int xc, int yc, int r)
{
    // int xc = 200, yc = 150, r = 100;
    int x = 0, y = r;
    int d = 3 - 2 * r;
    // glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(xc + x, yc + y);
    glVertex2f(xc + x, yc - y);
    glVertex2f(xc - x, yc + y);
    glVertex2f(xc - x, yc - y);
    glVertex2f(xc + y, yc + x);
    glVertex2f(xc + y, yc - x);
    glVertex2f(xc - y, yc + x);
    glVertex2f(xc - y, yc - x);
    while (x < y)
    {
        if (d < 0)
        {
            d += 4 * x + 6;
        }
        else
        {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
        glVertex2f(xc + x, yc + y);
        glVertex2f(xc + x, yc - y);
        glVertex2f(xc - x, yc + y);
        glVertex2f(xc - x, yc - y);
        glVertex2f(xc + y, yc + x);
        glVertex2f(xc + y, yc - x);
        glVertex2f(xc - y, yc + x);
        glVertex2f(xc - y, yc - x);
    }
    glEnd();
    glFlush();
}

//fishh
void fish(int x, int y, int xc, int yc) {
    glPushMatrix();
    glTranslatef(0 + pl, 700, 0);
    glVertex2f(xc + x, yc + y);
    glVertex2f(xc + x, yc - y);
    glVertex2f(xc - x, yc - y);
    glVertex2f(xc - x, yc + y);
    glVertex2f(xc + y, yc + x);
    glVertex2f(xc - y, yc + x);
    glVertex2f(xc - y, yc - x);
    glVertex2f(xc + y, yc - x);
}
void circle(int R, int xc, int yc) {
    glBegin(GL_POLYGON);
    int x = 0, y = R; int P = 3 - 2 * R;
    while (y >= x) {
        fish(x, y, xc, yc);
        if (P < 0) {
            P += 4 * x + 6;
        }
        else {
            P += 4 * (x - y) + 10;
            y--;
        }x++;
    }
    glEnd();
}
void traingle(int x1, int x2, int x3, int y1, int y2, int y3) {
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);

    glEnd();
}
void draw1(int x, int y, int xc, int yc)
{
    glVertex2f(xc + x, yc + y);
    glVertex2f(xc + x, yc - y);
    glVertex2f(xc - x, yc - y);
    glVertex2f(xc - x, yc + y);
}
void ellipse(int rx, int ry, int xc, int yc) {
    glBegin(GL_POLYGON);
    int x = 0, y = ry;
    int ry_sq = ry * ry;
    int rx_sq = rx * rx;
    int P = ry_sq - rx_sq * ry + 0.25 * rx_sq;
    while (ry_sq * x < rx_sq * y) {
        draw1(x, y, xc, yc);
        if (P < 0) {
            P += ry_sq * (2 * x + 3);
        }
        else {
            P += ry_sq * (2 * x + 3) + rx_sq * (-2 * y + 2);
            y--;
        }
        x++;
    }
    P = ry_sq * (x + float(1) / 2) * (x + float(1) / 2) + double(rx_sq) * (y - 1) * (y - 1) - double(rx_sq) * ry_sq;
    while (y >= 0) {
        draw1(x, y, xc, yc);
        if (P >= 0) {
            P += rx_sq * (-2 * y + 3);
        }
        else {
            P += ry_sq * (2 * x + 2) + rx_sq * (-2 * y + 3);
            x++;
        }
        y--;
    }
    glEnd();
}

void fishh(float x) {
    glPushMatrix();
    glTranslatef(x, 0, 0);
    glBegin(GL_POLYGON);

    glColor3f(1.0, 1.5, 0.0);
    ellipse(30, 15, 400, 100);
    traingle(380, 360, 360, 100, 120, 80);
    glColor3f(0.0, 0.0, 0.0);
    Bresenham(410, 100, 4);

    glColor3f(1.0, 1.5, 0.0);
    ellipse(30, 15, 700, 210);
    traingle(680, 660, 660, 210, 230, 190);
    glColor3f(0.0, 0.0, 0.0);
    Bresenham(720, 210, 4);

    glColor3f(0.0, 1.0, 1.0);
    ellipse(30, 15, 40, 250);
    traingle(12, 0, 0, 250, 230, 270);
    glColor3f(0.0, 0.0, 0.0);
    Bresenham(50, 250, 4);


    glColor3f(0.8, 0.5, 0.0);
    ellipse(30, 15, 100, 100);
    traingle(80, 60, 60, 100, 120, 80);
    glColor3f(0.0, 0.0, 0.0);
    Bresenham(110, 100, 4);

    glColor3f(1.8, 0.0, 1.0);
    ellipse(30, 15, 360, 200);
    traingle(340, 300, 300, 200, 220, 180);
    glColor3f(0.0, 0.0, 0.0);
    Bresenham(370, 205, 4);

    glPopMatrix();
}

//end fish



void Cloud(float x)
{
    glPushMatrix();
    glTranslatef(x, 0, 0);
    glBegin(GL_POLYGON);

    glColor3f(1.0, 1.0, 1.0);
    Bresenham1(-1, 500, 20);//1
    Bresenham1(45, 500, 40);//2
    Bresenham1(90, 500, 25);//3

    glColor3f(1.0, 1.0, 1.0);
    Bresenham1(90, 700, 40);//1
    Bresenham1(160, 700, 60);//2
    Bresenham1(230, 700, 45);//3

    glColor3f(1.0, 1.0, 1.0);
    Bresenham1(340, 600, 30);//1
    Bresenham1(400, 600, 50);//2
    Bresenham1(460, 600, 35);//3


    glColor3f(1.0, 1.0, 1.0);
    Bresenham1(540, 650, 30);//1
    Bresenham1(600, 650, 50);//2
    Bresenham1(660, 650, 35);//3

    glPopMatrix();
}



void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glLoadIdentity();
    gluOrtho2D(0, 1024, 0, 768);
}


//moveboat
void moveboat(float x)
{
    glPushMatrix();
    glTranslatef(x, 0, 0);
    glBegin(GL_POLYGON);

    glColor3f(0.3f, 0.0f, 0.0f);
    glVertex2i(100, 270);
    glVertex2i(400, 270);
    glVertex2i(480, 370);
    glVertex2i(50, 370);
    glVertex2i(100, 270);
    glEnd();

    glBegin(GL_POLYGON); //BOAT  
    glColor3f(1.0, 1.0, 0.5);
    glVertex2i(320, 370);
    glVertex2i(440, 370);
    glVertex2i(390, 420);
    glEnd();

    glBegin(GL_QUADS); //BOAT 
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(110, 370);
    glVertex2i(120, 370);
    glVertex2i(120, 410);
    glVertex2i(110, 410);
    glVertex2i(110, 370);
    glEnd();

    glBegin(GL_POLYGON); //BOAT  
    glColor3f(1.0, 1.0, 0.5);
    glVertex2i(120, 400);
    glVertex2i(80, 400);
    glVertex2i(120, 470);
    glEnd();
    glPopMatrix();

}

void display()
{
    glColor3f(0.8, 0.5, 0.0);
    ellipse(80, 50, 400, 100);
    traingle(340, 270, 270, 100, 150, 50);
    glColor3f(0.0, 0.0, 0.0);
    circle(5, 450, 120);

    glClear(GL_COLOR_BUFFER_BIT);

    if (screen == 1)
    {


        mountain3();
        mountain2();
        mountain();

        water();


        Cloud(pl);
        moveboat(p2);
        fishh(p2);


        p2 += 0.02;
        if (p2 == 1200)
            p2 = 0;

        pl += 0.5;
        if (pl == 1200)
            pl = 0;


        if (i == 1)
        {
            glColor3f(0.9, 0.9, 0.5);
            Bresenham1(800, 700, 15);//2
        }
        if (i == 2)
        {
            glColor3f(0.8, 0.7, 0.4);
            Bresenham1(800, 700, 15);//2
        }
        if (i == 3)
        {
            glColor3f(1.0, 1.0, 1.0);
            Bresenham1(800, 700, 15);//2
        }
        if (i == 4)
        {
            glColor3f(1.0, 1.0, 1.0);
            Bresenham1(800, 700, 15);//2
        }
        glFlush();
    }
    glutPostRedisplay();
    glutSwapBuffers();
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 13:if (screen == 0)
    {
        screen = 1;
        glutPostRedisplay();
    }
           break;
    case 27:exit(0);
        break;
    case 'y':
        glClearColor(0.8, 0.5, 0.4, 1.0);
        col = -0.1;
        i = 0;
        glutPostRedisplay();
        break;
    case 'm':glClearColor(0.5, 0.5, 1.0, 1.0);
        i = 1;
        col = 0.2;
        glutPostRedisplay();
        break;
    case 'a':glClearColor(0.9, 0.9, 0.3, 1.0);
        i = 2;
        col = 0.3;
        glutPostRedisplay();
        break;
    case 'e':glClearColor(0.8, 0.5, 0.4, 1.0);
        col = -0.1;
        i = 0;
        glutPostRedisplay();
        break;
    case 'n':glClearColor(0.5, 0.5, 0.5, 1.0);
        i = 3;
        glutPostRedisplay();
        col = -0.2;
        break;
    case 'd':glClearColor(0.0, 0.0, 0.0, 0.0);
        i = 4;
        col = -0.3;
        glutPostRedisplay();
        break;

    }
}

int main()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Moving Ship");
    glutSwapBuffers();
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}