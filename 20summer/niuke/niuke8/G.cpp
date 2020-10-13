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
ll gcd(ll a,ll b){while(b^=a^=b^=a%=b); return a;}
//#define INF 0x7fffffff

const int MAXN = 666;
int n;
int vis[10][10][10][10];

string check[5] = {"","nwh","iqv","otp","eru"};
struct Card{
	int a[5];
	int num;
	friend bool operator < (Card a,Card b){
		rep(i,1,4){
			if(a.a[i]>b.a[i]) return 1;
			else if(a.a[i]<b.a[i]) return 0;
		}
		return 0;
	}
}ka[MAXN];

void solve(int tnum){
	cin>>n;
	string str;
	getline(cin,str);
	rep(i,1,n){
		ka[i].num = i;
		int co = 0;
		getline(cin,str);
		int len = str.length();
		rep(j,0,len-1){
			if(str[j]=='['){
				++co;
				if(str[j+1]=='*'){
					ka[i].a[co]=9;
				} 
				rep(k,0,2) 
					if(str[j+2]==check[co][k]){ka[i].a[co]=k;break;}//给编号
			}
			if(co==4) break;
		}
	}//读入部分 
	//sort(ka+1,ka+n+1);
	for(int i=1;i<=n;i++){
		Card x = 
		vis[x.a[1]][x.a[2]][x.a[3]][x.a[4]];
	}
}

int main(){
	int z;
	cin>>z;
	rep(i,1,z) solve(z);
}
