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

const int MAXN = 5e4+5;
const double eps = 0.001;
// 
double jx,jy; 

struct rob{
	int pos,a;
	friend bool operator < (rob x,rob y){
		if(x.pos>y.pos) return 1;
		else if(x.pos==y.pos&&x.a>y.a) return 1; 
		return 0;
	}
}robo[MAXN];

struct point{
	double x,y;
	int robopx;//记录这个点往后是谁在领跑 
}p[MAXN];

int n; 

rob robo_pre[MAXN]; 

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>robo_pre[i].pos>>robo_pre[i].a;
	}
	sort(robo_pre+1,robo_pre+1+n);
	robo_pre[0] = rob{-1,-1};
	int count_n=0;
	for(int i=1;i<=n;i++){
		if(robo_pre[i].a==robo_pre[i+1].a&&robo_pre[i].pos==robo_pre[i+1].pos){
			i++;
			while(robo_pre[i].a==robo_pre[i-1].a&&robo_pre[i].pos==robo_pre[i-1].pos) i++;
			i--;
		}
		else robo[++count_n] = robo_pre[i];
	}
	n = count_n;
	
	if(n==0){
		cout<<0<<endl;
		return;
	}	
	int maxa=robo[1].a;//到现在为止最大的a
	
	p[0] = point{0,0,1};//p0就是pos在最上面的那个点 
	int countt = 0;//用来记录交点数量
	/*debug	
	for(int i=1;i<=n;i++){
		cout<<'('<<robo[i].pos<<','<<robo[i].a<<')'<<' ';
	}
	cout<<endl;
	*/
	for(int i=2;i<=n;i++){//从第二个点开始
		if(maxa>=robo[i].a) continue;
		//如果有maxa>i.a,则i不可能有机会领跑;
		//这边算是一种剪枝吧
		maxa = robo[i].a;
		//接下来开始二分
		int mid;
		int res=-1;
		int l = 1;
		int r = countt;
		while(l<=r){//二分找第一个在曲线下方的p点 
			mid = (l+r)>>1;
			//带入，看看这个点在抛物线上面还是下面 
			/*debug!
			cout<<"under or upward?"<<i<<endl;
			cout<<robo[i].a*(p[mid].x*p[mid].x)/2+robo[i].pos<<':'<<p[mid].y<<endl;
			cout<<"cha"<<fabs(robo[i].a*(p[mid].x*p[mid].x)/2+robo[i].pos - p[mid].y)<<endl;
			*/
			if(fabs(robo[i].a*(p[mid].x*p[mid].x)/2+robo[i].pos - p[mid].y)<=eps){
				//cout<<"yuedengyu!!"<<endl;
				res = mid;
				break;
			}
			else if(robo[i].a*(p[mid].x*p[mid].x)/2+robo[i].pos > p[mid].y){
				res = mid;
				r = mid-1;
			}
			else{
				l = mid+1;
			} 
		}
		if(res==-1&&mid==r){//找不到满足条件的res点，则要建立新的交点 
			countt++;
		}
		else{//最普通的情况 
			countt = max(1,res);//res之后的交点全部消除掉
		} 
		jx = sqrt(2*(robo[i].pos-robo[p[countt-1].robopx].pos)/(robo[p[countt-1].robopx].a-robo[i].a));
		jy = (jx*jx*robo[i].a)/2 + robo[i].pos;
		p[countt] = point{jx,jy,i};//建立新的交点，插入在合适位置 
		/*debug
		cout<<i<<' '<<countt<<':'<<endl;
		cout<<jx<<' '<<jy<<endl; 
		*/
	}
//	/*
	cout<<"show jiaodian"<<endl;
	for(int i=1;i<=countt;i++){
		cout<<'('<<p[i].x<<','<<p[i].y<<')';
	}
	cout<<endl;
//	*/
	cout<<countt+1<<endl; 
}

int main(){
	int z; 
	cin>>z;
	while(z--) solve();
}
/*
2
8
8 5
7 12
6 17
5 19
5 20
4 21
3 31
2 32
7
8 5
7 12
6 17
5 19
4 21
3 31
2 32
*/

