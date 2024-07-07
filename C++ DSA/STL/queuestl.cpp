#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<string>q;
    q.push("vishal");
    q.push("gupta");
    q.push("vicky");
    cout<<"size of stack before pop : "<<q.size()<<endl;

    cout<<"1st element : "<<q.front()<<endl;
    q.pop();
    cout<<"top element : "<<q.front()<<endl;
    cout<<"size of stack afyter pop : "<<q.size()<<endl;
    cout<<"empty or not : "<<q.empty()<<endl;

}