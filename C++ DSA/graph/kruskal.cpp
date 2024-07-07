#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void makeset(vector<int> &parent, vector<int> &rank, int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findparent(vector<int> &parent, int node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = findparent(parent, parent[node]);
    // Path compression logic
}

void unionset(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findparent(parent, u);
    v = findparent(parent, v);

    if (u != v) {
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[v] < rank[u]) {
            parent[v] = u;
        } else {
            // If ranks are equal, choose one as the parent and increment its rank
            parent[v] = u;
            rank[u]++;
        }
    }
}

bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

int minimumSpanningTree(vector<vector<int>> &edges, int n) {
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent, rank, n);

    int minweight = 0;

    for (int i = 0; i < edges.size(); i++) {
        int u = findparent(parent, edges[i][0]);
        int v = findparent(parent, edges[i][1]);
        int wt = edges[i][2];

        if (u != v) {
            minweight += wt;
            unionset(u, v, parent, rank);
        }
    }
    return minweight;
}