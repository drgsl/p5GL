
 
#include <cstdio>  // For sprintf

#include "../math.cpp"
#include "../renderer.cpp"

void RenderString(float x, float y, void *font, const char* string, float r, float g, float b)
{  
  char *c;

  glColor3f(r,g,b); 
  glRasterPos2f(x, y);

  glutBitmapString(font, (unsigned char*)string);
}

class Paddle
{
  public:
    Vector3 pos;
    Vector3 size;
    Vector3 speed;

    void show()
    {
      stroke(Color("white"));
      rect(pos, pos + size);
    }
};
class DVD
{
  public:
    Vector3 pos;
    Vector3 size;
    Vector3 speed;

    Color color;

    void reset()
    {
      pos = Vector3::zero;
      speed = Vector3::getRandom() * 0.025;
      size = Vector3::one * 0.25;

      color = Color::getRandom();
    }
};








DVD dvd;

Paddle player_left;
Paddle player_right;
void setup()
{
  dvd.reset();

  player_left.size = Vector3(0.02f, 0.5f);
  player_left.pos  = Vector3(-1 + player_left.size.x, 0);
  player_right.size = Vector3(0.02f, 0.1f); 
}

int score_player   = 0;
int score_computer = 0;

void loop()
{
  background(Color("black"));
  stroke(Color("white"));
  line(Vector3(0, 1), Vector3(0, 0.8));
  line(Vector3(0, 0.6), Vector3(0, 0.4));

  line(Vector3(0, 0.2), Vector3(0, 0.0));



  line(Vector3(0, -0.2), Vector3(0, -0.4));
  line(Vector3(0, -0.6), Vector3(0, -0.8));

  stroke(~dvd.color);
  rect(dvd.pos - Vector3::one * 0.01f, dvd.pos + dvd.size + Vector3::one * 0.01f);

  stroke(dvd.color);
  rect(dvd.pos, dvd.pos + dvd.size);

  dvd.pos.x += dvd.speed.x;
  dvd.pos.y += dvd.speed.y;


  if(dvd.pos.x + dvd.size.x >= 1)
  {
    dvd.speed.x =   - dvd.speed.x;
    dvd.pos.x   = 1 - dvd.size.x;

    dvd.color   = Color::getRandom();
    score_computer++;
  }
  else if (dvd.pos.x <= -1)
  {
    if (dvd.pos.y + dvd.size.y > player_left.pos.y && dvd.pos.y < player_left.pos.y + player_left.size.y)
    {
    dvd.speed.x = - dvd.speed.x;
    dvd.pos.x   = - 1;
    dvd.color   = Color::getRandom();
    score_player ++;
    }
    if(dvd.pos.x <= -2.0f)
    {
      dvd.reset();
      score_player = 0;
    }
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


  if (dvd.pos.x < 0)
  {
  // player_left.pos  = Vector3(-1 + player_left.size.x, dvd.pos.y);
  }

  player_left.show();

  if(dvd.pos.x > 0)
  {
  player_right.pos  = Vector3(1 - player_right.size.x, dvd.pos.y);
  }

  player_right.show();

  char buffer[50];  // Make sure the buffer is large enough to hold the number
  sprintf(buffer, "%d", score_player);

  const char* cstr = buffer;
  RenderString(-1, 0.7, GLUT_BITMAP_TIMES_ROMAN_24, cstr, 0, 0, 1.0);

  char buffer2[50];  // Make sure the buffer is large enough to hold the number
  sprintf(buffer2, "%d", score_computer);

  const char* cstr2 = buffer2;

  RenderString(0.9, 0.7, GLUT_BITMAP_TIMES_ROMAN_24, cstr2, 0, 0, 1.0);

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

if(key == 'w')
  {
  player_left.pos  = Vector3(-1 + player_left.size.x, player_left.pos.y + 0.08);
  }
if(key == 's')
  {
  player_left.pos  = Vector3(-1 + player_left.size.x, player_left.pos.y - 0.08);
  }

if (key == 'r')
  {
    dvd.reset();
  }
}


