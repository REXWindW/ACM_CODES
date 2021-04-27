#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
#define ft first
#define sd second
#define mkp make_pair
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int MAXN = 1145140;
#define INF 0x7fffffff
int cnt[MAXN];
int maxx,minn;
int hc,n;
void solve(){
    maxx = -1;
    minn = INF;
    cin>>n;
    rep(i,1,n){
        cin>>hc;
        cnt[hc]++;
        maxx = max(maxx,hc);
        minn = min(minn,hc);
    }
    cout<<minn<<' '<<cnt[minn]<<endl;
    cout<<maxx<<' '<<cnt[maxx]<<endl;
}
int main(){
    solve();
}