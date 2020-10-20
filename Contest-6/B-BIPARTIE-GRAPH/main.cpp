#include<bits/stdc++.h>

#define auth 5324172998DangNM
#define N 100010
using namespace std;

int n,m;
vector<int> ke[N];
int label[N];
int res = 1;

void dfs(int u){
    for(int v:ke[u]){
        if(!label[v]){
            if(label[u]==1) label[v]=2;
            if(label[u]==2) label[v]=1;
            dfs(v);
        }else if(label[v]==label[u]) res=0;
    }
}

int isBipartiteGraph(){
    for(int i=1;i<=n;++i){
        if(!label[i]){
            label[i] = 1;
            dfs(i);
        }
    }
    return res==1?1:0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    cout<<isBipartiteGraph();
    return 0;
}