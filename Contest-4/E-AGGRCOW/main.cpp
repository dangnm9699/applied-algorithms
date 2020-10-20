#include<bits/stdc++.h>

using namespace std;

int t;
int n,c;
long long int x[100001];

int main(){
    scanf("%d",&t);
    while(t--){
        long long res=0;
        scanf("%d%d",&n,&c);
        for(int i=1;i<=n;++i) scanf("%lld",&x[i]);
        sort(x+1,x+n+1);
        long long int lo=0,mid,hi=x[n];
        while(lo<=hi){
            mid=(lo+hi)/2;
            int cow=1;
            long long int cur=x[1];
            for(int i=2;i<=n;++i){
                if(x[i]-cur>=mid){
                    ++cow;
                    cur=x[i];
                }
            }
            if(cow>=c){
                res=max(res,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}