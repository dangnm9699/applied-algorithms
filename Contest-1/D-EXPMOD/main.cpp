#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    long long int a, b;
    long long int dvd = 1000000007;
    cin >> a >> b;
    long long int result = 1;

    a = a%dvd;
    while (b>0){
        if (b%2) result = (result*a)%dvd;
        b/=2;
        a = (a*a)%dvd;
    }
    cout << result;
    return 0;
}