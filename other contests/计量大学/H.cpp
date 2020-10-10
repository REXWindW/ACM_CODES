#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<functional>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define INF 0x3f3f3f3f
#define cendl printf("\n")
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff
const int MAXN = 2e5+5;
struct tree{
    int maxx;
    int lazy;
};
int n,m,ans;
struct St{//线段树 
	tree t[MAXN<<2];
	void pushup(int pos){ 
		t[pos].maxx = max(t[pos<<1].maxx,t[pos<<1|1].maxx);
		return;
	}
	void pushdown(int l,int r,int pos){
		if(!t[pos].lazy) return;
		int mid = (l+r)>>1;
		t[pos<<1].maxx = t[pos].lazy;
		t[pos<<1|1].maxx = t[pos].lazy;
		t[pos<<1].lazy = t[pos].lazy;
		t[pos<<1|1].lazy = t[pos].lazy;
		t[pos].lazy = 0; 
	}
	void build(int l,int r,int pos){ 
		t[pos].maxx = t[pos].lazy = 0;
		if(l==r){
			read(t[pos].maxx);
			return;
		}
		int mid = (l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		pushup(pos);
	}
	void update(int L,int R,int l,int r,int pos,int v){
		if(L<=l&&r<=R){
			t[pos].maxx = v;
			t[pos].lazy = v;
			return;
		}
		if(r<L||l>R) return;
		pushdown(l,r,pos);
		int mid = (l+r)>>1;
		update(L,R,l,mid,pos<<1,v);
		update(L,R,mid+1,r,pos<<1|1,v);
		pushup(pos);
	}
	void query(int L,int R,int l,int r,int pos){
		if(L<=l&&r<=R){
			ans =max(ans,t[pos].maxx);
			return;
		}
		if(r<L||R<l) return;
		pushdown(l,r,pos);
		int mid = (l+r)>>1;
		query(L,R,l,mid,pos<<1);
		query(L,R,mid+1,r,pos<<1|1);
		return;
	}
	//查询和修改，为了简化参数，我又写了两个 
	ll tquery(int L,int R){
		ans = 0;
		query(L,R,1,n,1);
		return ans; 	
	}
	void tupdate(int L,int R,int v){
		update(L,R,1,n,1,v);
	} 
};
St segt;
void solve(){
    read(n);read(m);
    segt.build(1,n,1);
    int l,r;
    while(m--){
        read(l),read(r);
        segt.tupdate(l,r,-INF);
        printf("%d\n",segt.tquery(1,n));
    }
}

int main(){
    int z;
    read(z);
    while(z--) solve();
}