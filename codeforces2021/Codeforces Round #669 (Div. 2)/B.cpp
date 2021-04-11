#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int n;
const int MAXN = 1145;
int a[MAXN];
int b[MAXN];
bool vis[MAXN];
int x,y;
void solve(){
    cin>>n;
    x = 0;
    rep(i,1,n){
        cin>>a[i];
        vis[i] = 0;
        if(a[i]>a[x])x = i;
    }
    vis[x] = 1;
    int now = a[x];
    int ngcdd;
    b[1] = a[x];
    rep(i,2,n){
        ngcdd = 0;
        rep(j,1,n){
            if(vis[j]) continue;
            if(gcd(now,a[j])>ngcdd){
                ngcdd = gcd(now,a[j]);
                y = j;
            }
        }
        //cout<<"fy"<<y<<endl;
        vis[y] = 1;
        now = ngcdd;
        b[i] = a[y];
    }
    rep(i,1,n) cout<<b[i]<<' ';
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}