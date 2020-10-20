#include<bits/stdc++.h>
using namespace std;

int n,m;
int hole[13][13];
int sol;
int H[13],C[13], sumHC[24], subHC[24]; 

void Try(int row){
    if(row==n+1){
        ++sol;
        return;
    }
    for(int col=1;col<=n;++col){
        if(!H[row]&&!C[col]&&!sumHC[row+col-1]&&!subHC[row-col+n]&&!hole[row][col]){
            H[row] = 1;
            C[col] = 1;
            sumHC[row+col-1] = 1;
            subHC[row-col+n] = 1;
            Try(row+1);
            H[row] = 0;
            C[col] = 0;
            sumHC[row+col-1] = 0;
            subHC[row-col+n] = 0;
        }
    }
}

int main(){
    while(true){
        scanf("%d%d",&n,&m);
        if(!m&&!n) return 0;
        sol=0;
        memset(hole,0,sizeof(hole));
        for(int i=1;i<=m;++i){
            int row, col;
            scanf("%d%d",&row,&col);
            hole[row][col]=1;
        }
        Try(1);
        printf("%d\n",sol);
    }
    return 0;
}