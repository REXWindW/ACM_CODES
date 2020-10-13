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
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define INF 0x3f3f3f3f
#define cendl printf("\n")
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff

const int MAXN = 2e6+5;

int cf[MAXN];//差分数组 
int a[MAXN];
int n,k;
map<int,int> mp;

void solve(){
	mp.clear();
	bool flag = 1;
	scanf("%d%d",&n,&k);
	rep(i,0,k) cf[i] = 0;//清空差分数组
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(a[i]>k)flag = 0;
	}
	if(flag==0){
		cout<<"NO"<<endl;
		return;
	}
	int countt = 0;
	int l,r;
	rep(i,1,n){//找隔板位置 
		if(mp[a[i]]==0){
			mp[a[i]] = i;
		}
		else{
			if(mp[a[i]]>=i-k+1){//重复的情况 
				//cout<<"find chongfu in "<<i<<endl;
				countt++;
				l = mp[a[i]] % k;
				r = i % k;
				//cout<<l<<' '<<r<<endl; 
				//隔板可能在的地方
				if(l<r){
					//cout<<"typ1"<<endl;
					cf[r]--;
					cf[l]++;
				} 
				else if(l>r){
					swap(l,r);
					//cout<<"typ2"<<endl;
					cf[0]++;
					cf[l]--;
					cf[r]++;
					cf[k+1]--;
				}
				/*debug
				int cfx = 0;
				rep(i,0,k-1){
					cfx += cf[i];
					cout<<cfx<<' ';
				}
				cout<<endl;
				*/
			}
			mp[a[i]] = i;
		}
	}
	//cout<<"countt=="<<countt<<endl;
	int cfx = 0;
	rep(i,0,k-1){//处理差分数组 
		cfx += cf[i];
		//cout<<cfx<<' ';
//		/*
		if(cfx==countt){
			cout<<"YES"<<endl;
			return;
		}
//		*/
	}
	cout<<endl;
	cout<<"NO"<<endl;
}

int main(){
	int z;
	scanf("%d",&z);
	while(z--) solve();
}

