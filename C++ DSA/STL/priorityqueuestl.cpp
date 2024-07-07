#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    //max heap
    priority_queue<int>maxi;
    //min heap
    priority_queue<int, vi, greater<int>>mini;

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);
    cout<<"size : "<<maxi.size()<<endl;
    int n = maxi.size();
    //loop me jb bina n k direct likha to ans me bs 3 2 aaya and jab n likha to 3 2 1 0 sb aaya
    //bcoz on loop maxi.size is changing continuously and we dont want to change it thats why use n
    for(int i=0; i<n;i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }cout<<endl;
    return 0;
    //similar for mini

}