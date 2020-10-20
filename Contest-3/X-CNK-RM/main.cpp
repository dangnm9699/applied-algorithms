#include <bits/stdc++.h>

using namespace std;

int saved[1001][1001];
int dvd = 1000000007;

int c(int k, int n){
    if (k==0 || k==n) return 1;
    for (int i=0;i<=k;i++) {
        for (int j=i;j<=n;j++) {
            if (i==0 || i==j) saved[i][j] = 1;
            else saved[i][j] = (saved[i-1][j-1] + saved[i][j-1])%dvd;
        }
    }
return saved[k][n];
}

int main(){
    int n, k;
    cin >> k >> n;
    int res = c(k,n);
    cout << res;
    return 0;
}