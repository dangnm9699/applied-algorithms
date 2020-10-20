#include<bits/stdc++.h>

using namespace std;

int n,r,dem=1;
int d[101][101];
int mark[101];
string route[11];
vector<int> path[11];
int start, stop;
vector<int> x;
int best;

void Try(int k, int dem, int val){
    if(k==path[dem].size()){
        if(d[x[x.size()-1]][stop]&&(val+d[x[x.size()-1]][stop]<best))
            best=d[x[x.size()-1]][stop]+val;
        return;
    }
    for(int i=0;i<path[dem].size();++i){
        if(!mark[path[dem][i]]&&d[x[x.size()-1]][path[dem][i]]&&(val+d[x[x.size()-1]][path[dem][i]]<best)){
            mark[path[dem][i]]=1;
            x.push_back(path[dem][i]);
            Try(k+1, dem, val+d[x[x.size()-2]][path[dem][i]]);
            mark[path[dem][i]]=0;
            x.pop_back();
        }
    }
}

int main(){
    cin>>n>>r;
    for(int i=1;i<=n;++i){
        mark[i]=0;
        for(int j=1;j<=n;++j){
            cin>>d[i][j];
        }
    }
    cin.ignore();
    for(int i=1;i<=r;++i){
        getline(cin, route[i]);
    }
    for(int i=1;i<=r;++i){
        string temp = route[i];
        int startIndex=0;
        for(int j=0;j<temp.length();++j){
            if(temp[j]==' '){
                int x=0;
                string subStr=temp.substr(startIndex,j);
                stringstream strToInt(subStr);
                strToInt>>x;
                path[i].push_back(x);
                startIndex=j+1;
            }
            if(j==temp.length()-1){
                int x=0;
                string subStr=temp.substr(startIndex);
                stringstream strToInt(subStr);
                strToInt>>x;
                path[i].push_back(x);
            }
        }
    }
    while(dem<=r){
        best=INT_MAX;
        start=path[dem][0];
        stop=path[dem][path[dem].size()-1];
        path[dem].erase(path[dem].begin());
        path[dem].pop_back();
        x.push_back(start);
        Try(0,dem,0);
        if(best>1000000) cout<<0<<endl;
        else cout<<best<<endl;
        x.clear();
        ++dem;
    }
    return 0;
}