#include <stdio.h>

#include "../engine.cpp"
#include <GL/freeglut_std.h>


void setup()
{
  strokeWeight(10);
//   stroke(1, 0, 0, 1);
//   point(0.5, 0.5);
// for (int i = 0; i<10; i++)
// {
//     line(0, 0, i, 1);
//   }
//   line(0,0, 1,1);

//   rect(0.5, 0.5, 1, 1);


//   stroke(0, 0, 1, 1);
//   point(-1, -1);
//   point(0,0);
//   point(1,1);

  background(Color("hotpink"));
}

double num2 = -1;
double num3 = -1;
double inc = 0.01;
void loop()
{
  background(Color("hotpink"));
  point(0,0);
  stroke(Color("purple"));
  line(0,0,num2, 0);
  line(0,0, 0, num3);
  line(0,0,num2, num3);
  
  line(0,0,-num2, 0);
  line(0,0, 0, -num3);
  line(0,0,-num2, -num3);
 
  line(0,0,-num2, num3);
  line(0,0,num2, -num3);
  num2+= inc;
  num3+= inc;

  if(num2 >= 1 || num2 <=-1)
  {
    inc = -inc;
  }

  
  // printf("%f \n", num2);
  //
  fill();
  circle(0,0, 0.5);
  fill();
  stroke(Color("orange", 0.5));
  rect(-0.5, 0.5, 1, 1);
}



