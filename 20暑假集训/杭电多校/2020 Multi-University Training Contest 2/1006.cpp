#include<iostream>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
#define ull long long
using namespace std;

const int MAXN = 2e6+6;

ull fb[MAXN];//用unsigned long long,相当于模数取了2^64 
int la,lb,lc;//abc的长度 
int c[MAXN];
ull aa,bb,cc;

void init(){
	fb[0] = fb[1] = 1;
	rep(i,2,MAXN-2) fb[i] = (fb[i-1]+fb[i-2]);
}

void solve(){
	int hc,res;
	aa = bb = cc = c[0] = 0;
	scanf("%d",&la);
	rep(i,1,la){
		scanf("%d",&hc);
		if(hc) aa = aa+fb[i];
	}
	scanf("%d",&lb);
	rep(i,1,lb){
		scanf("%d",&hc);
		if(hc) bb = bb+fb[i];
	}
	scanf("%d",&lc);
	rep(i,1,lc){
		scanf("%d",&c[i]);
		if(c[i]) cc = cc+fb[i]; 
	}
	ll dis = aa*bb-cc;//找到a*c和c'的差值 
	rep(i,1,lc){
		if(c[i]==0&&dis==fb[i]){
			res = i;
			break;
		}
	}
	printf("%d\n",res);
}

int main(){
	//freopen("1006.in","r",stdin);
	//freopen("outputs.txt","w",stdout);
	init();
	int z;
	scanf("%d",&z);
	while(z--) solve();
}

