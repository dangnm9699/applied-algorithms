#include <bits/stdc++.h>
using namespace std;
#define author dangnm20172998
#define N 39
#define B 1000009

int n, b;
// a is weight, c is value of item
int a[N], c[N];
int f[N][B];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> b;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> c[i];
    }
    for (int i = 0; i <= b; ++i)
    {
        f[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= b; ++j)
        {
            f[i][j] = f[i - 1][j];
            if (j >= a[i])
                f[i][j] = max(f[i][j], c[i] + f[i - 1][j - a[i]]);
        }
    }
    cout << f[n][b];
    return 0;
}