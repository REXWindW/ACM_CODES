#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
const int MAXN = 114514;
int n;
ll tot;//总时间,记得开ll
int s[MAXN];
int dp[MAXN];
int cf[MAXN];//差分数组，用来标记区间经过几次
void solve(){
    tot = 0;
    cin>>n;
    rep(i,1,n){//初始情况下第一个位置设置为1
        cin>>s[i];
        cf[i]=0;
    }
    cf[1]=1;cf[2]=-1;
    int now = 0;//配合差分数组
    rep(i,1,n){
        now+=cf[i];
        cf[i+1]++;cf[min(n+1,i+s[i]+1)]--;//区间加
        if(now<=s[i]){//
            tot+=s[i]-now;
        }
        else if(now>s[i]){//多出来的部分要个后面的1多加一点
            cf[i+1]+=now-s[i];//多出来的次数也要加上
            cf[i+2]-=now-s[i];
        }
    }
    cout<<tot<<endl;
}
//卧槽秒了，我真牛逼
int main(){
    int z;
    cin>>z;
    while(z--) solve();
}