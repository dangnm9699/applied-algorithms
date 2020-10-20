#include <bits/stdc++.h>

using namespace std;

int n, k, q;
int d[11];
stack<int> route[11];
int load[6];
int res=0;
int dvd = 1000000007;

int gt(int n){
    if (n==0||n==1) return 1;
    else return n*gt(n-1);
}

void Try(int x){
    if(x==n+1){
        for(int i=1;i<=k;i++) if(route[i].empty()) return;
        int temp=1;
        for(int i=1;i<=k;i++){
            temp=temp*gt(route[i].size());
        }
        res+=temp;
        return;
    }
    for(int i=1;i<=k;i++){
        if(load[i]-d[x]>=0){
            route[i].push(x);
            load[i]-=d[x];
            Try(x+1);
            route[i].pop();
            load[i]+=d[x];
        }
    }
}

int main(){
    cin>>n>>k>>q;
    int isOK=1;
    for(int i=1;i<=n;i++) {
        cin>>d[i];
        if(d[i]>q) isOK=0;
    }
    for(int i=1;i<=k;i++){
        load[i]=q;
    }
    if (isOK) Try(1);
    /*
    Do mỗi bộ bị lặp lại bởi hoán vị nên phải chia tổng có được cho k!
    */
    res=res/gt(k);
    cout << res%dvd;
    return 0;
}