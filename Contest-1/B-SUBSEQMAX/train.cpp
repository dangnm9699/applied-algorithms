#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000009];
int res = INT_MIN;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
        if (sum > res)
            res = sum;
        if (sum < 0)
            sum = 0;
    }
    cout << res;
    return 0;
}