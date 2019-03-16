/*
 * CPP program to illustrate 
 * concept of Virtual Functions 
 */

#include<iostream> 
using namespace std; 

// Abstract class, contain pure virtual methods
// Can't be instantiated
class base 
{ 
public: 
    // Destructor should be virtual (for classes with virt methods)
    virtual ~base()
    { cout<< "destruct base class" <<endl; }

    // Pure virtual method
	virtual void print () = 0;

	void show () 
	{ cout<< "show base class" <<endl; } 
}; 

class derived:public base 
{ 
public: 
    virtual ~derived()
    { cout<< "destruct derived class" <<endl; }

    // Codeword to emphasize that we override base method
	virtual void print () override 
	{ cout<< "print derived class" <<endl; } 

	void show () 
	{ cout<< "show derived class" <<endl; } 
}; 

class der2:public base 
{ 
public: 
    virtual ~der2()
    { cout<< "destruct der2 class" <<endl; }

	virtual void print () override 
	{ cout<< "print der2 class" <<endl; } 

	void show () 
	{ cout<< "show der2 class" <<endl; } 
}; 


int main() 
{ 
    /*
     * Simple example
     */
	base *bptr = new derived;

	//virtual function, binded at runtime 
	bptr->print(); 
	// Non-virtual function, binded at compile time 
	bptr->show(); 
    delete bptr;

    /*
     * More complicated example with array
     */
    const unsigned size = 8;
    base *array[size];

    // Fill array of pointers by some pattern
    // with objects of different classes
    for (int i = 0; i < size; i++)
        if (i % 3 == 0)
            array[i] = new derived;
        else
            array[i] = new der2;

    for (int i = 0; i < size; i++)
        array[i]->print();  // Virtual methods, different output
    for (int i = 0; i < size; i++)
        array[i]->show();   // Non-virtual methods, same output

    for (int i = 0; i < size; i++)
        delete array[i];    // delete objects one-by-one, same as we created them

    // operator new[] allows creation of objects with same type
    int *ia = new int[size]();
    delete[] ia;

    return 0;
} 

