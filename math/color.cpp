
#include "named_colors.cpp"

// Color class with multiple constructors
class Color {
  public:
    double r, g, b, a;

    // Constructor for grayscale color
    Color(double _value)
        : Color(_value, _value, _value, 1.0f) {}

    // Constructor for RGB color
    Color(double _r, double _g, double _b)
        : Color(_r, _g, _b, 1.0f) {}

    // Main constructor for RGBA color
    Color(double _r, double _g, double _b, double _a)
        : r(_r), g(_g), b(_b), a(_a) {}

    Color(const std::string& colorName)
        : Color(colorName, 1.0f) {}

    // Constructor for named color
    Color(const std::string& colorName, double _a) {
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
};

