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
int dir[8][2]={1,0,0,1,-1,0,0,-1,1,1,1,-1,-1,1,-1,-1};
const int MAXN = 26;
int a[MAXN][MAXN]={0};
int res[MAXN][MAXN];

int main(){
	//freopen("inp.txt","r",stdin);
	freopen("outp.txt","w",stdout);
	char c;
	int x,y;
	while(cin>>x>>y){
		memset(a,0,sizeof(a)); 
		rep(i,1,x){
			rep(j,1,y){
				res[i][j]=0;
				cin>>c;
				if(c=='X')a[i][j]=1;
				else a[i][j]=0;
			}
		}
		ll tot = 0;
		rep(i,1,x){
			rep(j,1,y){
				int dx,dy;
				if(a[i][j]==0){
					rep(k,0,7){
						dx = i+dir[k][0];dy = j+dir[k][1];
						if(a[dx][dy]) res[i][j]++;
					}
					tot+=res[i][j];
				}
			}
		}
		cout<<tot<<endl;
	}
}

