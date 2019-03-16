
#include <iostream>
#include "creatures.h"

using std::cout;
using std::endl;

void dog::speak()
{
    cout << "Gav" << endl;
}

void cat::speak()
{
    cout << "Meow" << endl;
}

int main()
{
    dog d;
    cout << d.getName() << endl;

    creature *c = new cat;
    cout << c->getName() << " says: ";
    c->speak();

}

