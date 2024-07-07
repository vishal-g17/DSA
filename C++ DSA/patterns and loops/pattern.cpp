#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    // code 1
    int i=1;
    while(i<=n){
        int j = 1;
        while(j<=n){
            cout<<j;   //use n-j+1 for reverse printing
            j++;
        }
        cout<<endl;
        i++;
    }

    // code 2
    int row =1;
    while(row<=n){
        char ch='A'+row-1;
        int col =1;
        while(col<=n){
            cout<<ch;
            col++;
        }
        cout<<endl;
        row++;
    }
}