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

const double eps = 1e-8;
double x,y,vx,vy,L;
double h,cardv;
int k;
const double Pi = 2*acos(0);

int get_jd(double x,double y,double vx,double vy,double t){//计算有几个交点 
	if(vy==0){return 0;}
	if(vy>0){ vy=-vy; y=h-y; }
	int ret = 1;
	double tl = (-vy)*t-y;
	ret += floor(tl/h);//每次只看和x轴平行的角线 
	return ret;
}

void solve(){
	scanf("%lf%lf%lf%lf%lf%d",&L,&x,&y,&vx,&vy,&k);
	h = L*sqrt(3)/2;
	int tot = 0;
	double zx = 0;//中心点坐标 
	double zy = h/3;
	double xx,yy,vvx,vvy;
	double mid;
	cardv = sqrt(vx*vx+vy*vy);
	double l=0,r=k*L/cardv;
	while(r-l>eps){
		mid = (l+r)/2;
		tot= get_jd(x,y,vx,vy,mid);//统计交点总数 
		//旋转 120度 
		xx = (x-zx)*cos(2*Pi/3) - (y-zy)*sin(2*Pi/3) + zx;
		yy = (x-zx)*sin(2*Pi/3) + (y-zy)*cos(2*Pi/3) + zy;
		vvx = vx*cos(2*Pi/3) - vy*sin(2*Pi/3);
		vvy = vx*sin(2*Pi/3) + vy*cos(2*Pi/3);
		tot+=get_jd(xx,yy,vvx,vvy,mid);
		//再旋转 240度 
		xx = (x-zx)*cos(4*Pi/3) - (y-zy)*sin(4*Pi/3) + zx;
		yy = (x-zx)*sin(4*Pi/3) + (y-zy)*cos(4*Pi/3) + zy;
		vvx = vx*cos(4*Pi/3) - vy*sin(4*Pi/3);
		vvy = vx*sin(4*Pi/3) + vy*cos(4*Pi/3);
		tot+=get_jd(xx,yy,vvx,vvy,mid);
		if(tot>=k) r = mid;
		else l = mid;
	}
	printf("%.8llf\n",mid);
}

int main(){
	int z;
	scanf("%d",&z);
	while(z--) solve();
}

