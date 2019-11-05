#include <iostream>

using namespace std;

int fiborecur(int n);
int fibofor(int n);

int main(){
    int n;
    cout << "Ingrese numero" << endl;
    cin >> n;
    cout << fiborecur(n) << endl;
    cout << fibofor(n) << endl;
    return 0;
}

int fiborecur(int n){
    if(n==1){
        return 1;
    }
    else if (n==0){
        return 0;
    }
    return fiborecur(n-2) + fiborecur(n-1);
}

int fibofor(int n){
    int a=0, b=1;
    for(int i = 0; i<n;i++){
        int c = a;
        a += b;
        b = c;
    }
    return a;
}