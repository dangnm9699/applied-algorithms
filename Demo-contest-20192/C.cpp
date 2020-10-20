#include<bits/stdc++.h>
using namespace std;
int n,m,M;
int Q=0;
int main(){
    cin>>n>>m>>M;
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int temp=a[i];
        if(temp>=m&&temp<=M) ++Q;
        for(int j=i+1;j<=n;++j){
            temp+=a[j];
            if(temp>M)continue;
            if(temp>=m&&temp<=M) ++Q;
        }
    }
    cout<<Q;
    return 0;
}