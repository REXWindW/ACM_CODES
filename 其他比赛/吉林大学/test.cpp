#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iomanip>
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
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a;}
//#define INF 0x7fffffff

int m,n;
const int MAXN = 15;
bool a[MAXN][MAXN];
bool vis[MAXN][MAXN];
int x1,y1,x2,y2;

int dir[4][2] = {0,1,1,0,0,-1,-1,0};

bool OK(int x,int y){
	return x&&y&&x<=m&&y<=n;
}

struct Node{
	int x, y;
	int steps;
};

void bfs(){
	int countt = -1;
	queue<Node> q;
	q.push(Node{x1,y1,0});
	Node now;
	while(!q.empty()){
		now = q.front();
		q.pop();
		if(now.x==x2&&now.y==y2){
			countt = now.steps;
			break;
		}
		for(int i=0;i<4;i++){
			int nx = now.x+dir[i][0];
			int ny = now.y+dir[i][1];
			if(!vis[nx][ny]&&OK(nx,ny)&&!a[nx][ny]){
				q.push(Node{nx,ny,now.steps+1});
				vis[nx][ny] = 1;
			}
			else if(a[nx][ny]==1&&a[nx+dir[i][0]][ny+dir[i][1]]==0){
				nx = nx+dir[i][0];
				ny = ny+dir[i][1];
				if(!vis[nx][ny]&&OK(nx,ny)&&!a[nx][ny]) {
					q.push(Node{nx,ny,now.steps+1});
					vis[nx][ny] = 1;
				}
			}
		}
	}
	cout<<countt<<endl;
}

void solve(){
	char hc;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>hc;
			vis[i][j] = 0;
			a[i][j] = (hc=='*');
		}
	}
	cin>>x1>>y1>>x2>>y2;
	bfs();
	
}

int main(){
	while(cin>>m>>n){
		solve();
	}
}
