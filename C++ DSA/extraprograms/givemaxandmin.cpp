#include<iostream>
#include<math.h>
using namespace std;

int getmin(int num[], int n){
   
    int mini = INT_MIN;

    for(int i = 0; i<n; i++){
        mini = min(mini , num[i]);
        return mini;
    }
}
int getmax(int num[], int n){

    int maxi = INT_MAX;

    for(int i = 0; i<n; i++){
        maxi = max(maxi , num[i]);
        return maxi;
    }
}

int main(){
    int size;
    cin>>size;
    int num[10];
    for(int i=0; i<size; i++){
        cin>>num[i];
    }
    cout<<"max value is "<< getmax(num,size)<<endl;
    cout<<"min value is "<< getmin(num,size)<<endl;
    return 0;
    
}