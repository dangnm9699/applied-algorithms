#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int a, b;
    int dvd = 1000000007;
    cin >> a >> b;
    cout << (a%dvd + b%dvd)%dvd;
    return 0;
}