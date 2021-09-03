#include<iostream>
#include</home/MarF1/ejudge/4_SEM/up02/up02_1.h>
namespace numbers
{
    class complex_stack
    {
    private:
        size_t maxsiz, siz;
        complex *mass;
    public:
        complex_stack(size_t x = 100): maxsiz(x), siz(0)
        {
            mass = new complex[maxsiz];
        }
        ~complex_stack()
        {
            delete []mass;
        }
        complex_stack(const complex_stack &obj) 
        {
            maxsiz = obj.maxsiz;
            siz = obj.siz;
            mass = new complex[maxsiz];
            for (size_t i = 0; i < siz; i++) {
                mass[i] = obj.mass[i];
            }
        }
        const complex &operator[](int num) const
        {
            return mass[num];
        }
        size_t maxsize() const 
        {
            return maxsiz;
        }
        size_t size() const 
        {
            return siz;
        }
        void push(const complex &X) 
        {
            if (siz >= maxsiz) {
                maxsiz *= 2;
                complex *mass1 = new complex[maxsiz];
                for (size_t i = 0; i < siz; i++) {
                    mass1[i] = mass[i];
                }
                delete []mass;
                mass = mass1;
            }
            mass[siz++] = X;
        }
        complex pop()                         
        {
            complex out = this->mass[siz > 0 ? --siz : 0];
            return out;
        }
        friend complex_stack operator<<(const complex_stack &Y, const complex &X); 
        const complex operator+() const
        {
            complex out(this->mass[siz > 0 ? siz - 1 : 0]);
            return out;
        }
        complex_stack operator~() const
        {
            complex_stack out(*this);
            out.pop();
            return out;
        }
        complex_stack &operator=(const complex_stack &obj)
        {
            delete []mass;
            maxsiz = obj.maxsiz;
            siz = obj.siz;
            mass = new complex[maxsiz];
            for (size_t i = 0; i < siz; i++) {
                mass[i] = obj.mass[i];
            }
            return *this;
        }
    };
    complex_stack operator<<(const complex_stack &Y, const complex &X) 
    {
        complex_stack out(Y);
        out.push(X);
        return out;
    }
}
