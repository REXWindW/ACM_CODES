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

const int MAXN = 1e5+10;

string str;
int cl[MAXN],cr[MAXN];
int cx[MAXN];

void solve(){
	cin>>str;
	int len = str.length();
	cx[0]=cl[0]=cr[0]=0;
	rep(i,1,len){//这边移动了一下位子，从1开始 
		//做前缀和 
		cx[i]=cx[i-1];//*
		cl[i]=cl[i-1];//(
		cr[i]=cr[i-1];//)
		if(str[i-1]=='('){
			cl[i]++;
		}
		else if(str[i-1]==')'){
			cr[i]++;
		}
		else if(str[i-1]=='*'){
			cx[i]++;
		}
	}
	int xtl = 0;//把*变成(的数量 
	rep(i,1,len){//先从前往后扫，选出必须变(的* 
		if(cr[i]>cl[i]+xtl){//缺(的情况 
			if(cx[i]>xtl){
				xtl++;
			}
			else{
				cout<<"No solution!"<<endl;
				return;
			}
		}
	}
	int xtr = 0;//把*变成)的数量 
	repb(i,len,1){//再从后往前扫，选出必须变)的* 
		if(cl[len]-cl[i-1] > cr[len]-cr[i-1]+xtr){
			if(cx[len]-cx[i-1]>xtr){
				xtr++;
			}
			else{
				cout<<"No solution!"<<endl; 
				return; 
			}
		}
	}
	if(xtr+xtl>cx[len]){//要改的地方不够用了的情况 
		cout<<"No solution!"<<endl;
		return;
	}
	rep(i,0,len-1){
		if(xtl==0) break;
		if(str[i]=='*'){
			str[i] = '(';
			xtl--;
		}
	}
	repb(i,len-1,0){
		if(xtr==0) break;
		if(str[i]=='*'){
			str[i] = ')';
			xtr--;
		}
	}
	rep(i,0,len-1){
		if(str[i]=='*') continue;
		cout<<str[i];
	}
	cout<<endl;
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}

