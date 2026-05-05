#include <bits/stdc++.h>
using namespace std;

void knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "Maximum value: " << dp[n][W] << "\n";
    cout << "Items included (0-indexed): ";
    
    int res = dp[n][W], w = W;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res != dp[i - 1][w]) {
            cout << (i - 1) << " ";
            res -= val[i - 1];
            w -= wt[i - 1];
        }
    }
    cout << "\n";
}

int main() {
/*
Sample Input:
3 50
60 10
100 20
120 30
*/
    int n, W;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> W;
    vector<int> val(n), wt(n);
    cout << "Enter value and weight for each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> val[i] >> wt[i];
    }
    knapsack(W, wt, val, n);
    return 0;
}

// Time Complexity: O(N * W)
// Space Complexity: O(N * W)
