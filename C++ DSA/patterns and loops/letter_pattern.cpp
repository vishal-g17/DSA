#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int row=1;

    // code 1
    // while(row<=n){
    //     int col=1;
    //     while(col<=row){
    //         char ch= ('A'+row-1);
    //         cout<<ch;
    //         col++;
    //     }
    //     cout<<endl;
    //     row++;
    // }


    // code 2
    while(row<=n){
        int col=1;
        char start = 'A'+n-row;
        while(col<=row){
            cout<<start;
            start++;
            col++;
        }
        cout<<endl;
        row++;
    }
}