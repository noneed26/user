#include <bits/stdc++.h>
using namespace std;

void lcs(string s1, string s2, int &length, string &sol)
{
    int m = s1.size();
    int n = s2.size();
    // vector initializes elements to 0 by default, so no need for the 0-loops
    vector<vector<int>> mat(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // Strings are 0-indexed, so we use i - 1 and j - 1
            if (s1[i - 1] == s2[j - 1])
            {
                mat[i][j] = mat[i - 1][j - 1] + 1;
            }
            else
            {
                mat[i][j] = max(mat[i][j - 1], mat[i - 1][j]);
            }
        }
    }

    length = mat[m][n]; // Set the final length

    // backtrack
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        // If characters match, it was part of the LCS
        if (s1[i - 1] == s2[j - 1])
        {
            sol += s1[i - 1];
            i--;
            j--;
        }
        // Otherwise, move in the direction of the larger value
        else if (mat[i - 1][j] > mat[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(sol.begin(), sol.end());
}

int main()
{
    string s1 = "assdfghj";
    string s2 = "ajhgsdf";
    string sol;
    int length = 0;

    lcs(s1, s2, length, sol);

    cout << "LCS is: " << sol << endl;
    cout << "Max length is: " << length << endl;

    return 0;
}