

class Vector2 {
  public:
    double x, y, w;

    Vector2(double _x, double _y)
          : Vector2(_x, _y, 1.0f) {}

    Vector2(double _x, double _y, double _w)
          : x(_x), y(_y), w(_w) {}
            //Vector3(_x, _y, 0, 1.0f) {}
};


class Vector3
{
  public:
    double x, y, z, w;

    Vector3(double _x, double _y)
          : Vector3(_x, _y, 0.0f, 1.0f) {}

    Vector3(double _x, double _y, double _z)
          : Vector3(_x, _y, _z, 1.0f) {}

    Vector3(double _x, double _y, double _z, double _w)
          : x(_x), y(_y), z(_z), w(_w) {}

    Vector3& operator+=(const Vector3& other) {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        return *this;
    }

    Vector3& operator*=(float scalar) {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        return *this;
    }

    Vector3 operator*(float scalar) const {
        return Vector3(this->x * scalar, this->y * scalar, this->z * scalar);
    }

    Vector3 operator-(const Vector3& other) const {
        return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
    }

    Vector3 operator+(const Vector3& other) const {
        return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
    }
    //
    // vector3.zero and vector3.one ??
    //
//    friend std::ostream& operator<<(std::ostream& os, const Vector4& vec)
//    {
//      os << "x: " << vec.x << " "
//         << "y: " << vec.y << " "
//         << "z: " << vec.z << " "
//         << "w: " << vec.w << " ";
//        return os;
//    }
};
