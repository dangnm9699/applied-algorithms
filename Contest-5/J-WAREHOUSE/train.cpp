#include<bits/stdc++.h>

using namespace std;

int N,T,D;
int t[1001];
int a[1001];
int f[1001][101];

int main(){
    scanf("%d%d%d",&N,&T,&D);
    int res=0;
    for(int i=1;i<=N;++i) scanf("%d",a+i);
    for(int i=1;i<=N;++i) scanf("%d",t+i);    
    for(int i=1;i<=N;++i) if(t[i]<=T){
            f[i][t[i]]=a[i];
            res=max(res,a[i]);
    }
    for(int i=1;i<=N;++i){
        for(int j=i+1;j<=min(i+D, N);++j){
            for(int k=0;k<=T-t[j];++k){
                if(f[j][k+t[j]]<f[i][k]+a[j]){
                    f[j][k+t[j]] = f[i][k] + a[j];
                    res=max(res,f[j][k+t[j]]);
                }
            }
        }
    }
    printf("%d",res);
    return 0;
}