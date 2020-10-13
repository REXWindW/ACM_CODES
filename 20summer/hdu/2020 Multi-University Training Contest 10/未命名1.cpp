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

int a[4][4];
int b[4][4];
bool w[4][4];
int c[4];
int cnt;

void cal(){
	c[1]=a[1][1];
	c[2]=a[2][3];
	c[3]=a[3][2];
	int nim1 = 0;
	rep(i,1,3){
		rep(j,1,3){
			if(i==1&&j==1) continue;
			if(i==2&&j==3) continue;
			if(i==3&&j==2) continue;
			nim1^=a[i][j]-1;
		}
	}
	if(nim1==0){//谁取走最后的谁赢 
		
	}
}

void solve(){
	rep(i,1,3){
		rep(j,1,3){
			w[i][j]=0;
			cin>>a[i][j];
		}
	}
	//取掉中间一个的情况
	int nim = 0;
	rep(i,1,3){
		rep(j,1,3){
			if(i==2&&j==2) continue;
			nim^=a[i][j]-1;	
		}
	}
	if(nim==0) w[2][2]=1;
	rep(i,1,4){
		rep(i,1,3){//旋转矩阵 
			rep(j,1,3){
				b[i][j]=a[j][3-i+1];
			}
		}
		rep(i,1,3){//旋转矩阵 
			rep(j,1,3){
				a[i][j]=b[i][j];
			}
		}
		cal();
	}
	cout<<cnt<<endl;
}

int main(){
	int z;
	cin>>z;
	while(z--)solve();
}

