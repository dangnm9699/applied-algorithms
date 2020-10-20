#include<bits/stdc++.h>

using namespace std;

long long int n,m;
long long int h[1000001];
long long int maxi=0;
long long int res=0;
long long int i;

int main(){
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%lld", &h[i]);
		if(h[i]>maxi) maxi=h[i];
	}
	long long int lo=0,mid,hi=maxi;
	long long int sum;
	while(lo<=hi){
		mid=(lo+hi)/2;
		sum=0;
		for(i=1;i<=n;++i) {
			if(h[i]>mid) sum+=(h[i]-mid);
		}
		if(sum>m){
			lo=mid+1;
			if(mid>res)res=mid;
		}else if(sum<m) hi=mid-1;
		else{
			res=mid;
			break;
		}
	}
	printf("%lld",res);
	return 0;
}
