#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

int X1, x2, Y1, y2;


void DDA(){
    int step;
    float x, y, xInc, yInc;
    step = fabs(x2 - X1);
    if (fabs(y2 - X1) > step)
    step = fabs(y2-Y1);
    xInc = (x2 - X1)/(float)step;
    yInc = (y2 - Y1)/(float)step;
    x = X1;
    y = Y1;

    while(x<x2){
        glVertex2i(round(x), round(y));
        x = x + xInc;
        y = y + yInc;
    }
}

void bresenhan(){
    int dx = x2 - X1;
    int dy = y2 - Y1;
    int x = X1;
    int y = Y1;
    int p;


    while(x != x2 && y != y2){
        glVertex2i(x, y);
        p = 2*dy-dx;
        x++;
        if(p<0){
            p += 2*dy;
        } else {
            y++;
            p += 2*dy-2*dx;
        }

    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0.0, 500.0, 500.0,0.0 );

    glBegin(GL_POINTS);
    glColor3f(1,1,1);
    if(glutGetWindow() == 1)
        DDA();
    else
        bresenhan();

    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    printf("Ponto 1: ");
    scanf("%d %d", &X1, &Y1);
    printf("Ponto 2: ");
    scanf("%d %d", &x2, &y2);

    glutInit(&argc, argv);

    glutInitWindowPosition(180, 80);
    glutInitWindowSize(500,500);
    glutCreateWindow("DDA");
    glutDisplayFunc(display);


    glutInitWindowPosition(700, 80);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bresenhan");
    glutDisplayFunc(display);

    glutMainLoop();

}