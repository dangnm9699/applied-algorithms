#include<bits/stdc++.h>

using namespace std;
int n,k;
int a[5001];
int Q=0;

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n-2;++i){
        for(int j=i+1;j<=n-1;++j){
            int lo = j + 1, hi = n;
            int kTemp = k-a[i]-a[j];
            if(kTemp>a[n]) continue;
            while(lo<=hi){
                int mid=(lo+hi)/2;
                if(a[mid]==kTemp){
                    ++Q;
                    break;
                }else if(a[mid]>kTemp){
                    hi = mid - 1;
                }else lo = mid + 1;
            }
        }
    }
    printf("%d", Q);
    return 0;
}