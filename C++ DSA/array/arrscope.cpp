#include<iostream>
using namespace std;
void update(int arr[], int n){
    cout<<"Inside the fn"<<endl;

    arr[0]= 120;

    for(int i=0;i<3;i++){
     
        cout<<arr[i]<<" ";
    }cout<<endl;

    cout<<"Going back to main fn";
}
int main(){
    int arr[3]= {1,2,3};
    update(arr,3);

    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


// fn with array jab bhi kro to update mt krna kyuki ye main arr me bhi changes kr deta h bcoz let say arr[3] update krte hai to isme arr jo hai vo base index bhi to dikhata hai 
// jiska mtlb arr[0] hota h...isliye changes main me bhi hi jaate hai   yaad rkhna ye bs base add diya hai array nhi diya h