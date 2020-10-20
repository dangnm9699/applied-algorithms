#include <bits/stdc++.h>

using namespace std;

#define pi 3.14159265359

int tc;
int n,f;
double r[10001];

int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d %d",&n,&f);
        ++f;
        double res = 0.0;
        double l = 0.0, m, h = 0.0;
        for(int i=1;i<=n;++i) {
            scanf("%lf",&r[i]);
            h = max(h, r[i]);
        }
        while(l+1e-7<h){
            m = (l+h)/2.0;
            int count = 0;
            for(int i=1;i<=n;++i){
                count += (int) (r[i]*r[i])/(m*m);
            }
            if(count>=f){
                if(m>res) res = m;
                l = m;
            }else{
                h = m;
            }
        }
        printf("%.6lf\n",pi*res*res);
    }
    return 0;
}