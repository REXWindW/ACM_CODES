#include<iostream>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define INF 0x7f7f7f7f
int hc;
int n,m;
int zo,cnt;
ll res;
int minn;
void solve(){
    cin>>n>>m;
    res = zo = cnt = 0;
    minn = INF;
    rep(i,1,n){
        rep(j,1,m){
            cin>>hc;
            if(hc<0) cnt++;
            if(hc==0) zo=1;
            res += abs(hc);
            minn = min(minn,abs(hc));
        }
    }
    if(zo||(cnt%2==0)) cout<<res<<endl;
    else cout<<res-2*minn<<endl;
}
int main(){
    int z;
    cin>>z;
    while(z--) solve();
}