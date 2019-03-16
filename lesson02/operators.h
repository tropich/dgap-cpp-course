
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
	void PrintPi()
    {
        std::cout << pi << std::endl;
    };
	
private:
	int age;
    static const double pi;
};

// multiple public inheritance
class StudentFopf: public Student, public Physicist  {
public:
	// overloaded constructors
	StudentFopf();

    // Forbid implicit conversion from int
    // Only explicit conversion or direct construction allowed
	explicit StudentFopf(int _obshaga); 

	~StudentFopf();

	void PrintFopf() const;

    /*
     * Overloaded operators for user class
     */
	StudentFopf operator+(int a);   // StudentFopf + int
    // StudentFopf + StudentFopf:
	StudentFopf operator+(const StudentFopf &s); // class member
	friend StudentFopf operator+(StudentFopf &s1, StudentFopf &s2); // friend function, same result

	void operator()() { PrintFopf(); }; // braces operator

    // overload to print our class to stream
	friend std::ostream& operator<<(std::ostream &os, const StudentFopf &s2);

	static void Hello();   

	static int faculty;

private:
	int obshaga;
};

