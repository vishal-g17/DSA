#include<iostream>
using namespace std;
int firstoccu(int arr[], int n, int key){
    int s=0, e=n-1;   //s=start e=end n=size
    int mid= s+((e-s)/2);
    int ans= -1;
    while(s<=e){
        if(arr[mid]==key){
             ans=mid;
             e=mid-1;
        }
        if(key>arr[mid]){//right me jaao
            s=mid+1;
        }
        if(key<arr[mid]){//left me jaao
            e=mid-1;
        }
        mid=s+((e-s)/2);
    }
    return ans;
}
int lastoccu(int arr[], int n, int key){
    int s=0, e=n-1;   //s=start e=end n=size
    int mid= s+((e-s)/2);
    int ans= -1;
    while(s<=e){
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        if(key>arr[mid]){//right me jaao
            s=mid+1;
        }
        if(key<arr[mid]){//left me jaao
            e=mid-1;
        }
        mid=s+((e-s)/2);
    }
    return ans;
}
int main(){
    int even[12]={1,2,3,3,3,3,3,3,3,3,3,5};
    cout<<"First Occurrrence of 3 is at index: "<<firstoccu(even,12,3)<<endl;
    cout<<"last Occurrrence of 3 is at index: "<<lastoccu(even,12 ,3)<<endl;
    cout<<"total Occurrrence of 3 : "<<(lastoccu(even,12 ,3)-firstoccu(even,12,3))+1<<endl;
}



