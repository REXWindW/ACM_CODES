#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define log(x) (31-__builtin_clz(x))
#define INF 0x3f3f3f3f
#define int ll
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff
int dir[6][2] = {1,1,0,1, -1,0,-1,-1, 0,-1,1,0};
ll c[6];
ll tx,ty;
ll res;
inline ll cd(int x){ return c[ (x+6)%6 ]; }
inline bool th(ll a,ll b){//判断同号
	if(a==b&&a==0) return 1;
	else if(a>0&&b>0) return 1;
	else if(a<0&&b<0) return 1;
	return 0;
}
void solve(){
	res = 0;
	cin>>tx>>ty;
	rep(i,0,5) cin>>c[i];//费用;
	rep(i,0,5){//最短路思想
		if(cd(i-1)+cd(i+1)<cd(i)) c[i] = cd(i-1)+cd(i+1);
	}
	rep(i,0,5){//最短路思想
		if(cd(i-1)+cd(i+1)<cd(i)) c[i] = cd(i-1)+cd(i+1);
	}
	ll minn = 1LL<<62;
	//我懂了，最多只需要两种方向。
	//先把tx弄到相同的方案
	//先搞x再搞y的情况
	rep(i,0,5){
		res = 0;
		ll tty = ty;ll ttx = tx;
		if(dir[i][0]==0) continue;
		if(th(dir[i][0],ttx)||ttx==0){
			ll tim = abs(ttx);
			tty -= tim*dir[i][1];
			ttx = 0;
			res += c[i]*tim;
			rep(j,0,5){
				if(dir[j][0]!=0) continue;
				if(dir[j][1]==0) continue;
				if(th(dir[j][1],tty)||tty==0){
					ll tim = abs(tty);
					ll res2 = res + c[j]*tim;
					minn = min(minn,res2);
					//cout<<i<<' '<<j<<':'<<res<<' '<<res2<<endl;
				}
			}
		}
	}
	//先搞y再搞x
	rep(i,0,5){
		res = 0;
		ll tty = ty;ll ttx = tx;
		if(dir[i][1]==0) continue;
		if(th(dir[i][1],tty)||tty==0){
			ll tim = abs(tty);
			ttx -= tim*dir[i][0];
			tty = 0;
			res += c[i]*tim;
			rep(j,0,5){
				if(dir[j][1]!=0) continue;
				if(dir[j][0]==0) continue;
				if(th(dir[j][0],ttx)||ttx==0){
					ll tim = abs(ttx);
					ll res2 = res + c[j]*tim;
					minn = min(minn,res2);
					//cout<<i<<' '<<j<<':'<<res<<' '<<res2<<endl;
				}
			}
		}
	}
	cout<<minn<<endl;
}

signed main(){
	int z;
	cin>>z;
	while(z--) solve();
}