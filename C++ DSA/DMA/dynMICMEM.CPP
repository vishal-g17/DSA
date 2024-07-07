#include<iostream>
using namespace std;

int getSum(int *arr, int n) {

    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    } 
    return sum;
}

int main() {

    int n;
    cin >> n;
    
    //variable size array
    int* arr = new int[n];

    //takign inputn in aray
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ans = getSum(arr, n);

    cout << "answer is "<< ans << endl;

//case 1
    while(true) {
        int i = 5;// is loop me baar baar var create hoga or dlt hoga after loop ends
    }
    
//case 2
    while(true) {
        int* ptr = new int;// isme heap me bnta hai to dlt nhi hota after loop ends and ye continuously new bnata rhega
        //program crash
    }




    return 0;
}