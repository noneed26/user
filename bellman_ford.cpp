#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};

void printPath(vector<int>& parent, int j) {
    if (parent[j] == -1) {
        cout << j;
        return;
    }
    printPath(parent, parent[j]);
    cout << " -> " << j;
}

void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    vector<int> dist(V, 1e9);
    vector<int> parent(V, -1);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;
            if (dist[u] != 1e9 && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        if (dist[u] != 1e9 && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }

    cout << "Vertex\tDistance\tPath\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\t\t";
        printPath(parent, i);
        cout << "\n";
    }
}

int main() {
/*
Sample Input:
5 8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
0
*/
    int V, E, src;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<Edge> edges(E);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    cout << "Enter source vertex: ";
    cin >> src;
    bellmanFord(V, E, edges, src);
    return 0;
}

// Time Complexity: O(V * E)
// Space Complexity: O(V)
