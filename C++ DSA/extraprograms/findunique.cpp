#include<iostream>
using namespace std;
int unique(int arr[],int size){
    int ans;
    for(int i =0; i<size;i++){
        ans = ans ^ arr[i];   //using logic of xor kyuki xor,same hone pe zero de deta h
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<unique(arr,n);
    
}