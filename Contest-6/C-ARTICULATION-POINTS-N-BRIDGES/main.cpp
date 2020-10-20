#include <bits/stdc++.h>
#define auth 5324172998DangNM
using namespace std;

#define N 100010

int n, m;
vector<int> ke[N];
int bridge = 0;
int articulation[N];
int num[N], low[N], step = 0;

void dfs(int cur, int pre)
{
    int n_ke = 0;
    low[cur] = num[cur] = ++step;
    for (int v : ke[cur])
    {
        if (v != pre)
        {
            if (num[v])
            {
                low[cur] = min(low[cur], num[v]);
            }
            else
            {
                ++n_ke;
                dfs(v, cur);
                low[cur] = min(low[cur], low[v]);
                if (low[v] >= num[v])
                    ++bridge;
                if (cur == pre)
                {
                    if (n_ke >= 2)
                        articulation[cur] = 1;
                }
                else
                {
                    if (low[v] >= num[cur])
                        articulation[cur] = 1;
                }
            }
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
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        if (!num[i])
            dfs(i, i);
    int nodes = 0;
    for (int i = 1; i <= n; ++i)
        if (articulation[i])
            ++nodes;
    cout << nodes << " " << bridge;
    return 0;
}