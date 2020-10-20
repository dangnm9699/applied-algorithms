#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    while(n!=0){
        int l[n+2], left[n+1], right[n+1];
        long long res = 0;
        for(int i=1;i<=n;++i) scanf("%d",&l[i]);

        // Stack includes index that l[index] <= l[stack.top()] 
        l[0] = -1, l[n+1] = -1;

        stack<int> s_left; s_left.push(0);
        for(int i=1;i<=n;++i){
            while(l[s_left.top()]>=l[i]) s_left.pop();
            left[i] = s_left.top() + 1;
            s_left.push(i);
        }

        stack<int> s_right; s_right.push(n+1);
        for(int i=n;i>=1;--i){
            while(l[s_right.top()]>=l[i]) s_right.pop();
            right[i] = s_right.top() - 1;
            s_right.push(i);
        }    

        for(int i=1;i<=n;++i) res = max(res, 1ll*l[i]*(right[i]-left[i]+1));
        printf("%lld\n",res);
        scanf("%d",&n);
    }
    return 0;
}