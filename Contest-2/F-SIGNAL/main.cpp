#include <bits/stdc++.h>

using namespace std;

int n,b;
int arr[200001];
int max_front[200001], max_back[200001];
int mf = 0, mb = 0;
int result=-1;

int main(){
    cin >> n >> b;
    for (int i=1;i<=n;i++){
        cin >> arr[i];   
        mf = max(mf, arr[i]);
        max_front[i] = mf;
    }
    for (int i=n;i>=1;i--){
        mb = max(mb, arr[i]);
        max_back[i] = mb;
    }
    for (int i=2;i<n;i++){
        int ai = arr[i];
        int left = max_front[i-1] - ai;
        int right = max_back[i+1] - ai;
        if (left>=b && right>=b) result = max(result, left+right);
    }
    cout << result;
    return 0;
}