#include <bits/stdc++.h>

using namespace std;

int m, n;
int t[11][31]; // Teachers and her/his list
int conflict[31][31];  // Conflicting pairs
vector<int> check[11]; // check teacher's list
int result = 33;

void Try(int k) {
    for (int it=1;it<=m;it++) {
        if (t[it][k]) {
            if (check[it].size() >= result) continue;
            int isOk = 1;
            for (int jt=0;jt<check[it].size();jt++){
                int existed = check[it][jt];
                if (conflict[existed][k] || conflict[k][existed]) isOk = 0;
            }
            if (isOk) {
                check[it].push_back(k);
                if (k==n) {
                    int temp = 0;
                    for (int jt=1;jt<=m;jt++) temp = max(temp, (int)check[jt].size());
                    result = min(result, temp);
                } else {
                    Try(k+1);
                }
                check[it].pop_back();
            }
        }
    }
}

int main(){
    cin >> m >> n;
    int k;
    for (int it=1; it<=m;it++){
        cin >> k;
        int temp;
        for (int jt=1;jt<=k;jt++){
            cin >> temp;
            t[it][temp] = 1;
        }
    }
    cin >> k;
    int i, j;
    for (int it=1;it<=k;it++){
        cin >> i >> j;
        conflict[i][j] = 1;
    }
    Try(1);
    if (result==33) cout << -1;
    else cout << result;
    return 0;
}