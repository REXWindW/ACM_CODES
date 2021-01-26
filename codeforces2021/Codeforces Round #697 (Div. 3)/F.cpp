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

const int MAXN = 1145;
int a[MAXN][MAXN],b[MAXN][MAXN];
int jiou[MAXN][MAXN];//记录每个格子上操作了几次
int x[MAXN],y[MAXN];//分别记录行和列上操作了几次
int n;
bool judge(){//判断行列操作数和格子操作数是否匹配
    rep(i,1,n)
        rep(j,1,n)
            if(jiou[i][j]!=(x[i]^y[j])) return 0;
    return 1;
}
void solve(){
    cin>>n;
    char hc;
    rep(i,1,n){
        rep(j,1,n){
            cin>>hc;
            a[i][j]=hc-'0';
        }
    }
    rep(i,1,n){
        rep(j,1,n){
            cin>>hc;
            b[i][j]=hc-'0';
            jiou[i][j] = b[i][j]^a[i][j];
        }
    }
    bool flag = 0;
    x[1] = 0;//先假设第一行是偶数
    rep(j,1,n) y[j] = jiou[1][j];
    rep(i,2,n) x[i] = jiou[i][1]^y[1];
    if(judge()) flag = 1;
    x[1] = 1;//再设第一行是奇数
    rep(j,1,n) y[j] = jiou[1][j]^1;
    rep(i,2,n) x[i] = jiou[i][1]^y[1];
    if(judge()) flag = 1;
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}