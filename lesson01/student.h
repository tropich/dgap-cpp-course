
#pragma once
// We need this directive to prevent multiple including of this file

#include <iostream>

class Student {
public:
	Student(int age);
	void Print();

protected:
	int grade;
private:
	std::string name;
	int age;
	bool male;
};

class Physicist {
public:
    // In-class method declaration
	void PrintPi()
    {
        std::cout << pi << std::endl;
    };
	
private:
	int age;
    static const double pi;
};

// Declare class with multiple inheritance
class StudentFopf: private Student, public Physicist  {
public:
	// overloaded constructors
	StudentFopf();
	StudentFopf(int _obshaga);

	// destructor - no arguments
	~StudentFopf();

    // Const method couldn't change object
	void PrintFopf() const;

    // static method - not connected with any object, so can't use non-static members
	static void Hello();   
    // static member - single per class type
	static int faculty;

private:
    // private members couldn't be accessed outside of class methods
	int obshaga;
};



