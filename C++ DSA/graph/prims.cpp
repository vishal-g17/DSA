// #include <bits/stdc++.h>
// using namespace std;

// vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
// {
//     // create adj list
//     unordered_map<int, list<pair<int, int>>> adj;

//     for (int i = 0; i < g.size(); i++)
//     {
//         int u = g[i].first.first;
//         int v = g[i].first.second;
//         int w = g[i].second;
//         adj[u].push_back(make_pair(v, w));
//         adj[v].push_back(make_pair(u, w));
//     }

//     vector<int> key(n + 1);
//     vector<bool> mst(n + 1);
//     vector<int> parent(n + 1);

//     for (int i = 0; i <= n; i++)
//     {
//         key[i] = INT_MAX;
//         parent[i] = -1;
//         mst[i] = false;
//     }

//     // lets start algo
//     key[1] = 0;
//     parent[1] = -1;

//     for (int i = 0; i < n; i++)
//     {
//         int mini = INT_MAX;
//         int u = -1; // initialize u

//         // find mini vali node
//         for (int v = 1; v <= n; v++)
//         {
//             if (mst[v] == false && key[v] < mini){
//                 mini = key[v];
//                 u = v;
//             }
//         }

//         // mark mini node as true
//         mst[u] = true;

//         // check its adjacent nodes
//         for (auto it : adj[u])
//         {
//             int v = it.first;
//             int w = it.second;
//             if (mst[v] == false && w < key[v]){
//                 parent[v] = u;
//                 key[v] = w;
//             }
//         }
//     }

//     vector<pair<pair<int, int>, int>> result;
//     for (int i = 2; i <= n; i++)
//     {
//         result.push_back({{parent[i], i}, key[i]});
//     }
//     return result;
// }



#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Initialize key, mst, and parent arrays
    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // Priority queue to select the edge with the minimum weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Starting vertex key set to 0
    key[1] = 0;
    pq.push({0, 1}); // {key, vertex}

    while (!pq.empty()) {
        // Extract the vertex with the minimum key value
        int u = pq.top().second;
        pq.pop();

        // Include the extracted vertex in the MST
        mst[u] = true;

        // Update the key values of the adjacent vertices
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if (!mst[v] && w < key[v]) {
                parent[v] = u;
                key[v] = w;
                pq.push({key[v], v});
            }
        }
    }

    // Prepare the result
    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}

int main() {
    int n = 5, m = 6;
    vector<pair<pair<int, int>, int>> g = {
        {{1, 2}, 3},
        {{1, 3}, 4},
        {{2, 3}, 2},
        {{2, 4}, 7},
        {{3, 4}, 1},
        {{4, 5}, 5}
    };

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, g);
    for (auto edge : mst) {
        cout << "Edge: " << edge.first.first << " - " << edge.first.second << " with weight " << edge.second << endl;
    }

    return 0;
}
