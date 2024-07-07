#include <bits/stdc++.h>
using namespace std;

#define ll long long int 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int A;
        int B;
        if(c%2!=0){
            A= a+ (c/2)+1;
            B= b+ c/2;
        }
        else{
            A= a+ c/2;
            B= b+ c/2;
        }
        if(A>B){
            cout<<"First"<<endl;
        }
        else{
            cout<<"Second"<<endl;
        }
    }

    return 0;
}
