#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f
typedef pair<ll,ll> pll;
const int MAXN = 2077;
#define x first
#define y second
inline ll getdis(pll a,pll b){
    return abs(a.x-b.x) + abs(a.y-b.y);
}
int n,k;
pll a[MAXN];
void solve(){
    cin>>n>>k;
    rep(i,1,n)
        cin>>a[i].x>>a[i].y;
    bool flag = 1;
    rep(i,1,n){
        flag = 1;
        rep(j,1,n){
            if(getdis(a[i],a[j])>k){
                flag = 0;break;
            }
        }
        if(flag){
            break;
        }
    }
    if(flag) cout<<1<<endl;
    else cout<<-1<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}