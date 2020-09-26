#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<functional>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define INF 0x3f3f3f3f
#define cendl printf("\n")
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff

const int MAXN = 1e5+5;
int n;
int a[MAXN],b[MAXN];

void solve(int tnum){
	scanf("%d",&n);
	map<int,int> vis;//记录选中数字x的位置 
	rep(i,1,n){
		scanf("%d%d",&a[i],&b[i]);
	}
	set<int> res;
	rep(i,1,n){
		if(!vis[a[i]]){
			vis[a[i]] = i;//select a
			res.insert(a[i]);
		}
		else if(!vis[b[i]]){
			vis[b[i]] = i;//select b
			res.insert(b[i]);
		}
		else{//both have been selected
			int prev = vis[a[i]];
			if(!vis[b[prev]]){//如果反悔那次选的是a，可让其反悔为b 
				vis[b[prev]] = prev;
				vis[a[prev]] = i; 
				res.insert(b[prev]);
			}
			prev = vis[b[i]];
			if(!vis[b[prev]]){
				vis[b[prev]] = prev;
				vis[a[prev]] = i;
				res.insert(b[prev]);
			}
		}
	}	
	printf("Case #%d: %d\n",tnum,res.size());
}

int main(){
	//freopen("inputs.txt","r",stdin);
	//freopen("outputs2.txt","w",stdout);
	int z;
	scanf("%d",&z);
	rep(j,1,z) solve(j); 
}

