#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

int n, m;
int visited[21];
int path[21];
int cost[21][21];
int total = MAX, cmin = MAX, temp_total = 0;

void find (int k) {
    for (int i = 2; i <= n; i ++) {
        if (!visited[i]) {
            path[k] = i;
            visited[i] = 1;
            temp_total += cost[path[k-1]][path[k]];

            if (k==n) {
                if (temp_total + cost[path[n]][path[1]] < total)
                    total = temp_total + cost[path[n]][path[1]];
            } else {
                int temp = temp_total + (n - k + 1)*cmin;
                if (temp < total) find(k+1);
            }

            temp_total -= cost[path[k-1]][path[k]];
            visited[i] = 0;
        }
    }
}

int main () {
    cin >> n >> m;

    // Tạo ma trận chi phí giữa các thành phố
    for (int i = 1; i <= n; i ++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j ++) {
            i==j?(cost[i][j] = 0):(cost[i][j] = MAX);
        }
    }

    // Update ma trận chi phí
    for (int i = 1; i <= m; i ++) {
        int temp_i, temp_j, temp_c;
        cin >> temp_i>>temp_j>>temp_c;
        cost[temp_i][temp_j] = temp_c;
        cmin = min(cmin, temp_c);
    }

    // Bắt đầu từ TP 1
    path[1] = 1;
    visited[path[1]] = 1;
    find(2);

    cout << total;

    return 0;
}