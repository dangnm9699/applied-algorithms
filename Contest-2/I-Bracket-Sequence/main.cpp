#include<bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin >> str;
    int len = str.size();
    int num[len+1];
    num[0] = 0;
    for(int i=1;i<=len;++i) num[i] = num[i-1] + (str[i-1]=='[');

    int left = 0, right = 0, best = 0;
    stack<int> index;
    index.push(0);
    for(int i=0;i<len;++i){
        if(str[i]=='['||str[i]=='('){
            index.push(i+1);
            continue;
        }
        if(index.top()>=1&&((str[i]==']'&&str[index.top()-1]=='[') || (str[i]==')'&&str[index.top()-1]=='('))){
            index.pop();
            if(num[i+1]-num[index.top()]>best){
                best = num[i+1] - num[index.top()];
                left = index.top();
                right = i+1;
            }
        }
        else index.push(i+1);
    }
    cout << best << endl;
    for(int i=left;i<right;++i) cout << str[i];
    return 0;
}