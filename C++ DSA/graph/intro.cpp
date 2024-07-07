#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>

template <typename T>
//isse kisi bhi data type ka grah bnana hai bs graph me mention krdo baar baar mention krne ki jrurat nhi
//kisi bhi type ka graph bna skte hai isse 

class graph {
    public:
    unordered_map<T, list<int>> adj;

    void addedge(int u, int v, bool direction){
        //direction 0 -> undirected
        //1 -> directed graph

        //create an edge from u -> v

        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printlist(){
        for(auto i:adj){
            cout<<i.first<<"->"; 
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cout<<"Enter no. of Nodes: "<<endl;
    cin>>n;

    int m;
    cout<<"Enter no. of Edges: "<<endl;
    cin>>m;

    graph <int>g;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //creating an unordered graph 
        g.addedge(u,v,0);
    }

    //printing
    g.printlist();
    
    return 0;
}