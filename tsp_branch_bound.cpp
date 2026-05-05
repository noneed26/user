#include <bits/stdc++.h>
using namespace std;

int N; // Number of cities
int final_res = INT_MAX;

void copyToFinal(vector<int>& curr_path, vector<int>& final_path) {
    for (int i = 0; i < N; i++) final_path[i] = curr_path[i];
    final_path[N] = curr_path[0];
}

int firstMin(vector<vector<int>>& adj, int i) {
    int min_val = INT_MAX;
    for (int k = 0; k < N; k++)
        if (adj[i][k] < min_val && i != k) min_val = adj[i][k];
    return min_val;
}

int secondMin(vector<vector<int>>& adj, int i) {
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < N; j++) {
        if (i == j) continue;
        if (adj[i][j] <= first) { second = first; first = adj[i][j]; }
        else if (adj[i][j] <= second && adj[i][j] != first) second = adj[i][j];
    }
    return second;
}

void TSPRec(vector<vector<int>>& adj, int curr_bound, int curr_weight, int level,
            vector<int>& curr_path, vector<bool>& visited, vector<int>& final_path) {
    if (level == N) {
        if (adj[curr_path[level - 1]][curr_path[0]] != 0) {
            int curr_res = curr_weight + adj[curr_path[level - 1]][curr_path[0]];
            if (curr_res < final_res) {
                copyToFinal(curr_path, final_path);
                final_res = curr_res;
            }
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (adj[curr_path[level - 1]][i] != 0 && !visited[i]) {
            int temp = curr_bound;
            curr_weight += adj[curr_path[level - 1]][i];

            if (level == 1) curr_bound -= ((firstMin(adj, curr_path[level - 1]) + firstMin(adj, i)) / 2);
            else curr_bound -= ((secondMin(adj, curr_path[level - 1]) + firstMin(adj, i)) / 2);

            if (curr_bound + curr_weight < final_res) {
                curr_path[level] = i;
                visited[i] = true;
                TSPRec(adj, curr_bound, curr_weight, level + 1, curr_path, visited, final_path);
            }

            curr_weight -= adj[curr_path[level - 1]][i];
            curr_bound = temp;
            visited[i] = false;
        }
    }
}

int main() {
/*
Sample Input:
4
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
*/
    cout << "Enter number of cities (N): ";
    cin >> N;
    
    vector<vector<int>> adj(N, vector<int>(N));
    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> adj[i][j];
        }
    }
    
    vector<int> curr_path(N + 1, -1), final_path(N + 1, -1);
    vector<bool> visited(N, false);
    
    int curr_bound = 0;
    for (int i = 0; i < N; i++)
        curr_bound += (firstMin(adj, i) + secondMin(adj, i));
    curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 : curr_bound / 2;

    visited[0] = true;
    curr_path[0] = 0;

    TSPRec(adj, curr_bound, 0, 1, curr_path, visited, final_path);

    cout << "Minimum cost: " << final_res << "\nPath: ";
    for (int i = 0; i <= N; i++) cout << final_path[i] << " ";
    cout << "\n";
    return 0;
}

// Time Complexity: O(N!)
// Space Complexity: O(N)
