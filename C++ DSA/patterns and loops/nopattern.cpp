#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;


    // code 1
    int row =1;
    while(row<=n){
        int col =1;
        int value =row;
        while(col<=row){
            cout<<value;
            value++;
            col++;
        }
        cout<<endl;
        row++;
    }


    // code 2
    int i=1;
    while(i<=n){
        int j =1;
        while(j<=i){
            cout<<(i-j+1);
            j++;
        }
        cout<<endl;
        i++;
    }

}