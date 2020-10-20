#include <bits/stdc++.h>

using namespace std;

int n,m;
int c[21][21];
int path[21];
int visited[21];
int cmin=INT_MAX;
int best=INT_MAX;

void Try(int k, int sum){
    if(k==n+1){
        if(sum+c[path[n]][1]<best) best=sum+c[path[n]][1];
        return;
    }
    for(int i=2;i<=n;i++){
        if(!visited[i]){
            if(sum+c[path[k-1]][i]+cmin*(n-k+1)<best){
                visited[i]=1;
                path[k]=i;
                Try(k+1, sum+c[path[k-1]][i]);
                visited[i]=0;
            }
        }
    }
}

int main () {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        visited[i]=0;
        for(int j=1;j<=n;j++){
            i==j?c[i][j]=0:c[i][j]=1999999;
        }
    }
    for(int i=1;i<=m;i++){
        int from, to, cost;
        cin>>from>>to>>cost;
        c[from][to]=cost;
        cmin=min(cmin, c[from][to]);
    }
    path[1]=1;
    visited[1]=1;
    Try(2, 0);
    cout<<best;
    return 0;
}