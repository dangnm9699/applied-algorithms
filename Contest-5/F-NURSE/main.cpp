#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007;

int n,k1,k2;
int f[1001];

int main(){ 
    scanf("%d%d%d",&n,&k1,&k2);
    for(int i=k1;i<=k2;++i) f[i] = 1;
    f[0] = 1;
    for(int i=2;i<=n;++i){
        for(int j=k1;j<=k2;++j){
            if(i+j-1<=n) f[i+j-1] += f[i-2], f[i+j-1]%=mod;
        }
    }
    printf("%d",f[n]+f[n-1]);
    return 0;
}