#include <bits/stdc++.h>

using namespace std;

int n;
int c[23][23];
int visited[23];
int res = INT_MAX;
int cmin = INT_MAX;
int temp_sum = 0;
int load = 0;

void taxi(int k, int from){
    if (!load){
        for(int i=1;i<=n;i++){
            if (!visited[i]){
                ++load;
                visited[i] = 1;
                temp_sum += c[from][i];
                if (temp_sum + (2*n+1-k)*cmin < res) taxi(k+1, i);
                temp_sum -= c[from][i];
                visited[i] = 0;
                --load;
            }
        }
    }
    for(int i=n+1;i<=2*n;i++){
        if (visited[i-n]&&!visited[i]){
            --load;
            visited[i] = 1;
            temp_sum += c[from][i];

            if (k==2*n) res = min(res, temp_sum+c[i][0]);
            else if (temp_sum + (2*n+1-k)*cmin < res) taxi(k+1, i);

            temp_sum -= c[from][i];
            visited[i] = 0;
            ++load;
        }
    }
}

int main(){
    cin >> n;
    int size=2*n+1;
    for (int i=0;i<size;i++){
        visited[i] = 0;
        for (int j=0;j<size;j++){
            cin >> c[i][j];
            if(c[i][j]) cmin = min(cmin, c[i][j]);
        }
    }
    taxi(1,0);
    cout << res;
    return 0;
}