#include<bits/stdc++.h>

#define mp make_pair
#define x first
#define y second

using namespace std;

int n;
pair<int, int> p[50000];

bool compare_x(pair<int,int> a, pair<int,int> b){
    return a.x<b.x;
}

bool compare_y(pair<int,int> a, pair<int,int> b){
    return a.y<b.y;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int h, v;
        scanf("%d%d",&h,&v);
        p[i] = mp(h,v);
    }
    return 0;
}