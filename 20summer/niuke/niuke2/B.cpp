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

const double eps = 1;
const double eps2 = 0.001;
const int MAXN = 2020;

struct point{
	double x;
	double y;
	friend bool operator < (point a,point b){
		if(a.x>b.x) return 0;
		else if(a.x==b.x&&a.y>b.y) return 0;
		return 1;
	}
};

double x1,x2,x3,yy1,y2,y3,a1,b1,c1,a2,b2,c2;

point cal(point a,point b){
	if(fabs(a.x*b.y-b.x*a.y)<eps) return point{1e10,1e10};//不存在这个点 
	x1 = a.x;yy1 = a.y;
	x2 = b.x;y2 = b.y;
	x3 = 0; y3 = 0;
	a1 = 2*(x2-x1); a2 = 2*(x3-x2);
	b1 = 2*(y2-yy1); b2 = 2*(y3-y2);
	c1 = x2*x2 + y2*y2 - x1*x1 - yy1*yy1;
	c2 = x3*x3 + y3*y3 - x2*x2 - y2*y2;
	double rx = (c1*b2-c2*b1)/(a1*b2-a2*b1);
	double ry = (c2*a1-c1*a2)/(a1*b2-a2*b1);
	return point{rx,ry};
}

point a[MAXN];
vector<point> vec;

int main(){
	int n;
	cin>>n;
	rep(i,1,n){
		cin>>a[i].x>>a[i].y;
	} 
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			point yx = cal(a[i],a[j]);
			if(yx.x==1e10&&yx.y==1e10) continue;
			vec.push_back(yx);
		}
	}
	sort(vec.begin(),vec.end());
	int siz = vec.size();
	ll maxx = 1;
	ll countt = 1;
	for(int i=1;i<siz;i++){
		if(vec[i].x==vec[i-1].x&&vec[i].y==vec[i-1].y){
			countt++;
		}
		else countt = 1;
		maxx = max(maxx,countt);
	}
	int res = (1+sqrt(1+8*maxx))/2;
	cout<<res<<endl;
}

