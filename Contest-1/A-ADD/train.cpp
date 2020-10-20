#include <bits/stdc++.h>

using namespace std;

string a, b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    string res = "";
    // make a's length <= a's length
    if (a.length() > b.length())
    {
        swap(a, b);
    }
    int remain = 0;
    int diff = b.length() - a.length();
    for (int i = a.length()-1; i >= 0; --i)
    {
        int calc = (a[i] - '0') + (b[i + diff] - '0') + remain;
        res += ((calc % 10) + '0');
        remain = calc / 10;
    }
    for (int i = diff - 1; i >= 0; --i)
    {
        int calc = (b[i] - '0') + remain;
        res += ((calc % 10) + '0');
        remain = calc / 10;
    }
    if (remain > 0) res += (remain + '0');
    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}