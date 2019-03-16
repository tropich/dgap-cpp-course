
#include <iostream>


class Complex
{
public:
    Complex();
    Complex(float re, float im = 0.0);
    Complex(const Complex &copy);
    ~Complex();

    float abs();
    Complex conj();

    Complex& operator=(const Complex &c);
    Complex& operator+=(const Complex &c);

    // overload this operators:
    // +, -, *(Complex), /(Complex), *(float)
    // >>, <<
private:
    float re;
    float im;
};

