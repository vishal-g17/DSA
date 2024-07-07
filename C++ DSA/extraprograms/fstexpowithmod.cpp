#include<iostream>
using namespace std;

int fastExpo(int a, int b ,int x) {

    int res = 1;

    while(b > 0) {

        if(b&1) {
            //odd
            res = (1LL * res * (a)%x)%x;
        }
        a = (1LL * (a)%x * (a)%x)%x; 
        b = b >> 1; 
    }

    return res;
}

int main() {

    int a,b,x;
    cout << "Enter the Values of a and b and x" << endl;
    cin >> a >> b>>x;

    cout << "Answer is: " << fastExpo(a,b,x) << endl;

    return 0;
}