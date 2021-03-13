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
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a;}

const int MAXN = 514;
char a[MAXN][MAXN];
int n,m;

void solve(){
    cin>>n>>m;
    rep(i,1,n){
        rep(j,1,m) cin>>a[i][j];
    }
    if(m==1){
        rep(i,1,n) cout<<'X'<<endl;
        return;
    }
    for(int j=2;j<=m;j+=3){
        rep(i,1,n) a[i][j] = 'X';//挖横栏
        bool flag = 0;
        if(j+3<=m){
            rep(i,1,n){
                if(a[i][j+1]=='X'){
                    a[i][j+2]='X';flag=1;break;
                }
                if(a[i][j+2]=='X'){
                    a[i][j+1]='X';flag=1;break;
                }
            }
            if(!flag) a[1][j+1]=a[1][j+2]='X';//强制让他们连通
        }
    }
    if(m%3==1&&m>1){
        rep(i,1,n)
            if(a[i][m]=='X') a[i][m-1]='X';
    }
    rep(i,1,n){
        rep(j,1,m) cout<<a[i][j];
        cout<<endl;
    }
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}
