#include <bits/stdc++.h>
using namespace std;
int n,a[1000005];
int res1,res2;
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i){
        cin >> a[i];
	}

	int pos = 1;

	while(a[pos] >= a[pos+1] && pos < n) ++pos;

    int bot = pos,top = pos+1;

    for(int i = pos+1; i < n; ++i){
        if(a[i] < a[i+1]) {
            top = i+1;
            continue;
        }

        if(a[i] == a[i+1]){
            while(a[i] >= a[i+1] && i < n) ++i;
            bot = i;
            top = i+1;
            continue;
        }

        while(a[i] > a[i+1] && i < n) ++i;
        res1 = max(res1,min(top-bot,i-top));

        while(a[i] >= a[i+1] && i < n) ++i;
            bot = i;
            top = i+1;
    }

    pos = 1;

	while(a[pos] <= a[pos+1] && pos < n) ++pos;

    bot = pos+1,top = pos;

    for(int i = pos+1; i < n; ++i){
        if(a[i] > a[i+1]) {
            bot = i+1;
            continue;
        }

        if(a[i] == a[i+1]){
            while(a[i] <= a[i+1] && i < n) ++i;
            bot = i+1;
            top = i;
            continue;
        }

        while(a[i] < a[i+1] && i < n) ++i;
        res2 = max(res2,min(bot-top,i-bot));

        while(a[i] <= a[i+1] && i < n) ++i;
            bot = i+1;
            top = i;
    }

    cout << res1 << " " << res2;
    return 0;
}