#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll l,r;//r<=1e18;
const int MAXR = 1e6;
bool vis[MAXR+5];
//sqrt和自己的话之后再
set<ll>st;
void init(){
    st.insert(1);
    for(ll i=2;i<=MAXR;i++){
        if(vis[i]) continue;
        for(ll j=i*i*i;j<=MAXR;j*=i){
            vis[j] = 1;
            st.insert(j);
        }
    }
}
void solve(){
    cin>>l>>r;
    ll sl = sqrt(l),sr = sqrt(r);
    ll res = sr-sl;
    if(sl*sl==l) res++;
    res+=st.upper_bound(r)-st.lower_bound(l);
    cout<<res<<endl;
}

int main(){
    int z;
    init();
    cin>>z;
    while(z--) solve();
}