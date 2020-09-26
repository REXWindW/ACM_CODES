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
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define INF 0x3f3f3f3f
#define cendl printf("\n")
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff

int x;
const int MAXN = 1e5+5; 

int idx(char c){return c-'a';}

void solve(){
	vector<int> v[27];
	string s,t;
	cin>>s>>t;
	int lens = s.size();
	rep(i,0,lens-1){
		x = idx(s[i]);
		v[x].push_back(i);
	}
	int lent = t.size();
	int px = 0;
	int countt = 1;
	bool flag = 1;
	rep(i,0,lent-1){// any letter in t but not in s
		x = idx(t[i]);
		if(v[x].empty()){
			flag = 0;
			break;
		}
	}
	if(!flag){
		cout<<-1<<endl;
		return;
	}
	rep(i,0,lent-1){
		x = idx(t[i]);
		int f = lower_bound(v[x].begin(),v[x].end(),px)-v[x].begin();
		if(f==v[x].size()){
			countt ++;
			px = v[x][0]+1;
		}
		else px = v[x][f]+1;
		//for test purpose!
//		cout<<"int countt"<<countt<<", insert "<<t[i]<<endl;
//		cout<<"now px =="<<px<<endl;
	}
	cout<<countt<<endl;
}

int main(){
	int z;
	cin>>z;
	while(z--)solve();
}

