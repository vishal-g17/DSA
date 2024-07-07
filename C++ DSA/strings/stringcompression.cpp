#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>

int compression(vector<char>& chars){
    int i=0;
    int ansindex =0;
    int n= chars.size();
    while(i<n){
        int j=i+1;
        while(j<n && chars[i]==chars[j]){
            j++;
        }
        //yaha kab aaoge
        //ya to vector piura traverse kr dia
        //ya fir new diff char encounter kuia hai

        //old char store krlo 
        chars[ansindex++]=chars[i];
        int count =j-1;
        if(count >1){
            //converting into single digit and saving in answer
            string cnt = to_string (count);
            for(char ch:cnt){
                chars[ansindex++]=ch;
            }
        }
        //moving to new char/ different char
        i=j;
    }
    return ansindex;  //size of answer vala array 
}
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
  
}