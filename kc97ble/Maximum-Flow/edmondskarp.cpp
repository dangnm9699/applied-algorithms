#include <stdio.h>
#include <queue>
using namespace std;

#define long long long
void minimize(int &a, int b)
{
    if (a > b)
        a = b;
}

int n, m, source, target;
vector<int> a[12309];
int c[2309][2309];
int f[2309][2309];
int d[12309];

bool findpath(int start, int target)
{
    queue<int> qu;
    for (int i = 1; i <= n; i++)
        d[i] = 0;
    d[start] = 1000111000;
    qu.push(start);

    while (qu.size())
    {
        int u = qu.front();
        qu.pop();
        //printf("u=%d\n", u);
        if (u == target)
            return true;
        for (int v : a[u])
            if (d[v] == 0 && c[u][v] > f[u][v])
            {
                d[v] = u;
                qu.push(v);
            }
    }
    return false;
}

void enlarge()
{
    int u, v, delta = 1000111000;
    for (v = target; (u = d[v]) != 1000111000; v = u)
        minimize(delta, c[u][v] - f[u][v]);
    for (v = target; v != source; v = u)
    {
        u = d[v];
        f[u][v] += delta;
        f[v][u] -= delta;
    }
}

long answer(int u)
{
    long r = 0;
    for (int v : a[u])
        r += f[u][v];
    return r;
}

main()
{
    scanf("%d%d%d%d", &n, &m, &source, &target);
    for (int i = 1; i <= m; i++)
    {
        int p, q, w;
        scanf("%d%d%d", &p, &q, &w);
        a[p].push_back(q);
        a[q].push_back(p);
        c[p][q] = w;
    }
    while (findpath(source, target))
        enlarge();

    printf("%lld\n", answer(source));
}