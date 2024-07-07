#include<iostream>
#include<list>
using namespace std;
int main(){
   list<int>l;
    // list<int>n(l);//copying old ist in new list or
    list<int>n(5,100);//size is 5 na dinitialise by 100 each
    cout<<"printing n"<<endl;
    for(int i:n){
        cout<<i<<" "<<endl;
    }
   l.push_back(1);
   l.push_front(2);
   for(int i:l){
    cout<<i<<" ";
   }
    cout<<endl;
    l.erase(l.begin());
    cout<<"after erase"<<endl;
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<"size of list"<<l.size()<<endl;
}