#include <bits/stdc++.h>
#define author dangnm20172998
#define N 100009
#define M 1000000000

using namespace std;

int n, m;
vector<int> ke[N];
stack<int> comp;
int res = 0;
int step = 0;
int num[N], low[N], connect[N];

void scc(int u)
{
    low[u] = num[u] = ++step;
    comp.push(u);
    connect[u] = 1;
    for (int v : ke[u])
    {
        if (!num[v])
        {
            scc(v);
            low[u] = min(low[u], low[v]);
        }
        else if (connect[v])
        {
            low[u] = min(low[u], num[v]);
        }
    }
    if (num[u] == low[u])
    {
        ++res;
        int v;
        do
        {
            v = comp.top();
            comp.pop();
            connect[v] = 0;
        } while (v != u);
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
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!num[i])
        {
            scc(i);
        }
    }
    cout << res;
    return 0;
}