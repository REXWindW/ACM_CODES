#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f
const int MAXN = 114514;
int jj[MAXN];
int cnt,x,res;
void init(){
    jj[0] = 0;
    cnt = 1;
    while(jj[cnt-1]<=1e6){
        jj[cnt] = jj[cnt-1]+cnt;
        cnt++;
    }
    cnt--;
}
void solve(){
    cin>>x;
    int px = lower_bound(jj,jj+cnt+1,x) - jj;
    if(jj[px]==x+1) res = px+1;
    else res = px;
    cout<<res<<endl;
}
int main(){
    init();
    int z;
    cin>>z;
    while(z--) solve();
}