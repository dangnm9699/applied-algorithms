#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define f1(i, n) for (int i = 1; i <= n; i++)
typedef pair<int, int> ii;
#define X first
#define Y second

#define N 100005
int n, m;
vector<ii> a[N];
int d[N];

bool minimize(int &a, int b)
{
    if (a > b)
        a = b;
    else
        return false;
    return true;
}

int dijkstra(int Start, int Target)
{
    priority_queue<ii> qu;
    qu.push(ii(0, Start));
    f1(i, n) d[i] = 0x44445555;
    d[Start] = 0;

    while (qu.size())
    {
        ii top = qu.top();
        qu.pop();
        int u = top.Y, du = -top.X;
        if (du != d[u])
            continue;
        if (u == Target)
            return d[u];

        for (int i = 0, v; v = a[u][i].Y; i++)
            if (minimize(d[v], d[u] + a[u][i].X))
                qu.push(ii(-d[v], v));
    }
    return -1;
}

main()
{
    int Start, Target;
    cin >> n >> m >> Start >> Target;
    f1(i, n) a[i].clear();
    f1(i, m)
    {
        int p, q, w;
        cin >> p >> q >> w;
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
    }
    f1(i, n) a[i].push_back(ii());

    int Answer = dijkstra(Start, Target);
    cout << Answer << endl;
    cin.ignore(3);
}