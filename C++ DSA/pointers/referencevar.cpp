#include<iostream>
using namespace std;

int& func(int a) {// this fn gives error as it type is ref var but returns a local var this is bad practice
    int num = a;
    int& ans = num;
    return ans;
}

int* fun(int n) {
    int* ptr = &n;// same here it also givr error as it returns local var
    
    return ptr;
}

void update2(int& n) {
    n++;
}

void update1(int n) {
    n++;
}

int main() {

    /*
    int i = 5;

    //create a ref variable 

    int& j = i;

    cout << i << endl; 
    i++;
    cout << i << endl; 
    j++;
    cout << i << endl; 
    cout << j << endl;
    */

   int n = 5;
   
   cout << "Before " << n << endl;
   update2(n);
   cout << "After " << n << endl;


    fun(n);

    return 0;
}