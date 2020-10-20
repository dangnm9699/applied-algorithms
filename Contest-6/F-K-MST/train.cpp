#include <bits/stdc++.h>
using namespace std;
#define author dangnm20172998
#define N 22
#define M 32

typedef pair<int, int> pii;
typedef pair<int, pii> pii_i;

int n, m, k;
vector<pii_i> edges;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(pii_i(w, pii(u, v)));
    }
    sort(edges.begin(), edges.end());

    return 0;
}