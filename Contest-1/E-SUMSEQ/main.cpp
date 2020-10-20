#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int result = 0;
    int dvd = 1000000007;
    cin >> n;
    for (int i=1;i<=n;i++){
        int temp;
        cin >> temp;
        result = (result+temp)%dvd;
    }
    cout << result;
    return 0;
}