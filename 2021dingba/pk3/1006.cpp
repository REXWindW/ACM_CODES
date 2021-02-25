#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#include<tr1/unordered_map>
using namespace std;
using namespace std::tr1;
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
const int MAXN = 1e7+5;
const int med = 1e9+9;
int fb[3];
ll x;
inline void solve(){
    cin>>x;
    if(x==0||x==1){
        cout<<x<<endl;
        return;
    }
    fb[0] = 0;
    fb[1] = 1;
    rep(i,2,MAXN-1){
        fb[2] = (fb[0]+fb[1])%med;
        if(fb[2]==x){
            cout<<i<<endl;
            return;
        }
        fb[0]=fb[1];fb[1]=fb[2];
    }
    cout<<-1<<endl;
    return;
}

signed main(){
    int z;
    cin>>z;
    while(z--) solve();
}