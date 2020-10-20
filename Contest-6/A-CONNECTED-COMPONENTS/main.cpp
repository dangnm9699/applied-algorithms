#include<bits/stdc++.h>
#define auth 5324172998DangNM

using namespace std;

const int N = 100003;

int n, m;
vector<int> ke[N];
bool mark[N];
int res = 0;

void dfs(int s){
    mark[s] = 1;
    for(int v:ke[s]){
        if(!mark[v]) dfs(v);
    }
}

void connectedComponents(){
    for(int i=1;i<=n;++i){
        if(!mark[i]) {
            dfs(i);
            ++res;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u, v;
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    connectedComponents();
    cout << res;
    return 0;
}