#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
typedef pair<int,int> pii;
#define ft first
#define sd second
#define mkp make_pair
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 114514*2;
int n[5];
pii w[5][MAXN];
int res;
set<int> ct[MAXN];//储存冲突
void solve(){
    rep(i,1,4) cin>>n[i];
    rep(i,1,4)
        rep(j,1,n[i]){cin>>w[i][j].ft;w[i][j].sd=j;}
    int hc,u,v;
    res = INF;
    rep(i,2,4){
        sort(w[i-1]+1,w[i-1]+1+n[i-1]);//排序
        rep(j,1,n[i]) ct[j].clear();
        cin>>hc;
        while(hc--){
            cin>>u>>v;
            ct[v].insert(u);
        }
        rep(j,1,n[i]){
            bool flag = 0;
            rep(k,1,n[i-1]){
                if(!ct[j].count(w[i-1][k].sd)){
                    w[i][j].ft+=w[i-1][k].ft;//增加费用
                    flag = 1;
                    break;
                }
            }
            if(!flag) w[i][j].ft = INF;
            if(i==4) res = min(res,w[i][j].ft);
        }
    }
    if(res>=INF) cout<<-1<<endl;
    else cout<<res<<endl;
}

int main(){
    solve();
}