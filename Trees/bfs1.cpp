#include <bits/stdc++.h>
using namespace std;

// BFS function to compute distance from 'start' to all nodes
vector<int> bfs(int start, vector<vector<int>>& adj, int n) {
    vector<int> dist(n, -1);      // distance array
    queue<int> q;

    dist[start] = 0;              // distance to itself = 0
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {          // not visited
                dist[v] = dist[u] + 1;    // update distance
                q.push(v);
            }
        }
    }
    return dist;
}

int countSpecialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {

    // Step 1: Build adjacency list
    vector<vector<int>> adj(n);
    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    // Step 2: Get distances from x, y, z
    vector<int> dx = bfs(x, adj, n);
    vector<int> dy = bfs(y, adj, n);
    vector<int> dz = bfs(z, adj, n);

    // Step 3: Check Pythagorean condition
    int count = 0;
    for (int i = 0; i < n; i++) {
        int a = dx[i], b = dy[i], c = dz[i];

        // sort three numbers manually
        vector<int> d = {a, b, c};
        sort(d.begin(), d.end());

        if (d[0]*d[0] + d[1]*d[1] == d[2]*d[2]) {
            count++;
        }
    }

    return count;
}

// ----------------- MAIN (for testing) -----------------
int main() {
    int n = 4;
    vector<vector<int>> edges = {{0,1},{0,2},{0,3}};
    int x = 1, y = 2, z = 3;

    cout << countSpecialNodes(n, edges, x, y, z);
    return 0;
}
