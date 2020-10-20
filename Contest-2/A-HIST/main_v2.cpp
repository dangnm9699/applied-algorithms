#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<long long> resultset;
    // Nhap so phan tu cua dong dau tien
    cin >> n;
    while (n) {

        vector<int> a(n+2);
        vector<int> l(n+1), r(n+1);
        vector<int> s;

        // Nhap cac phan tu
        for (int i = 1; i <= n; i ++) {
            cin >> a[i];
        }

        // Tim Left, Right cua testcase
        s.push_back(0); // s[0] = 0;
        a[0] = -1;
        a[n+1] = -1;

        for (int i = 1; i <= n; i ++) {
            while (a[s.back()] >= a[i]) s.pop_back();
            l[i] = s.back() + 1;
            s.push_back(i);
        }

        s.clear(); // renew stack
        s.push_back(n+1); // s[0] = n+1;

        for (int i = n; i >= 1; i --) {
            while (a[s.back()] >= a[i]) s.pop_back();
            r[i] = s.back() - 1;
            s.push_back(i);
        }

        // Tim max cua testcase
        long long result = 0;  
        for (int i = 1; i <= n; i ++) {
            result = max(result, 1ll*(r[i] - l[i] + 1)*a[i]);
        }
        resultset.push_back(result);
        
        // Nhap so phan tu cua dong tiep theo
        cin >> n;
    }

    for (int i = 0; i < resultset.size(); i ++) cout << resultset[i] << endl;

    return 0;
}