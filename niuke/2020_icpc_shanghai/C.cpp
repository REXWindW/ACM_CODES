#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f
#define double long double
const double pi = acos(-1);

int n,m;
int jj[666];
void initjj(){
    jj[0] = 0;
    rep(i,1,500)
        jj[i] = jj[i-1]+i;
}
void solve(){
    scanf("%d%d",&n,&m);//n个圈
    double fy = pi/m;//单位角度
    //int fjd = floor(2/fy);//找到2的分界点
    //cout<<fjd<<endl;
    double res = 0;
    //fjd以内都走弧，fjd+1以及往上都走半径2r
    rep(i,1,n){//n个同心圆，第i个半径i
        if(m!=1)res+=i;//往圆心的情况
        rep(j,0,m-1){
            double hudu = j*fy*i;
            if(hudu<2*i){
                res+=(jj[n-i]+(n-i)*hudu);//到比它高的
                res+=hudu/2;//到同高的
            }
            else{//j>fjd的情况,走里面
                res+=(jj[n-i]+2*(n-i)*i);
                res+=i;//同高的
            }
        }
        rep(j,1,m){
            double hudu = j*fy*i;
            if(hudu<2*i){
                res+=(jj[n-i]+(n-i)*hudu);//到比它高的
                res+=hudu/2;//到同高的
            }
            else{//j>fjd的情况,走里面
                res+=(jj[n]-jj[i]+(n-i)*i);
                res+=i;
            }
        }
    }
    res *= m*2;
    printf("%.10Lf\n",res);
}

int main(){
    initjj();
    solve();
}