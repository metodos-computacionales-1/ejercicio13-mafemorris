#include <iostream>

using namespace std;

int getMax( int a, int b);
double getMax( double a, double b);

int main(){
    cout << getMax(0.1,0.7) << endl;
    cout << getMax(8,1) << endl;
    return 0;
}

int getMax( int a, int b){
    if(a>b){
        return a;
    }
    return b;
}

double getMax( double a, double b){
    if(a>b){
        return a;
    }
    return b;
}


