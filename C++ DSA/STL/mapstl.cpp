#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    unordered_map<int, string>m;
    m[1]= "vishal";
    m[13]= "gupta";
    m[-7]= "vicky";
    m.insert({5,"bheem"});
    // cout<<"before erase"<<endl;
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<"finding -13 : "<<m.count(-13)<<endl;
    m.erase(13);
    cout<<"after erase "<<endl;
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;

    }
    auto it = m.find(5);// bs ordered map k liye hai 
    // ye ye isse aage vale key pair print krega 
    for(auto i =it; i != m.end();i++){
        cout<<(*i).first<<endl;
    }
    if (m.find(5) != m.end()) {  //iska mtlb hai jise find me daal rhe hai vo map me hai ya nhi    does not equal to m.end mtlb map me hai
        cout<<"kv";
    }
    // cout<<m.size();
}