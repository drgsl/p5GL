

Quad square;
Quad square2;

Point player;

void setup()
{
  background(Color("black"));
  square = Quad(Vector3(0,0), Vector3(1,1));
  square.show();


  strokeWeight(10);
  player = Point(Vector3(0,0,0));
  player.show();

  square2 = Quad(Vector3(-1,-1), Vector3(1, 1));
}

void loop()
{
  stroke(Color("red"));
  background(Color("black"));

  player.translate(Vector3(-0.001, 0, 0));
  player.show();

  square.translate(Vector3(0, -0.001, 0));
  square.show();

  stroke(Color("aqua", 0.25));
  square2.scale(0.999);
  square2.show();

  stroke(Color("purple", 0.5));
  circle(Vector3(0, 0, 0.0, 1.0), 0.5);
}


void keyPressed(unsigned char key, int x, int y)
{
printf("%c", key);
// printf("%d", key);
printf("\n");
printf("%d %d", x, y);
printf("\n");
}

