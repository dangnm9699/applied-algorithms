#include <bits/stdc++.h>

using namespace std;

int l, c;
int n;
int dem[2000][2000];

int main() {
    vector<pair<int,int>> m1, m2;
    cin >> n;
    for (int i=1;i<=n;i++){
        int result = 0;
        memset(dem, 0, sizeof dem);
        cin >> l >> c;
        int temp;
        for (int j=1;j<=l;j++){
            for (int k=1;k<=c;k++){
                cin >> temp;
                if (temp) m1.push_back({j,k});
            }
        }
        for (int j=1;j<=l;j++){
            for (int k=1;k<=c;k++){
                cin >> temp;
                if (temp) m2.push_back({j,k});
            }
        }
        for (int j=0;j<m1.size();j++){
            for (int k=0;k<m2.size();k++){
                int d_1 = m1[j].first - m2[k].first + l;
                int d_2 = m1[j].second - m2[k].second + c;
                ++dem[d_1][d_2];
            }
        }
        for (int j=1;j<2*l;j++){
            for (int k=1;k<2*c;k++){
                result = max(result, dem[j][k]);
            }
        }
        cout << result << endl;
        m1.clear();
        m2.clear();
    }
    return 0;
}