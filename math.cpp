
#include "math/vector.cpp"
#include "math/color.cpp"

#include <random>
#include <cmath> // for std::cos, std::sin, std::atan2, std::sqrt

class Math {
  public:
    static constexpr double PI = 3.14159265358979323846;
    static constexpr double HALF_PI = PI / 2;
    static constexpr double QUARTER_PI = PI / 4;

    static double randomRange(double min, double max) {
      // Random number generator
      static std::random_device rd;   // Non-deterministic generator
      static std::mt19937 gen(rd());  // Seed the generator
      std::uniform_real_distribution<> dis(min, max);

      // Generate and return a random value
      return dis(gen);
    }

    // Trigonometric functions
    static double cos(double angle) {
        return std::cos(angle);
    }

    static double sin(double angle) {
        return std::sin(angle);
    }

    // Convert Cartesian coordinates to polar coordinates
    // Returns a pair where first element is the radius and second element is the angle
    static std::pair<double, double> cartesianToPolar(double x, double y) {
        double radius = std::sqrt(x * x + y * y);
        double angle = std::atan2(y, x);
        return {radius, angle};
    }

    // Convert polar coordinates to Cartesian coordinates
    // Takes radius and angle as inputs and returns a pair of x and y
    static std::pair<double, double> polarToCartesian(double radius, double angle) {
        double x = radius * std::cos(angle);
        double y = radius * std::sin(angle);
        return {x, y};
    }
};
