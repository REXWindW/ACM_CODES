#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
using namespace std;
#define ll long long
typedef pair<ll,ll> pii;
#define ft first
#define int ll
#define sd second
#define mkp make_pair
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int n,m,q;
const int MAXN = 514514;
vector<pii> e[MAXN];//存目的地,现金费用
vector<pii> re[MAXN];//存目的地,旅游金费用
//现金只能一次性全部换成旅游金!也就是说旅途分成两段,一段前面一段后面！
//费用换算成旅游金来统计?
//从两侧开始1ton，nto1做两次dij?
priority_queue<pii,vector<pii>,greater<pii>> qe;
ll zheng[MAXN];
bool zvis[MAXN];
ll fan[MAXN];
bool fvis[MAXN];
ll a[MAXN];
set<pii> st;
inline ll chu(ll x,ll y){
    return (x+y-1)/y;
}
inline void solve(){
    cin>>n>>m>>q;
    int u,v,c,d;//c现金d旅游金
    rep(i,1,m){
        cin>>u>>v>>c>>d;
        e[u].push_back(mkp(v,c));
        re[v].push_back(mkp(u,d));
    }
    rep(i,1,n) cin>>a[i];//汇率
    //正着用现金做最短路
    qe.push(mkp(0,1));
    while(!qe.empty()){
        pii now = qe.top();
        qe.pop();
        if(zvis[now.sd]) continue;
        zvis[now.sd] = 1;
        zheng[now.sd] = now.ft;
        for(auto tmp:e[now.sd]){
            qe.push(mkp(now.ft+tmp.sd,tmp.ft));
        }
    }
    //反着用奖励做最短路
    qe.push(mkp(0,n));
    while(!qe.empty()){
        pii now = qe.top();
        qe.pop();
        if(fvis[now.sd]) continue;
        fvis[now.sd] = 1;
        fan[now.sd] = now.ft;
        for(auto tmp:re[now.sd]){
            qe.push(mkp(now.ft+tmp.sd,tmp.ft));
        }
    }
    rep(i,1,n){
        st.insert(mkp(zheng[i]+chu(fan[i],a[i]),i));
    }
    ll ti,ta;
    /*
    cout<<"check"<<endl;
    rep(i,1,n)cout<<zheng[i]<<' ';
    cout<<endl;
    rep(i,1,n)cout<<fan[i]<<' ';
    cout<<endl;
    */
    while(q--){
        cin>>ti>>ta;
        st.erase(mkp(zheng[ti]+chu(fan[ti],a[ti]),ti));
        a[ti] = ta;
        st.insert(mkp(zheng[ti]+chu(fan[ti],a[ti]),ti));
        set<pii>::iterator it;//迭代器
        it = st.begin();
        cout<<it->ft<<endl;
    }
}
signed main(){
    solve();
}