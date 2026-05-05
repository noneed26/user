// min max

#include <bits/stdc++.h>
using namespace std;

struct ds
{
    int min;
    int max;
};

ds minmax(int l, int r, vector<int> &arr)
{
    ds result, leftResult, rightResult;

    if (l == r)
    {
        result.min = arr[l];
        result.max = arr[r];
        return result;
    }

    if (r == l + 1)
    {
        if (arr[l] < arr[r])
        {
            result.min = arr[l];
            result.max = arr[r];
        }
        else
        {
            result.min = arr[r];
            result.max = arr[l];
        }
    }

    int mid = (l + r) / 2;

    leftResult = minmax(l, mid, arr);
    rightResult = minmax(mid + 1, r, arr);

    result.min = std::min(leftResult.min, rightResult.min);
    result.max = std::max(leftResult.max, rightResult.max);

    return result;
}

int main()
{
    vector<int> arr = {2, 3, 1, 5, 6, 10, 100000, -11010101};

    int l = 0, r = arr.size() - 1;
    ds ans = minmax(l, r, arr);
    cout << ans.min << " " << ans.max << endl;

    return 0;
}

// T(n)=2T(n/2)+2
// 3n/2 - 1

// space is O(logn) -> call stack