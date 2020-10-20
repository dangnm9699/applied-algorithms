#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    int max = INT_MIN, check_sum = 0;
    for (int i=0;i<n;i++){
        int temp;
        cin >> temp;
        check_sum += temp;
        if (check_sum>max) max=check_sum;
        if (check_sum<0) check_sum=0;
    }
    cout << max;
    return 0;
}