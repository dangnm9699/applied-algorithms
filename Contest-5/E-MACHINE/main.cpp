#include<bits/stdc++.h>
#define mp make_pair

using namespace std;

int n;
pair<int,int> p[2000001];
int f[2000001]; // max C t[i]

int main(){
    scanf("%d",&n);
    int max_t = 0;
    for(int i=1;i<=n;++i) {
        scanf("%d%d",&p[i].first,&p[i].second);
        max_t = max(max_t, p[i].second);
    }
    sort(p+1,p+1+n);
    fill(f,f+n+1,0);
    for(int i=1;i<=n;++i){
        f[p[i].second] = max(p[i].second-p[i].first, f[p[i].second]);
    }
    f[0]=0;
    int res = -1;
    for(int i=1;i<=max_t;++i) f[i] = max(f[i], f[i-1]);
    for(int i=1;i<=n;++i){
        if(f[p[i].first-1]!=0) res = max(res, f[p[i].first-1]+p[i].second-p[i].first);
    }
    cout << res;
    return 0;
}