
#include <iostream>
#include "operators.h"

using namespace std;


// Define static class members
const double Physicist::pi = 3.141593;
int StudentFopf::faculty = 2;

// Define Student methods
Student::Student(int age_)
{
	age = age_;
}

void Student::Print()
{
	cout << "I'm Student" << endl;
}

// Define StudentFopf methods
StudentFopf::StudentFopf(): // Initialization list:
	Student(18),            // construct base classes or class members
	obshaga(6)
{
}

StudentFopf::StudentFopf(int _obshaga):
	Student(18),
	obshaga(_obshaga)
{
}

StudentFopf::~StudentFopf()
{
	// free all resources
}

void StudentFopf::PrintFopf() const
{
	cout << "I'm FOPF" << faculty << endl;
}

// static method
void StudentFopf::Hello()
{
	cout << "Hello Physics!" << faculty << endl;
}


StudentFopf StudentFopf::operator+(int a)
{
	StudentFopf f;  // construct, fill and return new object
	f.obshaga = obshaga + a;
	return f;
}

StudentFopf StudentFopf::operator+(const StudentFopf &s2)
{
	StudentFopf f;  // construct, fill and return new object
	f.obshaga = obshaga + s2.obshaga;
	return f;
}

// friend function, same result
StudentFopf operator+(StudentFopf &s1, StudentFopf &s2)
{
	StudentFopf f;  // construct, fill and return new object
	f.obshaga = s1.obshaga + s2.obshaga;
	return f;
}


ostream& operator<<(ostream &os, const StudentFopf &s2)
{
	os << "I'm FOPF from " << s2.obshaga;
	return os;  // Don't forget to return input stream object
}


int main()
{
	Student st1(20);
	st1.Print();
	
	StudentFopf stf;
	stf.PrintFopf();
	stf();

    // Dynamic instantiation - allocates memory on a heap
    // and constructs object there
    StudentFopf *pstf = new StudentFopf(6);
	pstf->PrintFopf();

	StudentFopf stf_sum = stf + *pstf;
	cout << stf_sum << endl;
    // Same output, but there we need correct const/rvalue arguments
    // in overloaded operator<<
	cout << stf + *pstf << endl;    

    // allocate and delete array of objects
	StudentFopf *stfAr = new StudentFopf[10];
	cout << stfAr[2] << endl;    
	delete[] stfAr;

    // Don't forget about deleting objects!
    delete pstf;
	return 0;
}

