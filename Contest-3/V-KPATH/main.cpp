#include<bits/stdc++.h>

using namespace std;

#define mp make_pair

int n,k,m, res=0;
vector<int> ke[31];
int mark[31];
vector<int> path;

void Try(int x, vector<int> &p){
    if(x==k+2){
        ++res;
        return;
    }
    if(p.empty()){
        int be = 1;
        while(be<=n){
            p.push_back(be);
            mark[be] = 1;
            Try(x+1, p);
            p.pop_back();
            mark[be] = 0;
            ++be;
        }
    }else{
        int last = p.back();
        for(int i=0;i<ke[last].size();++i){
            if(!mark[ke[last][i]]){
                p.push_back(ke[last][i]);
                mark[ke[last][i]] = 1;
                Try(x+1, p);
                p.pop_back();
                mark[ke[last][i]] = 0;
            }
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&k,&m);
    memset(mark,0,sizeof(mark));
    int u, v;
    for(int i=1;i<=m;++i){
        scanf("%d%d",&u,&v);
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    Try(1, path);
    printf("%d",res/2);
    return 0;
}