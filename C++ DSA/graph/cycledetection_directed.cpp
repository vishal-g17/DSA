#include<bits/stdc++.h>

using namespace std;

bool checkCycledfs(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, unordered_map<int, list<int>>& adj) {
    visited[node] = true;
    dfsvisited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            bool cycledetected = checkCycledfs(neighbour, visited, dfsvisited, adj);
            if (cycledetected) {
                return true;
            }
        }else if (dfsvisited[neighbour]) {
            return true;
        }
    }

    dfsvisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    // Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // Call DFS for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;//kyuki ye directed graph hai direction matters
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bool cyclefound = checkCycledfs(i, visited, dfsvisited, adj);
            if (cyclefound) {
                return true;
            }
        }
    }
    return false;
}