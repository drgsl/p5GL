
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

class Ball
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
    
    void reset()
    {
      pos   = Vector3::zero;
      speed = Vector3::random; 
    }
};

Paddle player_left;
Paddle player_right;

void setup()
{
  background(Color("black"));
  player_left.size = Vector3(0.02f, 0.1f); 
  player_left.pos  = Vector3(-1 + player_left.size.x, 0.5f);

  player_left.show();


  player_right.size = Vector3(0.02f, 0.1f); 
  player_right.pos  = Vector3(1 - player_right.size.x, 0.5f);

  player_right.show();


  
}

void loop()
{

}


void keyPressed(unsigned char key, int x, int y)
{
  printf("%c", key);
  // printf("%d", key);
  printf("\n");
  printf("%d %d", x, y);
  printf("\n");
}
