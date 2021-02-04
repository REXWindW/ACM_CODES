#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
const int MAXN = 1145;
bool OK[MAXN][MAXN];
ll enj[MAXN];
ll n,m,k;

void solve(){
    cin>>n>>m>>k;
    rep(i,1,n) cin>>enj[i];
    char hc;
    rep(i,1,n){
        rep(j,1,m){
            cin>>hc;
            OK[i][j]=(hc=='1');
        };
    }
    ll l = 1,r = n+1;
    ll mid;
    ll res;
    vector<ll> vec;
    while(l<r){
        res = 0;
        mid = (l+r)>>1;
        rep(i,1,m){
            vec.clear();
            rep(j,1,n)
                if(OK[j][i]) vec.push_back(enj[j]);
            ll siz = min((ll)vec.size(),mid);
            sort(vec.begin(),vec.end(),greater<int>());
            rep(i,0,siz-1) res+=vec[i];
        }
        if(res>=k) r = mid;
        else if(res<k) l = mid+1;
    }
    if(r==n+1) cout<<-1<<endl;
    else cout<<r<<endl;
}

int main(){
    solve();
}