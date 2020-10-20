#include<bits/stdc++.h>

using namespace std;

int main(){
    string seq;
    cin>>seq;
    stack<char> s;
    for(int i=0;i<seq.length();++i){
        if(s.empty()) s.push(seq[i]);
        else if(s.top()==seq[i]) s.pop();
        else s.push(seq[i]);
    }
    if(s.empty()) cout<<"Yes";
    else cout<<"No";
    return 0;
}