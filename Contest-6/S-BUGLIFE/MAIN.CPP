#include <bits/stdc++.h>

using namespace std;

#define N 2010

int n;
int mark[N];
int V, E;
vector<int> ke[N];
int is_2_phia;

void dfs(int u){
    for(int v: ke[u]){
        if(!mark[v]){
            if(mark[u]==1) mark[v]=2;
            if(mark[u]==2) mark[v]=1;
            dfs(v);
        }else if(mark[u]==mark[v]) is_2_phia=0;
    }
}

void check(){
    for(int i=1;i<=V;++i){
        if(!mark[i]){
            mark[i]=1;
            dfs(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int tc = 1;
    while(tc<=n){
        memset(mark, 0, sizeof(mark));
        is_2_phia = 1;
        cin>>V>>E;
        for(int i=1;i<=E;++i){
            int u,v;
            cin>>u>>v;
            ke[u].push_back(v);
            ke[v].push_back(u);
        }
        check();
        cout << "Scenario #" << tc << ":\n";
        if(is_2_phia) cout << "No suspicious bugs found!\n";
        else cout << "Suspicious bugs found!\n";
        for(int i=1;i<=V;++i) ke[i].clear();
        ++tc;
    }
    return 0;
}