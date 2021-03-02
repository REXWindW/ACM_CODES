#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#pragma GCC optimize(2)
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
double vx,vy;
int x,y;
int aa,bb,pp,cc;
const int MAXN = 114514;
double t[MAXN];
void gen(){
    rep(i,0,x){
        t[i]=(double)aa/cc;
        aa=(ll)aa*bb%pp;
    }
}
void solve(){
    scanf("%d%d",&x,&y);
    scanf("%lf%lf",&vx,&vy);
    scanf("%d%d%d%d",&aa,&bb,&cc,&pp);
    gen();
    double res=x/vx+y/vy;
    double tmp;
    rep(a,0,x-1){
        rep(b,1,y){
            tmp = sqrt((ll)(x-a)*(x-a)+(ll)b*b)/log(1+t[a]*b) + a/vx + (y-b)/vy;
            res = min(res,tmp);
        }
    }
    printf("%.4lf\n",res);
}

signed main(){
    int z;
    scanf("%d",&z);
    while(z--) solve();
}