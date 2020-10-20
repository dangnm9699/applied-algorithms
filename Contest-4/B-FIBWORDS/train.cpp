#include <bits/stdc++.h>

using namespace std;

int n;
string p;
int len[101];
string fibo[101];
long long int f[101], m[2];

string fibonacii(int l){
    if(l==0||l==1) return fibo[l];
    if(fibo[l]!="0") return fibo[l];
    fibo[l]=fibonacii(l-1)+fibonacii(l-2);
    return fibo[l];
}

int count_p(string str){
    int dem = 0;
    int ind = str.find(p);

    while(ind>=0){
        ++dem;
        str = ind+1<str.length()?str.substr(ind+1):"";
        ind = str.find(p);
    }
    return dem;
}

long long int dp(int l){
    if(f[l]<0){
        f[l] = dp(l-1) + dp(l-2) + m[l%2];
    }
    return f[l];
}

int main(){
    int tc = 0;
    for(int i=0;i<=100;++i) fibo[i] = "0";
    fibo[1] = "1";
    len[0] = 1, len[1] = 1;
    int length = 1, current = 1;
    while(length<100000){
        ++current;
        string fibo_string = fibonacii(current);
        len[current] = fibo_string.length();
        length = len[current];
    }
    while(cin>>n>>p){
        ++tc;
        if(n<current&&len[n]<p.length()){
            printf("Case %d: %d\n",tc,0);
            continue;
        }
        memset(f,-1,sizeof(f));
        current = 1;
        while(len[current-1]<p.length()) ++current;
        f[current-1] = count_p(fibo[current-1]);
        f[current] = count_p(fibo[current]);
        //a..x b..y and a = b
        string a = fibo[current-1].substr(0, p.length()-1);
        string x = fibo[current-1].substr(fibo[current-1].length()-p.length()+1);
        string y = fibo[current].substr(fibo[current].length()-p.length()+1);
        m[current%2] = count_p(x+a);
        m[(current+1)%2] = count_p(y+a);
        printf("Case %d: %lld\n", tc,dp(n));
    }
    return 0;
}