#include <bits/stdc++.h>

using namespace std;

struct place {
    int x, m;
};

bool comparePlace(place p1, place p2) {
    return p1.x < p2.x;
}

int main() {
    
    int n, k, times;
    int temp_x, temp_m;
    long long time = 0;

    vector<place> negx;
    vector<place> posx;
    place temp_place;

    cin >> n >> k ;
    for (int i = 0; i < n; i ++) {
        cin >> temp_x >> temp_m;
        temp_place.x = temp_x;
        temp_place.m = temp_m;
        if (temp_x > 0) posx.push_back(temp_place);
        else negx.push_back(temp_place);
    }

    sort(posx.begin(), posx.end(), comparePlace);
    sort(negx.begin(), negx.end(), comparePlace);
    reverse(negx.begin(), negx.end());

    int div;
    while (!negx.empty()) {
        div = negx.back().m%k;
        times = div==0?(negx.back().m/k):(negx.back().m/k + 1);
        time += 2*1ll*abs(negx.back().x)*times;
        int rest = k - (div==0?k:div);
        negx.pop_back();
        while (!negx.empty() && rest > 0) {
            if (rest >= negx.back().m) {
                rest -= negx.back().m;
                negx.pop_back();
            } else {
                negx.back().m -= rest;
                rest = 0;
            }
        }
    }

    while (!posx.empty()) {
        div = posx.back().m%k;
        times = div==0?(posx.back().m/k):(posx.back().m/k + 1);
        time += 2*1ll*abs(posx.back().x)*times;
        int rest = k - (div==0?k:div);
        posx.pop_back();
        while (!posx.empty() && rest > 0) {
            if (rest >= posx.back().m) {
                rest -= posx.back().m;
                posx.pop_back();
            } else {
                posx.back().m -= rest;
                rest = 0;
            }
        }
    }

    cout << time;

    return 0;
}