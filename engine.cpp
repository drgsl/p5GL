
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
  glColor4f(r,g,b, a);
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

