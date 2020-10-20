#include<bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin >> str;
    int len = str.size();
    int num[len];
    num[0] = str[0]=='['?1:0;
    for(int i=1;i<len;++i) num[i] = num[i-1] + (str[i]=='[');

    int left = 0, right = 0, best = 0;
    stack<int> index;
    for(int i=0;i<len;++i){
        if(!index.empty()&&((str[i]==']'&&str[index.top()]=='[') || (str[i]==')'&&str[index.top()]=='('))){
            index.pop();
            if(index.empty()) {
                if(num[i]>best) best=num[i], left=0,right=i+1;
            }else{
                if(num[i]-num[index.top()]>=best){
                    best=num[i]-num[index.top()];
                    left = index.top()+1;
                    right = i+1;
                }
            }
        }
        else index.push(i);
    }
    cout << best << endl;
    for(int i=left;i<right;++i) cout << str[i];
    return 0;
}