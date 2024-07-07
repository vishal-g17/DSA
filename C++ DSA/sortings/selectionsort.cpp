#include<iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int>& arr, int n)
{   
    for(int i = 0; i < n-1; i++ ) {
        int minIndex = i;
        
        for(int j = i+1; j<n; j++) {
            
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
            
        }
       
        swap(arr[minIndex], arr[i]);
    }
}

int main(){

    vector<int>arr;
    // for(int i =0; ;i++){
    //     if(i <0){
    //         break;
    //     }
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(7);
    arr.push_back(2);
    arr.push_back(10);
    for(int i:arr){
        cout<<i<<" ";
    }
    selectionSort(arr,arr.size());
    for(int i =0; i<arr.size();i++){
        cout<<endl<<arr[i]<<" ";
    }

}
//selection sort me sbse chota elemnt sbse pehle then.....