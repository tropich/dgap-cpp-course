
#include <iostream>

class base
{
public:
	virtual base* getThis() { std::cout << "base" << std::endl; return this; };

};

class derived: public base
{
public:
    // Same method, but different return type. It is called "covariant return type".
    // If a derived class method returns a more-derived type than its overridden
    // base class method, the derived class return type is said to be covariant.
	virtual derived* getThis() {  std::cout << "der" << std::endl; return this; };

};

int main()
{
	base *pb;
	derived *pd;
	int type;
	std::cin >> type;

	if (type)
		pb = new derived;
	else
		pb = new base;
    
    // This is not allowed, because compiler always assumes return type as base*,
    // as it don't know actual virtual method that will be used.
    pd = pb->getThis();

    // So we need to properly cast such return values
	pd = dynamic_cast<derived*>(pb->getThis());

    // If pb was a pointer to base object, than we got null
	std::cout << (pd ? "pointer" : "null") << std::endl;

	return 0;
}
