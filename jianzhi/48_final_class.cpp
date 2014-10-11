#include <iostream>

using namespace std;

// first solution uses c++11 `final` keyword
class Base final
{
public:
    Base() {}
};

class Derived : public Base
{
public:
    Derived() {}
};

// second solution uses	`virtual inheritance` and `friend`
template <typename T>
class MakeFinal
{
private :
    friend T;
    MakeFinal() {}
    ~MakeFinal() {}
};

class FinalClass : virtual public MakeFinal<FinalClass>
{
public :
    FinalClass() {}
    ~FinalClass() {}
};

class Test : public FinalClass
{
};

int main(int argc, char *argv[])
{
    Derived d1;
    Test t;
    return 0;
}
