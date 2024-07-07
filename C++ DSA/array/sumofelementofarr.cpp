#include<iostream>
using namespace std;
// sum of elements of array

int sum(int arr[], int size){
    int sum=0;
    for(int i =0; i<size;i++){
        sum = arr[i] +sum;
    }
    return sum;
}

int main(){
    int size ;
    cin>>size;

    int arr[100];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    cout<<"Sum of elements of array is : "<< sum(arr, size);
}