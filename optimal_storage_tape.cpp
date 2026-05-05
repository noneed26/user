#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {2, 3, 8, 3, 5, 10};

    sort(arr.begin(), arr.end());

    int current_sum = 0; // Tracks sum up to the current file
    int total_time = 0;  // Total retrieval time for all files
    double ART = 0;      // Average retrieval time

    vector<int> sol;

    for (int i = 0; i < arr.size(); i++)
    {
        current_sum += arr[i];
        total_time += current_sum;
        sol.push_back(current_sum);
    }

    ART = (double)total_time / arr.size();

    cout << "Optimal Storage Order: ";
    for (int i : arr)
    {
        cout << i << " ";
    }

    cout << "\nCumulative Retrieval Times: ";
    for (int i : sol)
    {
        cout << i << " ";
    }

    cout << "\nTotal Minimum Retrieval Time (Total Time): " << total_time;
    cout << "\nAverage Retrieval Time (ART): " << ART << endl;

    return 0;
}