#include <bits/stdc++.h>

using namespace std;

int n, l1, l2;
int a[100001];
int f[100001];
// O(n + n*(l2-l1) + n) ~ O(n^2)
int main()
{
    scanf("%d%d%d", &n, &l1, &l2);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        f[i] = a[i];
    }
    for (int i = l1 + 1; i <= n; ++i)
    {
        for (int j = l1; j <= l2; ++j)
        {
            if (i - j >= 1)
                f[i] = max(f[i], f[i - j] + a[i]);
            else
                break;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = max(res, f[i]);
    printf("%d", res);
    return 0;
}