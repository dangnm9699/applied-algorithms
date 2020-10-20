#include<bits/stdc++.h>

using namespace std;
int n,l;
double a[1001];
double res=0.0;

int main(){
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;++i) scanf("%lf",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i){
        if(i==1) res=max(res,a[1]);
        else res=max(res,(a[i]-a[i-1])/2.0);
    }
    res=max(res,1.0*l-a[n]);
    printf("%.10lf",res);
    return 0;
}