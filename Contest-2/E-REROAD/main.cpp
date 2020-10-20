#include <bits/stdc++.h>

using namespace std;

int result = 1;
int N, Q;

int main(){
    cin >> N;
    int t[N+2];
    for (int i=1;i<=N;i++){
        cin >> t[i];
        if (t[i] != t[i-1] && i >= 2) ++result;
    }
    cin >> Q;
    int p, c;
    for (int i=1;i<=Q;i++){
        cin >> p >> c;

        if(c != t[p]){
            if (p==1){
                if (t[1] == t[2]) ++result;
                if (c == t[2]) --result;
            }
            else if (p==N){
                if (t[N] == t[N-1]) ++result;
                if (c == t[N-1]) --result;
            } else {
                int left = t[p-1];
                int right = t[p+1];
                if (left==right){
                    if (t[p]==left) result+=2;
                    if (c==left) result-=2;
                }else{
                    if (t[p]==left){
                        if (c!=right) ++result;
                    }
                    else if (t[p]==right){
                        if (c!=left) ++result;
                    } else {
                        if (c==left) --result;
                        if (c==right) --result;
                    }
                }
            }

        }

        cout << result << endl;
        t[p] = c;
    }
    return 0;
}