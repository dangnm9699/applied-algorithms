#include <bits/stdc++.h>

using namespace std;
#define state tuple<int, int, int>
#define visited pair<int, int>

int main() {

    int a, b, c;
    cin >> a >> b >> c;

    queue<state> q;
    map<visited, bool> visit_check;

    state init = make_tuple(0,0,0);
    state curr, next;
    q.push(init);

    while (!q.empty()) {
        curr = q.front();
        visit_check[{get<0>(curr), get<1>(curr)}] = true;
        q.pop();
        // Check: Đã có Jug nào có c lít hay chưa ?
        if (get<0>(curr) == c || get<1>(curr) == c) {
            cout << get<2>(curr);
            return 0;
        }

        // Case: Đổ hết a-Jug
        next = state(0, get<1>(curr), get<2>(curr) + 1);
        if (!visit_check[visited{get<0>(next), get<1>(next)}]) {
            q.push(next);
            visit_check[visited{get<0>(next), get<1>(next)}] = true;
        }

        // Case: Đổ hết b-Jug
        next = state(get<0>(curr), 0, get<2>(curr) + 1);
        if (!visit_check[visited{get<0>(next), get<1>(next)}]) {
            q.push(next);
            visit_check[visited{get<0>(next), get<1>(next)}] = true;
        }

        // Case: Đổ đầy a-Jug
        next = state(a, get<1>(curr), get<2>(curr) + 1);
        if (!visit_check[visited{get<0>(next), get<1>(next)}]) {
            q.push(next);
            visit_check[visited{get<0>(next), get<1>(next)}] = true;
        }

        // Case: Đổ đầy b-Jug
        next = state(get<0>(curr), b, get<2>(curr) + 1);
        if (!visit_check[visited{get<0>(next), get<1>(next)}]) {
            q.push(next);
            visit_check[visited{get<0>(next), get<1>(next)}] = true;
        }

        // Case: Đổ từ a-Jug sang b-Jug đến khi a-Jug hết hoặc b-Jug đầy
        next = state(max(0, get<0>(curr) + get<1>(curr) - b), min(get<0>(curr) + get<1>(curr), b), get<2>(curr) + 1);
        if (!visit_check[visited{get<0>(next), get<1>(next)}]) {
            q.push(next);
            visit_check[visited{get<0>(next), get<1>(next)}] = true;
        }

        // Case: Đổ từ b-Jug sang a-Jug đến khi b-Jug hết hoặc a-Jug đầy
        next = state(min(get<0>(curr) + get<1>(curr), a), max(0, get<0>(curr) + get<1>(curr) - a), get<2>(curr) + 1);
        if (!visit_check[visited{get<0>(next), get<1>(next)}]) {
            q.push(next);
            visit_check[visited{get<0>(next), get<1>(next)}] = true;
        }

    }

    cout << -1;

    return 0;
}