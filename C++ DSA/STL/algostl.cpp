#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
    vi v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    cout<<"finding 6 : "<<binary_search(v.begin(),v.end(),6)<<endl;
    cout<<"lower bound  : "<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;
    cout<<"upper bound  : "<<upper_bound(v.begin(),v.end(),6)-v.begin()<<endl;

    int a=3;
    int b=5;
    cout<<"max : "<<max(a,b)<<endl;
    cout<<"min : "<<min(a,b);
    swap(a,b);
    cout<<endl<<a<<endl;
    string abcd = "abcd";
    reverse(abcd.begin(),abcd.end());
    cout<<"string : "<<abcd<<endl;
    rotate(v.begin(),v.begin()+1,v.end());
    cout<<"after rotate ";
    for(auto i:v){
        cout<<i<<endl;
    }cout<<endl;
    sort(v.begin(),v.end());// behind this sorting working is intro sort 3 sorting is mixed heap insertion  quick sort
    for(auto i:v){
        cout<<i<<endl;
    }

}