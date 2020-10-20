#include <bits/stdc++.h>
using namespace std;

int n;
int sol;
int C[31], sumHC[60], subHC[60];

void Try(int row)
{
    if (row == n + 1)
    {
        ++sol;
        return;
    }
    for (int col = 1; col <= n; ++col)
    {
        if (!C[col] && !sumHC[row + col - 1] && !subHC[row - col + n])
        {
            C[col] = 1;
            sumHC[row + col - 1] = 1;
            subHC[row - col + n] = 1;
            Try(row + 1);
            C[col] = 0;
            sumHC[row + col - 1] = 0;
            subHC[row - col + n] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    Try(1);
    printf("%d", sol);
    return 0;
}