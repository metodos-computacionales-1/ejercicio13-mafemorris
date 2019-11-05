#include <iostream>
#include <cmath>
int main(int argc, char **argv)
{
    int N=atoi(argv[1]); //casting to int
    double array[N];
    for(int i =0;i<=N;i++)
    {
        array[i]=i;
    }
    return 0;
}