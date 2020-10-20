#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<long long> result;
    int n;
    // Nhap so phan tu cua dong dau tien
    cin >> n;
    while (n) {

        vector<int> temp_vector;
        int temp_int;

        // Nhap cac phan tu
        for (int i = 0; i < n; i ++) {
            cin >> temp_int;
            temp_vector.push_back(temp_int);
        }

        // Tim max cua testcase
        vector<int> Stack;
        vector<int> Left(n), Right(n);

        for (int i = 0; i < n; i ++) {
            while (!Stack.empty() && temp_vector[Stack.back()] >= temp_vector[i]) Stack.pop_back();
            if (Stack.empty()) Left[i] = 0;
            else Left[i] = Stack.back() + 1;
            Stack.push_back(i);
        }

        Stack.clear();

        for (int i = n - 1; i >= 0 ; i --) {
            while (!Stack.empty() && temp_vector[Stack.back()] >= temp_vector[i]) Stack.pop_back();
            if (Stack.empty()) Right[i] = n - 1;
            else Right[i] = Stack.back() - 1;
            Stack.push_back(i);
        }

        long long max = 0;  
        long long temp;
        for (int i = 0; i < n; i ++) {
            temp = 1ll*(Right[i] - Left[i] + 1)*temp_vector[i];
            if (temp > max) max = temp;
        }

        result.push_back(max);
        

        // Nhap so phan tu cua dong tiep theo
        cin >> n;
    }
    
    for (int i = 0; i < result.size(); i ++) cout << result[i] << endl;
    
    return 0;
}