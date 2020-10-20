#include<bits/stdc++.h>
using namespace std;

int n,k,m;
long long int p[501];

int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&m,&k);
        long long int sum = 0;
        long long int maxi = 0;
        for(int i=1;i<=m;++i) {
            scanf("%lld",&p[i]);
            maxi = max(maxi, p[i]);
            sum += p[i];
        }
        long long int lo=maxi,mid,hi=sum;
        int part;
        while(lo<hi){
            mid=(lo+hi)/2;
            part = 1;
            sum = 0;
            for(int i=m;i>=1;--i){
                if(p[i]>mid){
                    part = k+1;
                    break;
                }
                if(sum+p[i]>mid){
                    ++part;
                    sum = 0;
                }
                sum += p[i];
            }
            if(part<=k){
                hi = mid;
            }else{
                lo = mid+1;
            }
        }
        sum = 0;
        part = 1;
        vector<int> b;
        for(int i=m;i>=1;--i){
            if(sum+p[i]>hi||i==k-part){ // Nếu tổng > max hoặc i là vị trí bằng mới số part còn lại
                sum = 0;
                b.push_back(i);
                ++part;
            }
            sum += p[i];
        }
        for(int i=1;i<=m;++i){
            printf("%lld ",p[i]);
            if(!b.empty()){
                if(i==b.back()){
                    printf(" / ");
                    b.pop_back();
                }
            }
        }
        printf("\n");
    }
    return 0;
}