#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 114;
ll a[MAXN],p[MAXN];
int n,m,s,k;
void solve(){
	cin>>s>>n>>m>>k;
	rep(i,1,n){
		cin>>a[i]>>p[i];
	}
	int mto;
	ll nowm = m;
	ll cost=0;
	a[0] = 0;
	a[n+1] = s;
	p[n+1] = 0;
	rep(i,1,n+1){
		nowm-=50*(a[i]-a[i-1]);
		if(nowm<0){
			cout<<"Impossible"<<endl;
			return;
		}
		int ma = a[i]+m/50;//加满的情况
		bool flag = 0;
		rep(j,i+1,n+1){//检查是否有比这个点更划算的
			if(a[j]>ma) break;
			if(p[j]<=p[i]){
				//cout<<"find"<<j<<"cheaper than "<<i<<endl;
				mto = max((ll)(a[j]-a[i])*50,nowm);
				//cout<<"cost"<<cost<<"nowm"<<nowm<<"mto"<<mto<<endl;
				cost+=(mto-nowm)*p[i];
				nowm=mto;
				flag = 1;
				break;
			}
		}
		if(!flag){//如果在这里加油最划算
			cost+=(m-nowm)*p[i];
			nowm = m;
		}
	}
	//cout<<"cost"<<cost<<endl;
	if(cost<k){
		cout<<k-cost<<endl;
	}
	else{
		cout<<"No profit"<<endl;
	}
}

int main(){
	freopen("F_out.txt","w",stdout);
	int z;
	cin>>z;
	while(z--) solve();
}