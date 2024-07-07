#include<iostream>
using namespace std;
int findduplicate(vector<int> &arr){
    int ans =0;
    for(int i =0;i<arr.size();i++){
        ans = ans^arr[i];
    }
    //xor[1,n-1]
    for(int i =1;i<arr.size();i++){
        ans = ans^1;
    }
    return ans;
}
int main(){
    
}