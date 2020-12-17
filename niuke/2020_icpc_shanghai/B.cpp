#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f
const int MAXN = 2077;
bool a[MAXN][MAXN],b[MAXN][MAXN];
int n,m;
void solve(){
    cin>>n>>m;
    char hc;
    rep(i,1,n){
        rep(j,1,m){
            cin>>hc;
            a[i][j] = hc=='X';
        }
    }
    int cnt = 0;
    int maxx = m*n>>1;
    rep(i,1,n){
        rep(j,1,m){
            cin>>hc;
            b[i][j] = hc=='X';
            if(b[i][j]!=a[i][j]) cnt++;
        }
    }
    if(cnt<=maxx){
        rep(i,1,n){
            rep(j,1,m){
                if(a[i][j]==1) cout<<'X';
                else cout<<'.';
            }
            cout<<endl;
        }
    }
    else{
        rep(i,1,n){
            rep(j,1,m){
                if(a[i][j]==1) cout<<'.';
                else cout<<'X';
            }
            cout<<endl;
        }
    }
}

int main(){
    solve();
}