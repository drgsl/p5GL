
#include <iostream>
#include <GL/freeglut.h>
#include <math.h>


//template<typename T>
//void print(const T& obj)
//{
//  std::cout << "typeOf(" << 
//                obj << ")=" <<
//                typeid(obj).name() << "\n";
//}


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

void point(Vector3 pos)
{
  glBegin(GL_POINTS); 
    glVertex4f(pos.x, pos.y, pos.z, pos.w);
  glEnd();
}

void line(Vector3 start, Vector3 finish)
{
  glBegin(GL_LINES);
    glVertex4f(start.x, start.y, start.z, start.w);
    glVertex4f(finish.x, finish.y, finish.z, finish.w);
  glEnd();

}

void rect(Vector3 bottomLeft, Vector3 topRight)
{
    Vector3 topLeft(bottomLeft.x, topRight.y, 0.0, 1.0);
    Vector3 bottomRight(topRight.x, bottomLeft.y, 0.0, 1.0);

    glBegin(GL_POLYGON);
        glVertex4f(bottomLeft.x, bottomLeft.y, bottomLeft.z, bottomLeft.w);
        glVertex4f(bottomRight.x, bottomRight.y, bottomRight.z, bottomRight.w);
        glVertex4f(topRight.x, topRight.y, topRight.z, topRight.w);
        glVertex4f(topLeft.x, topLeft.y, topLeft.z, topLeft.w);
    glEnd();
}


void circle(Vector3 center, double r, double segments = 1000){
  double π = 3.14159; 
  glBegin(GL_POLYGON);
  for (int i = 0; i< segments; i++)
  {
    double θ = 2.0f * π * i/segments;

    float x = r * cosf(θ);
    float y = r * sinf(θ);

    glVertex4f(x, y, center.x, center.w);
  }
  glEnd();
}
