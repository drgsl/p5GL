
#include <iostream>
#include <random>

// class Vector2 {
//   public:
//     double x, y, w;

//     Vector2(double _x, double _y)
//           : Vector2(_x, _y, 1.0f) {}

//     Vector2(double _x, double _y, double _w)
//           : x(_x), y(_y), w(_w) {}
//             //Vector3(_x, _y, 0, 1.0f) {}
// };


class Vector3
{
  public:
    double x, y, z, w;
    static Vector3 zero;
    static Vector3  one;
    static Vector3 random;

/***** ***** ***** ***** ***** *****
            CONSTRUCTORS
 ***** ***** ***** ***** ***** *****/
  
    Vector3() : Vector3(0,0,0,1) {} 
    Vector3(double _x, double _y)
          : Vector3(_x, _y, 0.0f, 1.0f) {}
    Vector3(double _x, double _y, double _z)
          : Vector3(_x, _y, _z, 1.0f) {}
    Vector3(double _x, double _y, double _z, double _w)
          : x(_x), y(_y), z(_z), w(_w) {}
  
/***** ***** ***** ***** ***** *****
              OPERATORS
 ***** ***** ***** ***** ***** *****/

    Vector3& operator=(const Vector3& other) 
    {
        if (this != &other) // Check for self-assignment
        {
            this->x = other.x;
            this->y = other.y;
            this->z = other.z;
            this->w = other.w;
        }
        return *this;
    }
    Vector3& operator+=(const Vector3& other) 
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        return *this;
    }
    Vector3& operator*=(float scalar) 
    {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        return *this;
    }

    Vector3 operator*(float scalar) const 
    {
        return Vector3(this->x * scalar, this->y * scalar, this->z * scalar);
    }

    Vector3 operator-(const Vector3& other) const 
    {
        return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
    }

    Vector3 operator+(const Vector3& other) const 
    {
        return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector3& vec) {
        os << "x: " << vec.x << " "
           << "y: " << vec.y << " "
           << "z: " << vec.z << " "
           << "w: " << vec.w;
        return os;
    }

    // // Convert Cartesian coordinates to polar coordinates
    // // Returns a pair where first element is the radius and second element is the angle
    // static std::pair<double, double> toPolar(const Vector3& vec)
    // {
    //     double radius = std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    //     double angle = std::atan2(vec.y, vec.x);
    //     return {radius, angle};
    // }

    // // Convert polar coordinates to Cartesian coordinates
    // // Takes radius and angle as inputs and returns a Vector3 in Cartesian coordinates
    // static Vector3 fromPolar(double radius, double angle)
    // {
    //     double x = radius * std::cos(angle);
    //     double y = radius * std::sin(angle);
    //     return Vector3(x, y, 0.0);
    // }

/***** ***** ***** ***** ***** *****
            RANDOM
 ***** ***** ***** ***** ***** *****/

    static Vector3 getRandom() {
        static std::random_device rd;  // Non-deterministic generator
        static std::mt19937 gen(rd()); // Seed the generator
        static std::uniform_real_distribution<> dis(0.0, 1.0);

        double _x = dis(gen);
        double _y = dis(gen);
        double _z = dis(gen);

        return Vector3(_x, _y, _z, 1.0);
    }

    static Vector3 generateRandomVector() {
        static std::random_device rd;  // Non-deterministic generator
        static std::mt19937 gen(rd()); // Seed the generator
        static std::uniform_real_distribution<> dis(0.0, 1.0);

        double _x = dis(gen);
        double _y = dis(gen);
        double _z = dis(gen);

        return Vector3(_x, _y, _z, 1.0);
    }
};


Vector3 Vector3::zero = Vector3(0, 0, 0, 1);
Vector3 Vector3::one  = Vector3(1, 1, 1, 1);
Vector3 Vector3::random = Vector3::generateRandomVector();
