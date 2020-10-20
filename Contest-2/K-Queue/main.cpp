#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int dP[n];
    pair<int,int> ageAndIndex[n];
    for(int i=0;i<n;++i){
        cin>>ageAndIndex[i].first;
        ageAndIndex[i].second=i;
    }
    sort(ageAndIndex, ageAndIndex+n);
    int index=INT_MIN;
    for(int i=0;i<n;++i){
        dP[ageAndIndex[i].second] = max(-1,index-ageAndIndex[i].second-1);
        index=max(index, ageAndIndex[i].second);
    }
    for(int i=0;i<n-1;++i) cout<<dP[i]<<" ";
    cout<<dP[n-1];
    return 0;
}