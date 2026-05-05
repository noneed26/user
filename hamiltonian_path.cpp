#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& path, int pos) {
    if (graph[path[pos - 1]][v] == 0) return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v) return false;
    return true;
}

void hamiltonianNonRecursive(vector<vector<int>>& graph, int V) {
    vector<int> path(V, -1);
    path[0] = 0; 
    int pos = 1;

    while (pos >= 1) {
        bool found = false;
        while (path[pos] < V - 1) {
            path[pos]++;
            if (isSafe(path[pos], graph, path, pos)) {
                found = true;
                break;
            }
        }
        
        if (found) {
            if (pos == V - 1) {
                cout << "Hamiltonian Path: ";
                for (int i = 0; i < V; i++) cout << path[i] << " ";
                cout << "\n";
                // Backtrack to find more paths if needed, or break.
                break;
            } else {
                pos++;
                path[pos] = -1;
            }
        } else {
            path[pos] = -1;
            pos--;
        }
    }
}

int main() {
/*
Sample Input:
5
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 1
0 1 1 1 0
*/
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < V; ++i) {
        for(int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }
    hamiltonianNonRecursive(graph, V);
    return 0;
}

// Time Complexity: O(N!)
// Space Complexity: O(N)
