#include<iostream>
using namespace std;
// mountain array means in form of mountain like first increasing then decreasing sofind its peak  "^"
//mountain array pehle increasing sorted then deecreasing sorted so hm binary search use kr skte h
//vaise hm kisi quew me binary ya linear search kuch bhi use kr skte h pr for time complexity we use more binary search O(logn)  
int peakindex(int arr[], int n){
    int s= 0;
    int e= n-1;
    int mid = s +(e-s)/2;
    while(s<e){
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}
int main(){
    int arr[4]={3,4,5,1};
    cout<<"peak index is :"<<peakindex(arr,4);

}