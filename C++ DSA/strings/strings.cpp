#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>

int length(char arr[]){
    int count =0;
    for(int i=0; arr[i]!= '\0';i++){
        count++;
    }
    return count;
}
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
   char arr[20];
   cin>>arr;
   arr[3]='\0';
   cout<<length(arr);

}