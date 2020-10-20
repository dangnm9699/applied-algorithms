#include<bits/stdc++.h>
using namespace std;
int n;
int deep=0, high=0;
int main(){ 
    cin>>n;
    int a[n], order[n];
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=1;i<n;++i){
        if(a[i]>a[i-1]) order[i]=1;
        else if(a[i]<a[i-1]) order[i]=-1;
        else order[i]=0;
    }
    for(int i=1;i<n;++i){
        if(order[i]==0)continue;
        int left=1, right=0;
        for(int j=i+1;j<n;++j){
            if(order[j]==0) break;
            if(order[j]==order[j-1]){
                if(order[j]==order[i]) ++left;
                else ++right;
            }else{
                if(order[j]==order[i]) break;
                ++right;
            }
        }
        if(order[i]<0&&left&&right) deep=max(deep, min(left, right));
        if(order[i]>0&&left&&right) high=max(high, min(left, right));
    }
    cout<<high<<" "<<deep;
    return 0;
}