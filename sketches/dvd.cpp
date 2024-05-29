

#include <iostream>

class DVD
{
  public:
    Vector3 pos;
    Vector3 size;
    Vector3 speed;

    Color color;
};


DVD dvd;

void setup()
{
  dvd.pos = Vector3::getRandom();
  dvd.speed = Vector3::getRandom() * 0.025;
  dvd.size = Vector3::one * 0.25;

  dvd.color = Color::getRandom();
}

void loop()
{
  background(Color("black"));
  
  stroke(dvd.color);
  rect(dvd.pos, dvd.pos + dvd.size);

  dvd.pos.x += dvd.speed.x;
  dvd.pos.y += dvd.speed.y;


  if(dvd.pos.x + dvd.size.x >= 1)
  {
    dvd.speed.x =   - dvd.speed.x;
    dvd.pos.x   = 1 - dvd.size.x;

    dvd.color   = Color::getRandom();
  }
  else if (dvd.pos.x <= -1)
  {
    dvd.speed.x = - dvd.speed.x;
    dvd.pos.x   = - 1;

    dvd.color   = Color::getRandom();
  }
  if(dvd.pos.y + dvd.size.y >= 1)
  {
    dvd.speed.y =   - dvd.speed.y;
    dvd.pos.y   = 1 - dvd.size.y;
    
    dvd.color   = Color::getRandom();
  }
  else if(dvd.pos.y <= -1)
  {
    dvd.speed.y =   - dvd.speed.y;
    dvd.pos.y   =   - 1; 
    
    dvd.color   = Color::getRandom();
  }

  // std::cout << dvd.pos.x << " " << dvd.pos.y << "\n";
  // std::cout << dvd.color.r << " " << dvd.color.g << " " << dvd.color.b << "\n";
}


void keyPressed(unsigned char key, int x, int y)
{
printf("%c", key);
// printf("%d", key);
printf("\n");
printf("%d %d", x, y);
printf("\n");
}
