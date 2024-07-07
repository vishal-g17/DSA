#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v; //vector<int>a(5,1) mtlb size of vector is 5 and all places are assigned by 1
    //cout<<"print a"<<endl;
    //for(int i:a){
        // cout<<i<<" ";
    // }

    //printing vector

    //ab agr ek ais avector bnau jisme iske saare elemnts aa jae
    // simply vector<int>last(a);
    //cout<<"print last"<<endl;
    //for(int i:last){
        // cout<<i<<" ";
    // }cout<<endl;


    // cout<<"capacity: "<<v.capacity()<<endl;
    v.push_back(1);
    // cout<<"capacity: "<<v.capacity()<<endl;
    v.push_back(2);
    // cout<<"capacity: "<<v.capacity()<<endl;
    int b=7;
    v.push_back(b);
    // cout<<"capacity: "<<v.capacity()<<endl;
    // cout<<"size : "<<v.size()<<endl;
    v.pop_back();
    for(int i:v){
        cout<<i<<" ";
    }
    //push back end se enter krta hai elements and push_front aage se enter
    //pop_back end se elemnt delete krta h
    //on clearing vector only size gets zero not capacity bcoz it assigned
}