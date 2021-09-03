#include <iostream>
#include <cmath>

class Rectangle: public Figure {
public:
    double a;
    double b;
    static Rectangle *make(std::string s) {
        double x, y;
        sscanf(s.c_str(), "%lf %lf", &x, &y);
        Rectangle *out = new Rectangle();
        out->a = x;
        out->b = y;
        return out;
    }
    double get_square() const {
        return a * b;
    }
};
class Square: public Figure {
public:
    double a;
    static Square *make(std::string s) {
        double x;
        sscanf(s.c_str(), "%lf", &x);
        Square *out = new Square();
        out->a = x;
        return out;
    }
    double get_square() const {
        return a * a;
    }
};
class Circle: public Figure {
public:
    double r;
    static Circle *make(std::string s) {
        double l;
        sscanf(s.c_str(), "%lf", &l);
        Circle *out = new Circle();
        out->r = l;
        return out;
    }
    double get_square() const {
        return M_PI * r * r;
    }
};
