#include <bits/stdc++.h>

using namespace std;

#define N 5010

int n,k;
int mark[N];
vector<int> ke[N];
pair<int, int> w[N];
int dist[N][N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    mark[s]=1;
    dist[s][s]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:ke[u]){
            if(!mark[v]){
                mark[v]=1;
                dist[s][v] = dist[s][u] +1;
                q.push(v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        int c,d;
        cin>>c>>d;
        w[i].first=c;
        w[i].second=d;
    }
    for(int i=1;i<=k;++i){
        int u,v;
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    for(int i=1;i<=n;++i){
        memset(mark,0,sizeof(mark));
        bfs(i);
    }
    memset(mark,0,sizeof(mark));
    int ans[N];
    memset(ans, 63, sizeof(ans));
    ans[1] = 0;
    int step = n;
    while(step--){
        int minv = 0;
        for(int i=1;i<=n;++i){
            if(!mark[i]&&ans[minv]>ans[i]) minv=i;
        }
        mark[minv]=1;
        for(int i=1;i<=n;++i){
            if(dist[minv][i]<=w[minv].second)
                ans[i] = min(ans[i], ans[minv]+w[minv].first);
        }
    }
    cout<<ans[n];
    return 0;
}