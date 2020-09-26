#include<iostream>
#include<cstring>
using namespace std;
#define ll long long

const int MAXN = 1e6+5;

inline int lowbit(int x){return x&(-x);}

int n;
ll t[MAXN];

inline void init(){
	memset(t,0,sizeof(t));
} 

void add(int x,int k){
	for(;x<=n;x+=lowbit(x)) t[x]+=k;
}

ll sum(int x){
	ll ans = 0;
	for(;x>0;x-=lowbit(x)) ans+=t[x];
	return ans; 
} 

int main(){
	int q,hc;
	scanf("%d%d",&n,&q);
	init();
	for(int i=1;i<=n;i++){
		scanf("%d",&hc);
		add(hc,1);
	}
	while(q--){
		scanf("%d",&hc);
		if(hc>0) add(hc,1);
		else{
			hc = -hc;
			int l=1,r=n;
			while(l<r){
				int mid = (l+r)/2;
				if(sum(mid)<hc) l = mid+1;
				else r = mid;
			}
			add(r,-1);
		}
	}
	bool flag = 0;
	for(int i=1;i<=n;i++){
		if(sum(i)-sum(i-1)){
			flag = 1;
			printf("%d\n",i);
			break;
		}
	} 
	if(!flag) printf("0\n");
}
