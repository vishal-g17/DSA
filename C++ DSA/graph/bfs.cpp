#include <bits/stdc++.h> 
using namespace std;
void prepareADJlist(unordered_map<int, set<int>> &adjlist, vector<pair<int, int>> &edges){
    for(int i=0; i<edges.size();i++){
        int u= edges[i].first;
        int v= edges[i].second;

        adjlist[u].insert(v);
        adjlist[v].insert(u);

    }
}



void bfs(unordered_map<int, set<int>> &adjlist, unordered_map<int,bool>visited, vector<int> &res, int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        // store frontNode into res
        res.push_back(frontNode);

        //traverse all neighbours of frontnOde
        for(auto i : adjlist[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

vector<int>BFS (int vertex, vector<pair<int, int>> edges){
    unordered_map<int, set<int>> adjlist;
    vector<int> res;
    unordered_map<int, bool> visited;

    prepareADJlist(adjlist, edges);


    //traverse all components of graph
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjlist, visited, res, i);
        }
    }
    return res;
}

//ptani kyu ni c hl rh ah