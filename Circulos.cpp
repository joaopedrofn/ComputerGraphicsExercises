#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

int xc, yc, r;
float c1, c2, c3;
float pi = 3.141592;


void CircleSimple(){
    int x, y;
    float theta = 0;
    float dTheta = 0.01;
    
    while(theta < pi/4){
        x = xc + r * cos(theta);
        y = yc + r * sin(theta);
        theta += dTheta;
        glVertex2i(x, y);
        glVertex2i(y, x);
        glVertex2i(y, 2*xc-x);
        glVertex2i(2*xc-x, y);
        glVertex2i(2*xc-x, 2*yc-y);
        glVertex2i(2*yc-y, 2*xc-x);
        glVertex2i(2*yc-y, x);
        glVertex2i(x, 2*yc-y);
    }
}

void CircleMidPoint(){
    int x = 0;
    int y = r;
    float p = 5 / 4 - r;
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc - y, yc - x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc + x, yc - y);
    
    while(x++<y){
        if(p<0){
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * x + 1 - 2 * y;
        }
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc - y, yc - x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc + x, yc - y);
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0.0, 500.0, 500.0,0.0 );

    glBegin(GL_POINTS);
    glColor3f(c1, c2, c3);
    if(glutGetWindow() == 1)
        CircleSimple();
    else
        CircleMidPoint();

    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    printf("Centro, raio: ");
    scanf("%d %d %d", &xc, &yc, &r);
    printf("Cor RGB [0..1]: ");
    scanf("%f %f %f", &c1, &c2, &c3);

    glutInit(&argc, argv);

    glutInitWindowPosition(180, 80);
    glutInitWindowSize(500,500);
    glutCreateWindow("CircleSimple");
    glutDisplayFunc(display);


    glutInitWindowPosition(700, 80);
    glutInitWindowSize(500,500);
    glutCreateWindow("CircleMidPoint");
    glutDisplayFunc(display);

    glutMainLoop();

}