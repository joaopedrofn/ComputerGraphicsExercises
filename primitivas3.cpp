// Programa 01
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
void Inicializa(void)
{
    // Define a cor de fundo da janela de visualização como azul
    glClearColor(0,0, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10, 10, -10, 10);
}
// Função callback chamada para fazer o desenho
void Desenha(void)
{

    //Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    //Executa os comandos OpenGL para renderização.
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
        glColor3f(1, 0, 0);
        glVertex2f(-1.5, 0);
        glVertex2f(-5, -5);

        glColor3f(0, 0, 1);
        glVertex2f(0, -2);
        glVertex2f(5, -5);

        glColor3f(0, 1, 0);
        glVertex2f(1.5, 0);
        glVertex2f(0, 5);
    glEnd();
    glFlush();
}
void Teclado(unsigned char key, int x, int y)
{
    if (key == 27)
        exit(0);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Primeiro Programa");
    glutDisplayFunc(Desenha);
    Inicializa();
    glutKeyboardFunc (Teclado);
    glutMainLoop();
}