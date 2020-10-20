#include <bits/stdc++.h>

using namespace std;

int digits(int n){
    if (n%2) return 0;
    int count = 0;
    int check[10] = {0,0,0,0,0,0,0,0,0,0};
    for (int i=1;i<=9;i++){
        if (check[i]) continue;
        check[i] = 1;
        for (int c=1;c<=9;c++){
            if (check[c]) continue;
            check[c] = 1;
            for (int t=1;t<=9;t++){
                if (check[t]) continue;
                check[t] = 1;
                for (int h=1;h<=9;h++){
                    if (check[h]) continue;
                    check[h] = 1;
                    for (int u=1;u<=9;u++){
                        if (check[u]) continue;
                        check[u] = 1;
                        for (int s=1;s<=9;s++){
                            if (check[s]) continue;
                            check[s] = 1;
                            for (int k=1;k<=9;k++){
                                if (check[k]) continue;
                                check[k] = 1;
                                int ict = i*100+c*10+t;
                                int k62 = k*100+62;
                                int hust = h*1000+u*100+s*10+t;
                                int total = ict - k62 + hust;
                                if (total==n) ++count;
                                check[k] = 0;
                            }
                            check[s] = 0;
                        }
                        check[u] = 0;
                    }
                    check[h] = 0;
                }
                check[t] = 0;
            }
            check[c] = 0;
        }
        check[i] = 0;
    }

    return count;
}

int main(){
    int n;
    cin>>n;
    cout << digits(n);
    return 0;
}