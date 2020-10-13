#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
const int MAXN = 53;

struct Item{
	int a,b,c,d;
}it[MAXN][MAXN];

int n,k;
int aa,bb,cc,dd;
int nxt[MAXN],c[MAXN];
long long res;

void dfs(int pos){
	if(pos>k){
		res = max(res,1ll*aa*bb*cc*dd);
		return;
	}
	for(int i=1;i<=c[pos];i++){
		aa += it[pos][i].a;bb += it[pos][i].b;
		cc += it[pos][i].c;dd += it[pos][i].d;
		dfs(nxt[pos]);
		aa -= it[pos][i].a;bb -= it[pos][i].b;
		cc -= it[pos][i].c;dd -= it[pos][i].d;
	}
	if(!c[pos]) dfs(nxt[pos]); 
}

void solve(){
	cin>>n>>k;
	int typ;
	rep(i,1,k) c[i] = 0;
	rep(i,1,n){
		scanf("%d",&typ);
		c[typ]++;
		scanf("%d%d%d%d",&it[typ][c[typ]].a,&it[typ][c[typ]].b,&it[typ][c[typ]].c,&it[typ][c[typ]].d);
	} 
	int tt = k+1;
	repb(i,k,1){
	//这个nxt是关键，因为如果不能直接跳过c[i]=0的点会慢很多 
		nxt[i] = tt;
		if(c[i]) tt = i;
	}
	aa = bb = cc = dd = 100;
	res = 100000000; 
	dfs(1);
	printf("%lld\n",res);
}

int main(){
	/*
	freopen("1010in.txt","r",stdin);
	freopen("outputs.txt","w",stdout);
	*/
	int z;
	cin>>z;
	while(z--) solve();
}
