#include <bits/stdc++.h>
 
using namespace std;

int n, m;
int c[17]; //course credit
int p[17][17]; //prerequisites
vector<int> check[6];
int start[17];
int sum[6] = {0,0,0,0,0,0}; // courses credit SUM
int res=1;

void Try(int k){
    if(k==n+1){
        int temp=0;
        for(int i=1;i<=m;i++) temp=max(temp,sum[i]);
        res=min(res,temp);
        return; 
    }
    for(int i=start[k];i<=m;i++){
        if(sum[i]+c[k]>=res) continue;
        int Ok=1;
        for(int j=0;j<check[i].size();j++){
            if(p[k][check[i][j]]) Ok=0;
        }
        if(Ok){
            check[i].push_back(k);
            sum[i]+=c[k];
            Try(k+1);
            check[i].pop_back();
            sum[i]-=c[k];
        }
    }
}
 
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> c[i];
        res+=c[i];
        start[i]=1;
    }
    int RES = res;
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> p[i][j];
            if(p[i][j]){
                start[j]=max(start[j], start[i]+1);
            }
        }
    }
    Try(1);
    if(res==RES) cout << -1;
    else cout << res;
    return 0;
}