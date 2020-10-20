#include <bits/stdc++.h>
using namespace std;
#define author dangnm20172998
#define N 100009

int n, m;
vector<int> ke[N], bridge[N];
long long int res = 0, temp = 0;
int step = 0;
int num[N], low[N], parent[N];

void findBridge(int u)
{
    num[u] = low[u] = ++step;
    for (int v : ke[u])
    {
        if (!num[v])
        {
            parent[v] = u;
            findBridge(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[v])
            {
                bridge[u].push_back(v);
                bridge[v].push_back(u);
            }
        }
        else if (parent[u] != v)
        {
            low[u] = min(low[u], num[v]);
        }
    }
}

void dfs(int u)
{
    num[u] = 1;
    ++temp;
    for (int v : bridge[u])
    {
        if (!num[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
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

            findBridge(i);
        }
    }
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= n; ++i)
    {
        if (bridge[i].size() > 0)
        {
            if (!num[i])
            {
                dfs(i);
                res += (temp - 2) * (temp - 1) / 2;
                temp = 0;
            }
        }
    }
    cout << res;
    return 0;
}
