#include <bits/stdc++.h>

using namespace std;

unsigned long long int res = 0;
int n;
int d[101];
long long int c[101], mc[2];
string fibo[101];
string be[101], en[101];
string p;

/**
 * Calculate Fibonacci(n)
 * 
*/
string fib(int n){
    if(n==0||n==1) return fibo[n];
    if(fibo[n]!="0") return fibo[n];
    fibo[n] = fib(n-1)+fib(n-2);
    return fibo[n];
}

int countP(string fi){
    int dem = 0;
    int ind = fi.find(p);
    while(ind>=0){
        ++dem;
        string temp = "";
        for(int i=ind+1;i<fi.length();i++){
            temp+=fi[i];
        }
        fi=temp;
        ind = fi.find(p);
    }
    return dem;
}

long long int cP(int x){
    if(c[x]<0){
        c[x]=cP(x-1)+cP(x-2)+mc[x%2];
    }
    return c[x];
}

int main(){
    int tc = 1;
    fibo[0] = "0";
    for(int i=0;i<=100;i++) fibo[i]="0";
    fibo[1] = "1";
    d[0] = 1;
    d[1] = 1;
    int l = 1; // length
    int tmp = 1;
    while(l<100000){
        ++tmp;
        string x = fib(tmp);
        d[tmp] = x.length();
        l = d[tmp];
    }
    while(cin>>n>>p){
        int lp = p.length();
        if(n<tmp&&d[n]<lp) {
            cout<<"Case "<<tc<<": " <<0<<endl;
            ++tc;
            continue;
        }
        for(int i=0;i<=n;i++) c[i]=-1;
        tmp=1;
        // x..a + y..b
        while(d[tmp-1]<lp) ++tmp;
        c[tmp-1]=countP(fibo[tmp-1]);
        c[tmp]=countP(fibo[tmp]);
        string x = fibo[tmp].substr(0,lp-1); //x=y
        string a = fibo[tmp-1].substr(fibo[tmp-1].length()-lp+1);
        string b = fibo[tmp].substr(fibo[tmp].length()-lp+1);
        mc[tmp%2] = countP(a+x);
        mc[(tmp+1)%2] = countP(b+x);
        cout <<"Case "<<tc<<": " <<cP(n)<<endl;
        ++tc;
    }
    return 0;
}