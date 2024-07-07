#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>

bool chkequal(int a[26], int b[26]){
    for(int i=0;i<26;i++){
        if(a[i]!=b[i]){
            return 0;
        }
        else {
            return 1;
        }
    }
}
bool chkinclusion(string s1, string s2){
    //character count araay
    int count1[26]={0};
    for(int i=0; i<s1.length();i++){
        int index = s1[i]-'a';
        count1[index]++;
    }
    //traverse s2 string in window of size s1 length  and compare
    int i=0;
    int windowsize = s1.length();
    int count2[26]={0};

    //running or first window
    while(i<windowsize && i<s2.length()){
        int index = s2[i]-'a';
        count2[index]++;
        i++;
    }
    if(chkequal(count1, count2)){
        return 1;
    }

    //aage window process kro
    while(i<s2.length()){
        char newchar = s2[i];
        int index = newchar - 'a';
        count2[index]--;
        i++;
        if(chkequal(count1, count2)){
            return 1;
        }
        else{
            return 0;
        }
    }

}
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
   //good logical thinking que give time this
    
    return 0;
}