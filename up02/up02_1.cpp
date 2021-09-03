#include <iostream>
#include <cmath>

    class complex
    {
    private:
        double x, y;
    public:
        complex(double a_r = 0, double a_i = 0): x(a_r), y(a_i)
        {
        }
        explicit complex(const std::string str)
        {
            sscanf(str.c_str(), "%lf,%lf", &x, &y);
        }
        std::string to_string() const
        {
            char buf[300];
            sprintf(buf, "(%.10g,%.10g)", x, y);
            std::string str(buf);
            return str;
        }
        double re() const
        {
            return x;
        }
        double im() const
        {
            return y;
        }
        double abs() const
        {
            return sqrt(x * x + y * y);
        }
        double abs2() const
        {
            return (x * x + y * y);
        }
        complex &operator+=(const complex &obj2)
        {
            x += obj2.x; 
            y += obj2.y;
            return *this;
        }
        complex &operator-=(const complex &obj2)
        {
            x -= obj2.x;
            y -= obj2.y;
            return *this;
        }
        complex &operator*=(const complex &obj2)
        {
            double help = x;
            x = x * obj2.x - y * obj2.y;
            y = help * obj2.y + y * obj2.x;
            return *this;
        }
        complex &operator/=(const complex &obj2)
        {
            double help = x, znam = (obj2.x * obj2.x + obj2.y * obj2.y);
            x = (x * obj2.x + y * obj2.y) / znam;
            y = (y * obj2.x - help * obj2.y) / znam;
            return *this;
        }
        friend complex operator+(const complex &obj1, const complex &obj2);
        friend complex operator-(const complex &obj1, const complex &obj2);
        friend complex operator*(const complex &obj1, const complex &obj2);
        friend complex operator/(const complex &obj1, const complex &obj2);
        friend complex operator~(complex obj);
        friend complex operator-(complex obj);
    };
    
    complex operator+(const complex &obj1, const complex &obj2)
    {
        complex out(obj1.x, obj1.y);
        out += obj2;
        return out;
    }
    complex operator-(const complex &obj1, const complex &obj2)
    {
        complex out(obj1.x, obj1.y);
        out -= obj2;
        return out;
    }
    complex operator*(const complex &obj1, const complex &obj2)
    {
        complex out(obj1.x, obj1.y);
        out *= obj2;
        return out;
    }
    complex operator/(const complex &obj1, const complex &obj2)
    {
        complex out(obj1.x, obj1.y);
        out /= obj2;
        return out;
    }
    complex operator~(complex obj)
    {
        complex out(obj.x, -obj.y);
        return out;
    }

    complex operator-(complex obj)
    {
        complex out(-obj.x, -obj.y);
        return out;
    }
int main(){}     
