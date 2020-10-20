#include<bits/stdc++.h>

#define for0n for(int i=0;i<n;++i)

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int p[n];
    for0n scanf("%d",&p[i]);
    int valid=0;
    for (int i=n-2;i>=0;--i){
        if(p[i]<p[i+1]){
            valid=1;
            int pos = i+1;
            for(int j=i+1;j<n;++j){
                if(p[j]>p[i]){
                    if(p[j]<p[pos]) pos=j;
                }
            }
            swap(p[i], p[pos]);
            reverse(p+i+1,p+n);
            break;
        }
    }
    if(valid) for0n printf("%d ",p[i]);
    else printf("-1");
    return 0;
}