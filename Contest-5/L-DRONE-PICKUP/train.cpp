#include<bits/stdc++.h>

using namespace std;

int n,k;
int a[3001],c[3001],f[3001][101];

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i) scanf("%d", c+i);
    for(int i=1;i<=n;++i) scanf("%d", a+i);
    int res = -1;
    f[1][0] = c[1];
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=min(i+a[i], n);++j){
            for(int p=1;p<=k;++p){
                if(f[i][p-1]&&f[j][p]<f[i][p-1]+c[j]){
                    f[j][p] = f[i][p-1] + c[j];
                }
            }
        }
    }
    for(int i=1;i<=k;++i) res = max(res, f[n][i]);
    if(res) printf("%d",res);
    else printf("-1");
    return 0;
}