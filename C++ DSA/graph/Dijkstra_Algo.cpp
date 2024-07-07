#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>

// class graph{
//     public:
//     unordered_map<int,list<pair<int,int>>>adj;

//     void addEdge(int u, int v, int weight){
//         pair<int,int> p = make_pair(v, weight);
//         adj[u].push_back(p);
//     }

//     void printAdj(){
//         for(auto i: adj){
//             cout<<i.first<<"->";
//             for(auto j: i.second){
//                 cout<<"("<<j.first<<","<<j.second<<"), ";
//             }cout<<endl;
//         }
//     }

//     void dfs(int node, unordered_map<int, bool> &vis, stack<int> &topo){
//         vis[node] = true;

//         for(auto neighbour : adj[node]){
//             if(!vis[neighbour.first]){
//                 dfs(neighbour.first, vis, topo);
//             }
//         }
//         topo.push(node);
//     }

//     void getshortestpath(int src, vector<int> &dist, stack<int> &topo){
//         dist[src]=0;

//         while(!topo.empty()){
//             int top = topo.top();
//             topo.pop();

//             if(dist[top] != INT_MAX){
//                 for(auto i: adj[top]){
//                     if(dist[top] + i.second < dist[i.first]){
//                         dist[i.first] = dist[top] + i.second;
//                     }
//                 }
//             }
//         }
//     }
// };

// int main() {

//     graph g;
//     g.addEdge(0,1,5);
//     g.addEdge(0,2,3);
//     g.addEdge(1,2,2);
//     g.addEdge(1,3,6);
//     g.addEdge(2,3,7);
//     g.addEdge(2,4,4);
//     g.addEdge(2,5,2);
//     g.addEdge(3,4,-1);
//     g.addEdge(4,5,-2);

//     g.printAdj();

//     int n=6;
//     //topo sort
//     unordered_map<int, bool> visited;
//     stack<int>s;
//     for(int i=0;i<n;i++){
//         if(!visited[i]){
//             g.dfs(i,visited,s);
//         }
//     }

//     int src=1;
//     vector<int> dist(n);

//     for(int i=0;i<n;i++){
//         dist[i] = INT_MAX;
//     }

//     g.getshortestpath(src, dist, s);

//     cout<<"answer is :"<<endl;

//     for(int i=0;i<dist.size();i++){
//         cout<<dist[i]<<" ";
//     }cout<<endl;

//     return 0;
// }


vector<int>dijkstra(vector<vector<int>>&vec, int vertices, int edges, int source){
    unordered_map<int, list<pair<int, int>>>adj;
    for(int i=0; i<edges; i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];

        adj[u].push_back(make_pair(v,w));
    }

    vector<int>dist(vertices);
    for(int i=0; i<vertices; i++){
        dist[i] = INT_MAX;
    }

    set<pair<int, int>>st;

    dist[source]=0;
    st.insert(make_pair(0, source));

    while(!st.empty()){
        //fetch top record
        auto top = *(st.begin());//hmne priority queue ki jgah set use kia hai isme ye method hota hai smallest nikane ka

        int nodeDist = top.first;
        int topNode = top.second;

        //remove top record
        st.erase(st.begin());

        //traverse on neighbours
        for(auto neighbour : adj[topNode]){
            if(nodeDist + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                if(record != st.end()){
                    st.erase(record);
                }

                //distance update
                dist[neighbour.first] = nodeDist + neighbour.second;
                //record push in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}