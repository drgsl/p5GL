#include <GL/freeglut_std.h>
#include <stdio.h>
#include <GL/freeglut.h>
unsigned char prevKey;

#include "math.cpp"
#include "renderer.cpp"

// import user script
//#include "examples/basics.cpp"
#include "examples/transform.cpp"





void display(void)
{
  // printf("DisplayFunction: \n");
  loop();
  glutSwapBuffers();
  glFlush();
  glutPostRedisplay();
}

void reshape(int w, int h)
{
  // printf("ReshapeFunction \n");
  
  glViewport(0,0,(GLsizei) w, (GLsizei) h);
}

void keyboard(unsigned char key, int x, int y)
{
  printf("keyboard event \n");
  printf("key pressed: %c \n", key);
  if (key == 27)
    exit(0);
  printf("mouse pos: x%d y%d \n", x, y);

}

void mouse(int button, int state, int x, int y)
{
  printf("mouse \n");
}

void glutSetup()
{
  glutInitWindowSize(480, 480); // 480x640
  glutInitWindowPosition(0,0);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutCreateWindow("Canvas");

  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
}

int main (int argc, char** argv)
{
  glutInit(&argc, argv);
  glutSetup();



  setup();

  glutMainLoop();

  return 0;
}
