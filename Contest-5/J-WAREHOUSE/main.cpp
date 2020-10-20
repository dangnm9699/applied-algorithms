#include<bits/stdc++.h>

using namespace std;

int N,T,D;
int a[1001];
int t[1001];
int g[1001][101];
int res=0;

int dp(int location, int time){
    if(g[location][time]<0){
        if(time<T){
            for(int i=1;i<=D;++i){
                if(location-i>=1&&time+t[location-i]<=T) g[location][time] = max(g[location][time], dp(location-i, time+t[location-i]) + a[location]);
            }
        }else if(time==T){
            g[location][time] = a[location];
        }else{
            g[location][time] = 0;
        }
    }
    return g[location][time];
}

int main(){
    scanf("%d%d%d",&N,&T,&D);
    for(int i=1;i<=N;++i) scanf("%d",&a[i]);
    for(int i=1;i<=N;++i) scanf("%d",&t[i]);
    for(int i=1;i<=N;++i) {
        memset(g,-1,sizeof(g));
        res=max(res, dp(i, t[i]));
    }
    cout << res;
    return 0;
}