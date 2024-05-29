
class Transform
{
  public:
    Vector3 position = Vector3::zero;
    Vector3 rotation = Vector3::zero;
    Vector3 scale    = Vector3::one;
};

class Rigidbody
{
  public:
    Vector3 speed;
};

class gameobject
{
  public:
    Transform transform;
    Rigidbody rigidbody;
    
};
