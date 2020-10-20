#include <bits/stdc++.h>

using namespace std;

int c[20], c1[40], c2[40], n;
int res;

void Try(int x)
{
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
            if (!c1[x + i - 1])
                if (!c2[n + x - i])
                {
                    c[i] = 1;
                    c1[x + i] = 1;
                    c2[n + x - i] = 1;
                    if (x == n)
                        res++;
                    else
                        Try(x + 1);
                    c2[n + x - i] = 0;
                    c1[x + i] = 0;
                    c[i] = 0;
                }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    Try(1);
    cout << res;
    return 0;
}