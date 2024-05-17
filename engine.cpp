
#include <GL/freeglut.h>
#include <math.h>

#include "color.cpp"



void background(Color c)
{
  glClearColor( c.r, c.g, c.b, c.a);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}

/***** ***** ***** ***** ***** *****
              MODIFIERS
 ***** ***** ***** ***** ***** *****/

void fill()
{
  glPolygonMode(GL_FRONT, GL_FILL);
}

void noFill()
{
  glPolygonMode(GL_BACK, GL_LINE);
}

void strokeWeight(double weight)
{
  glPointSize(weight);
  glLineWidth(weight);
}

void stroke(Color c)
{
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glColor4f(c.r,c.g,c.b,c.a);
}

/***** ***** ***** ***** ***** *****
             PRIMITIVES
 ***** ***** ***** ***** ***** *****/

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

void circle(double x, double y, double r, double segments = 1000)
{
  double π = 3.14159; 
  glBegin(GL_POLYGON);
  for (int i = 0; i< segments; i++)
  {
    double θ = 2.0f * π * i/segments;

    float x = r * cosf(θ);
    float y = r * sinf(θ);

    glVertex2f(x, y);
  }
  glEnd();
}
