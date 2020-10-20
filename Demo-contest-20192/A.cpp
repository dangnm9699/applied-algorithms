#include<bits/stdc++.h>

using namespace std;

int t;
int n;
long long int res;
int x[1001],y[1001];


int main(){
    cin>>t;
    int dem=1;
    while(dem<=t){
        cin>>n;
        res=LONG_LONG_MAX;
        for(int i=1;i<=n;++i) cin>>x[i];
        for(int i=1;i<=n;++i){cin>>y[i];
        sort(x+1,x+n+1);
        sort(y+1,y+n+1);
        reverse(y+1,y+n+1);
        long long sum=0;
        for(int i=1;i<=n;++i) sum+= 1ll*x[i]*y[i];
        printf("Case #%d: %lld\n",dem,sum);
        ++dem;
    }
    return 0;
}