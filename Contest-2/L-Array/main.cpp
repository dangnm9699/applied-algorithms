#include<bits/stdc++.h>

using namespace std;
int n;
int *a;

int main(){
    cin>>n;
    a=new int[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    cout<<1<<" "<<a[1]<<endl;
    if(a[n]>0){
        cout<<1<<" "<<a[n]<<endl;
        cout<<n-2;
        for(int i=2;i<n;i++) cout<<" "<<a[i];
    }else{
        cout<<2<<" "<<a[2]<<" "<<a[3]<<endl;
        cout<<n-3;
        for(int i=4;i<=n;i++) cout<<" "<<a[i];
    }
    return 0;
}