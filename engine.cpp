

#include <stdio.h>
#include <GL/glut.h>

class Canvas
{
  public:
    int width, height;

    Canvas(int _w, int _h) : width(_w), height(_h) 
    {
      glutInit(0, 0);
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
      glutInitWindowSize(width, height);
      glutInitWindowPosition(0,0);
      glutCreateWindow("Canvas");

      //callback functions
       glutReshapeFunc(reshape);
       glutDisplayFunc(display);
      glutKeyboardFunc(keyboard);
         glutMouseFunc(mouse);

      glutMainLoop();
    }

    void display()
    {
      printf("DisplayFunction");
    }

    void reshape()
    {
      printf("ReshapeFunction");
    }

    void keyboard()
    {
      printf("keyboard");
    }

    void mouse()
    {
      printf("mouse");
    }
};


