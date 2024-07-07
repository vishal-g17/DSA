#include<bits/stdc++.h>
using namespace std ; 

struct process{
    int id , at , bt , ct ;
} ;

signed main(){
    int n , c = 0 ;
    cout << "********First Come First Serve (FCFS) Scheduling********\n" ;
    cout<<"\t\tEnter the number of processes  " ;
    cin >> n ; 
    vector<process> v(n) ;
    for(auto &x : v){
        x.id = (++c) ; 
        cout <<"\nEnter arrival time : " ;
        cin >> x.at ;
        cout << "\nEnter burst time : " ;
        cin >> x.bt ;
    }
    sort(v.begin(),v.end(),[](const process &a , const process &b){
        return a.at < b.at ; 
    }) ;
    int t= 0  ;
    for(int i = 0 ; i < n ; ++i){
        if(t >= v[i].at){
            v[i].ct = t + v[i].bt ; 
            t = v[i].ct ;
        }
        else{
            v[i].ct = v[i].at + v[i].bt ; 
            t = v[i].ct ;
        }
    }
    cout << "\n********Completion Times********\n" ;
    for(auto &x : v){
        cout <<"\t\t" << x.id << " " << x.ct <<"\n" ;
    }   
}




#include<bits/stdc++.h>
using namespace std ; 

signed main(){
    int n , c = 0 ;
    cout << "********Shortest Job First Scheduling********\n" ;
    cout<<"\t\tEnter the number of processes  " ;
    cin >> n ; 
    vector<pair<int,int>> v(n) ;
    cout <<"Enter the burst times : \n" ; 
    for(int i =0 ; i < n ; ++i){
        cin >> v[i].first ;
        v[i].second = 1 + i ;
    }
    sort(v.begin(),v.end()) ;
    int t= 0  ;
    cout << "\n********Completion Times********\n" ;
    cout << "\nPID Completion Time : \n" ;
    for(int i = 0 ; i < n ; i++){
        t+=v[i].first ;
        cout <<v[i].second<<" -> " << t <<"\n" ;
    } 
}
This paste expires in <1 day. Public IP access. Share whatever you see with others in seconds with Context.Terms of ServiceReport this