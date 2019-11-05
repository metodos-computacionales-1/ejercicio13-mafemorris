#include <iostream>
int subtraction(int a, int b)
{
    int r;
    r=a-b;
    return r;
}

int main()
{
    int x=5,y=3,z;
    z=subtraction(7,2);
    std::cout<< "The first result is " <<z<<"\n";
    std::cout<< "The second result is " <<subtraction(7,2)<<"\n";
    std::cout<< "The third result is " <<subtraction(x,y)<<"\n";
    z=4+subtraction(x,y);
    std::cout<< "The fourth result is " <<z<<"\n";
    std::cout<< "La x es " << &x << ", la y es "<< &y << " y el de z es " << &z<< "\n";
    return 0;
}