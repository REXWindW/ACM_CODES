#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f
const int MAXN = 2020;
inline int lowbit(int x){return x&-x;}
int n,q;
int f[MAXN],x[MAXN];
int now;
void solve(){
    cin>>n>>q;
    rep(i,1,q) cin>>f[i]>>x[i];
    int cnt;
    rep(k,0,n){
        cnt = 0;
        rep(i,1,q){
            now = x[i]+k;
            if(f[i]==1){
                while(now<=n+k) now+=lowbit(now),cnt++;
            }
            else if(f[i]==2){
                while(now) now-=lowbit(now),cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}