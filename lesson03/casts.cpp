/*
 * Examples of basic casts:
 * dynamic_cast
 * static_cast
 * reinterpret_cast
 * const_cast
 */

#include <iostream>
#include <typeinfo>

using namespace std;

class base
{
public:
	int b;
	virtual void f() {};
};

class derived: public base
{
public:
	int d;
	virtual void f() {};
};

void f(base b)
{

}


void func(derived *d)
{
	d->d++; // Changing actually const object... Don't do that
}

// const_cast could change constness of variable
// very dangerous, not recommended
void constfunc(const derived *cd)
{
    // We should 100% know that func() will not change object
	func(const_cast<derived *>(cd));
}

int main()
{
	base B;
	derived D;
	
	f(D);	    // implicit cast
	f((base)D);	// explicit C-style cast
	D.d = 3;

    {
        base *pb = &D;  // derived object works as base object
                        // so this pointer points to inherited part of derived class
        derived *pd;

        // Dynamic cast checks in RUNTIME
        // that pointed object is compatible with class derived
        pd = dynamic_cast<derived *>(pb);
        pd->d++;    // works fine

        // typeid feature allows us to get type info in runtime
        cout << typeid(*pb).name() << endl;

        std::string *ps;
        // Try to cast incompatible types...
        ps = dynamic_cast<std::string *>(pb);
        // Fail, we got NULL pointer
        if (ps == NULL)
            cout << "Incorrect cast" << endl;
    }

    {
        base *pb = &D;
        derived *pd;

        // Static cast checks in COMPILETIME
        // that pointed object is compatible with class derived
        pd = static_cast<derived *>(pb);
        pd->d++;    // works fine

        cout << pd->d << endl;

        // This could lead to undefined behaviour (incorrect cast)
        pd = static_cast<derived *>(&B);
        //pd->d++;    // UNDEFINED behaviour (pd points to incorrect object)
    }

	string s;
    // Very powerfyl and very dangerous cast:
    // could cast anything to anything
	long *pl = reinterpret_cast<long*>(&s);
    // Of course, this could lead to undefined behaviour

    // Check const_cast
    constfunc(&D);

	return 0;
}

