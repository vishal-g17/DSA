#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    set<int>s;
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(6);
    s.insert(0);
    s.insert(0);
    s.insert(0);
    //set takes only once 0 1 5 6  and in order gives 
    for(auto i:s){
        cout<<i<<endl;
    }cout<<endl;
    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);
    for(auto i:s){
        cout<<i<<endl;
    }

    cout<<endl;
    cout<<"5 is present or not : "<<s.count(5)<<endl;
    set<int>::iterator itr = s.find(5);
    for(auto it = itr; it != s.end();it++){//mtlb jo hm find me dete hai us eye reference maan leta hai usse start krta hai counting ya element printing
        cout<<*it<<" ";
        cout<<endl;
    }
}