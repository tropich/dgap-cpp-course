
#pragma once

#include <string>

class creature
{
public:
    creature(const std::string name):
        m_name(name)
    {};

    virtual void speak() = 0;   // Should be defined in derived classes
    virtual std::string getName()
        { return m_name; };

private:
    const std::string m_name = "Unknown creature";
};


class dog: public creature
{
public:
    dog():
        creature("Dog Strelka")
    {};

    virtual void speak() override;
};

class cat: public creature
{
public:
    cat():
        creature("Cat Barsik")
    {};

    virtual void speak() override;
};

