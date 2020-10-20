#include <bits/stdc++.h>

using namespace std;

bool check(string str){
    stack<char> s;
    for (int i=0;i<str.length();i++){
        if (str[i]=='('||str[i]=='['||str[i]=='{'){
            s.push(str[i]);
            continue;
        }
        if (s.empty()) return false;

        if (str[i]==')'){
            if (s.top()!='(') return false;
            s.pop();
            continue;
        }
        if (str[i]==']'){
            if (s.top()!='[') return false;
            s.pop();
            continue;
        }
        if (str[i]=='}'){
            if (s.top()!='{') return false;
            s.pop();
            continue;
        }
    }
    return s.empty();
}

int main(){
    int t;
    cin >> t;
    string input;
    for (int i=1;i<=t;i++){
        cin >> input;
        if (check(input)) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}