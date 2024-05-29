
#include "named_colors.cpp"
#include <random>


// Color class with multiple constructors
class Color {
  public:
    double r, g, b, a;
    static Color random;

/***** ***** ***** ***** ***** *****
            CONSTRUCTORS
 ***** ***** ***** ***** ***** *****/

    Color() : Color(0,0,0) {}
    // Constructor for grayscale color
    Color(double _value)
        : Color(_value, _value, _value, 1.0f) {}
    // Constructor for RGB color
    Color(double _r, double _g, double _b)
        : Color(_r, _g, _b, 1.0f) {}
    // Main constructor for RGBA color
    Color(double _r, double _g, double _b, double _a)
        : r(_r), g(_g), b(_b), a(_a) {}
    // Constructor for named color
    Color(const std::string& colorName)
        : Color(colorName, 1.0f) {}
    Color(const std::string& colorName, double _a) 
    {
        auto it = namedColors.find(colorName);
        if (it != namedColors.end()) {
            r = std::get<0>(it->second);
            g = std::get<1>(it->second);
            b = std::get<2>(it->second);
            a = _a;
        } else {
            throw std::invalid_argument("Unknown color name");
        }
    }

/***** ***** ***** ***** ***** *****
              OPERATORS
 ***** ***** ***** ***** ***** *****/

    // Define the operator to get the opposite color
    Color operator~() const {
        return Color(1.0 - r, 1.0 - g, 1.0 - b, a);
    }

/***** ***** ***** ***** ***** *****
            RANDOM
 ***** ***** ***** ***** ***** *****/

    static Color generateRandomColor() {
        static std::random_device rd;  // Non-deterministic generator
        static std::mt19937 gen(rd()); // Seed the generator
        static std::uniform_real_distribution<> dis(0.0, 1.0);

        double _r = dis(gen);
        double _g = dis(gen);
        double _b = dis(gen);
        double _a = dis(gen);

        return Color(_r, _g, _b, _a);
    }

    static Color getRandom() {
        static std::random_device rd;  // Non-deterministic generator
        static std::mt19937 gen(rd()); // Seed the generator
        static std::uniform_real_distribution<> dis(0.0, 1.0);

        double _r = dis(gen);
        double _g = dis(gen);
        double _b = dis(gen);
        double _a = dis(gen);

        return Color(_r, _g, _b, _a);
    }
};


// Definition of static member
Color Color::random = Color::generateRandomColor();
