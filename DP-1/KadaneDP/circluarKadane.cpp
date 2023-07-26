#include <bits/stdc++.h>
using namespace std;

int NormalMaxSum(vector<int> &arr, int n)
{
    int max_sum = arr[0];
    int res = arr[0];
    for (int i = 1; i < n; i++)
    {
        max_sum = max(max_sum + arr[i], arr[i]);
        res = max(max_sum, res);
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int max_normal = NormalMaxSum(arr, n);
    // cout<<max_normal;
    int total = 0;
    if (max_normal < 0)
        cout << max_normal;
    else
    {
        for (int i = 0; i < n; i++)
        {
            total += arr[i];
            arr[i] = -arr[i];
        }
        int inverted_max_normal = NormalMaxSum(arr, n);
        int max_circular = total + inverted_max_normal;
        // cout<<max_circular;

        cout << max(max_circular, max_normal);
    }
    return 0;
}