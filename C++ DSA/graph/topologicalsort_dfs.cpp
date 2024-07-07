#include <bits/stdc++.h>
using namespace std;

void toposort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj) {
    visited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            toposort(neighbour, visited, s, adj);
        }
    }

    // Important: push the node to the stack after visiting all its neighbours
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    // Create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // Call dfs topological sort until for all components
    // unordered_map<int, bool> visited;  // Changed from list<int> to bool
    // map gives TLE, use vector
    vector<bool> visited(v);
    stack<int> s;
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {  // Corrected condition
            toposort(i, visited, s, adj);
        }
    }

    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

