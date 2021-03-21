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
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 114514*10;
int a[MAXN],ys[MAXN];
int ok[MAXN];//记录以i为开头的合理数字数量
int n;
void solve(){
    cin>>n;
    rep(i,1,n){
        cin>>a[i];
        ok[i]=0;
    }
    int hc;
    rep(j,1,n){
        cin>>hc;
        ys[hc]=j;//映射一下
    }
    rep(i,1,n){
        a[i] = ys[a[i]];//对应编号
        //cout<<a[i]<<' ';
    }
    //cout<<endl;
    rep(i,1,n){
        if(a[i]>i) continue;
        ok[i-a[i]+1]++;
    }
    int minn = INF;
    //cout<<"check ok"<<endl;
    rep(i,1,n){
        //cout<<ok[i]<<' ';
        minn = min(minn,n-ok[i]);
    }
    //cout<<endl;
    cout<<minn<<endl;
}

int main(){solve();
}