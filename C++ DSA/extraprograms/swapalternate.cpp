#include<iostream>
using namespace std;

int swapalt(int arr[], int size){
    for(int i=0; i<size; i=i+2){
        if(i+1<size){
            swap(arr[i],arr[i+1]);
        }
    } 
}
void printArray(int arr[], int n){
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int size;
    int arr[100];
    cin>>size;
    for(int i=0; i<size;i++){
        cin>>arr[i];
    }
    
    swapalt(arr,size);
    printArray(arr,size);
}

// swap func without inbuilt fn 
// for swap 2 numbers make a temp variable and store 2nd value in its 
// and then equate 1st and 2nd value then equate 1st and temp variable