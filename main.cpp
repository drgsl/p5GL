#include <stdio.h>


#include <GL/freeglut.h>









void background(double r, double g, double b, double a)
{
  glClearColor( r, g, b, a);

  glClear(GL_COLOR_BUFFER_BIT);

  glFlush();
}

void strokeWeight(double weight)
{
  glPointSize(weight);
  glLineWidth(weight);
}

void stroke(double r, double g, double b, double a)
{
  glColor3f(r,g,b);
}

void point(double x, double y)
{
  glBegin(GL_POINTS); 
    glVertex2f(x, y);
  glEnd();
}

void line(double x, double y, double x2, double y2)
{
  glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x2,y2);
  glEnd();

}

void rect(double x, double y, double w, double h)
{
  glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+w, y);
    glVertex2f(x+w, y-h);
    glVertex2f(x, y-h);
  glEnd();
}



// import user script
#include "sketch.cpp"



void display(void)
{
  printf("DisplayFunction \n");

  // glBegin(GL_LINES);
  //   glVertex2i( 1,  1);
  //   glVertex2i(-1, -1);
  // glEnd();


  setup();
  glFlush();
}

void reshape(int w, int h)
{
  printf("ReshapeFunction \n");
  
  glViewport(0,0,(GLsizei) w, (GLsizei) h);
}

void keyboard(unsigned char key, int x, int y)
{
  printf("keyboard \n");
}

void mouse(int button, int state, int x, int y)
{
  printf("mouse \n");
}


int main (int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(480, 640);
  glutInitWindowPosition(0,0);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutCreateWindow("Canvas");

  // calls to be wrapped later
  glClearColor(1.0, 1.0, 1.0, 0);
  // glPolygonMode(GL_FRONT, GL_LINE);

  //callback functions
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);

  //main loop
  glutMainLoop();
  return 0;
}
