#include <bits/stdc++.h>
#define author dangnm20172998
#define N 100010
using namespace std;

int n, m;
vector<int> ke[N];
int bridges = 0;
int step = 0;
int articulation[N];
int low[N], num[N];

void dfs(int u, int p)
{
    int children = 0;
    low[u] = num[u] = ++step;
    for (int v : ke[u])
    {
        if (v != p)
        {
            if (num[v])
            {
                low[u] = min(low[u], num[v]);
            }
            else
            {
                ++children;
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= num[v])
                {
                    ++bridges;
                }
                if (u == p)
                {
                    if (children >= 2)
                    {
                        articulation[u] = 1;
                    }
                }
                else
                {
                    if (low[v] >= num[u])
                    {
                        articulation[u] = 1;
                    }
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!num[i])
        {
            dfs(i, i);
        }
    }
    int art_points = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (articulation[i])
        {
            ++art_points;
        }
    }
    cout << art_points << " " << bridges;
    return 0;
}