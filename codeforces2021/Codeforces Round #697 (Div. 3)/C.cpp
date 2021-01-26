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
int a,b,k;
const int MAXN = 114514*2;
int aa[MAXN],bb[MAXN];//读入a,b
int cnta[MAXN],cntb[MAXN];//记录行列的和
ll res;
void solve(){
    res = 0;
    cin>>a>>b>>k;
    rep(i,1,a) cnta[i] = 0;//计数的清空
    rep(i,1,b) cntb[i] = 0;
    rep(i,1,k){
        cin>>aa[i];
        cnta[aa[i]]++;//aa[i]行的总和增加
    }
    rep(i,1,k){
        cin>>bb[i];
        cntb[bb[i]]++;//bb[i]列的总和增加
    }
    rep(i,1,k){
        res += k-cnta[aa[i]]-cntb[bb[i]]+1;
    }
    cout<<res/2<<endl;//因为两个组合前后顺序无关,所以要除2
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}