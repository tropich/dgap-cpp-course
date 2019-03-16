
#include <iostream>

// Another usage of codeword "using"
using std::cout;
using std::endl;

class Complex 
{
public:
	int re;
};

// const ref argument could receive both lvalue and rvalue,
// but nonconst ref could receive only lvalue
void f(const Complex &c)
{
	cout << "const Complex" << endl;
}

#if 1
// Overload function to receive rvalue argument
// could be used without const modifier
void f(const Complex &&c)
{
	cout << "rval Complex" << endl;
}
#endif

int main()
{
	Complex c;

	f(c);   // lvalue
	f(Complex());   // rvalue

	return 0;
}

