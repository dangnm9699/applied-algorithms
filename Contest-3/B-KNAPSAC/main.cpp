#include <bits/stdc++.h>

using namespace std;

int n,b;
int a[31], c[31];
int best=0;

void Try(int i,int val){
    if(i>n){
        if(val>best) best=val;
        return;
    }
    int nums=0;
    if(b>=a[i]) nums=1;
    for(int j=0;j<=nums;j++){
        b-=j*a[i];  
        Try(i+1, val+j*c[i]);
        b+=j*a[i];
    }
}

int main(){
    cin>>n>>b;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    Try(1,0);
    cout<<best;
    return 0;
}