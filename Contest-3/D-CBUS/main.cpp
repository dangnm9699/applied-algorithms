#include <bits/stdc++.h>

using namespace std;

int n, k;
int dm[23][23];
int isVisited[23];
int dmmin = INT_MAX;
int load = 0;
int result = INT_MAX;
int temp_result = 0;

void find(int x, int from){
    // try to full load
    if (load < k){
        for (int i=1;i<=n;i++){
            if(!isVisited[i]){
                // add i
                isVisited[i] = 1;
                ++load;
                temp_result += dm[from][i];
                // try next if < f*
                if (temp_result + (2*n-x+1)*dmmin < result) find(x+1, i);
                // delete i
                temp_result -= dm[from][i];
                isVisited[i] = 0;
                --load;
            }
        }
    }
    // drop passengers
    for(int i=n+1;i<=2*n;i++){
        if (isVisited[i-n] && !isVisited[i]){
            --load;
            isVisited[i] = 1;
            temp_result += dm[from][i];
            //
            if (x == 2*n) result = min(result, temp_result + dm[i][0]);
            else {
                if (temp_result + (2*n-x+1)*dmmin < result) find(x+1,i);
            }
            //
            ++load;
            isVisited[i] = 0;
            temp_result -= dm[from][i];
        }
    }
}

int main(){
    cin >> n >> k;
    int size = 2*n+1;
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            cin >> dm[i][j];
            if (dm[i][j]) dmmin = min(dmmin, dm[i][j]);
        }
        isVisited[i] = 0;
    }
    find(1, 0);
    cout << result;
    return 0;
}