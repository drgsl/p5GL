

void setup()
{
  strokeWeight(10);

  background(Color("aqua"));
}

double num2 = -1;
double num3 = -1;
double inc = 0.01;
void loop()
{
  background(Color("hotpink"));
  point(Vector3(200, 200));
  stroke(Color("purple"));

  line(Vector3(0, 0), Vector3(num2, 0));
  line(Vector3(0, 0), Vector3(0, num3));
  line(Vector3(0, 0), Vector3(num2, num3));

  line(Vector3(0, 0), Vector3(-num2, 0));
  line(Vector3(0, 0), Vector3(0, -num3));
  line(Vector3(0, 0), Vector3(-num2, -num3));

  line(Vector3(0, 0), Vector3(-num2, num3));
  line(Vector3(0, 0), Vector3(num2, -num3));

  num2+= inc;
  num3+= inc;

  if(num2 >= 1 || num2 <=-1)
  {
    inc = -inc;
  }
    Vector3 vec(1.0, 2.0, 3.0, 4.0);
    //print(vec);

  fill();
  circle(Vector3(0, 0, 0.0, 1.0), 0.5);
  fill();
  stroke(Color("orange", 0.5));
  rect(Vector3(-0.5, 0.5, 0.0, 1.0), Vector3(0.5, -0.5, 0.0, 1.0));

}



