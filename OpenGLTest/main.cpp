#include <iostream>
#include <GL/glut.h>

using namespace std;

GLint iWidth = 512, iHeight = 512;

const int iCubeSize = 300;

void Display(void)
{
    int left, right, top, bottom;

    left  = (iWidth - iCubeSize) / 2;
    right = left + iCubeSize;
    bottom = (iHeight - iCubeSize) / 2;
    top = bottom + iCubeSize;

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
      glVertex2f(left,bottom);
      glVertex2f(left,top);
      glVertex2f(right,top);
      glVertex2f(right,bottom);
    glEnd();

    glFinish();
}

void Reshape(GLint w, GLint h)
{
    iWidth = w;
    iHeight = h;
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

//void Keyboard(unsigned char key, int x, int y)
//{
//#define ESCAPE '\033'
//
//    if( key == ESCAPE )
//        exit(0);
//}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(100, 100);

    //Reshape(1000, 1000);

    glutInitWindowSize(iWidth, iHeight);
    glutCreateWindow("OpenGL example");

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    //glutKeyboardFunc(Keyboard);

    glutMainLoop();

    return 0;
}
