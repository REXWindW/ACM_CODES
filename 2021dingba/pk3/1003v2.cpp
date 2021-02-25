#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;

//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define int ll
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plp;//数值,位置pos,插入时是第几个数
#define ft first
#define sd second
#define mkp make_pair
const ll LINF = 1ll<<60;
const int MAXN = 114514*5;
set<ll>::iterator it;
ll a[MAXN],aa[MAXN];
ll b[MAXN];//两个数字间末尾的数字
ll cnta[MAXN];//记录后面有几个数字
set<ll> st;
int n,m;
ll min2;//分别记录两种询问的最小值
priority_queue<plp,vector<plp>,greater<plp>> q;
//我懂错在哪里了，错在Min1是有可能变大的，用priorityqueue？
void solve(){
    min2 = LINF;
    //cout<<LINF<<endl;
    st.insert(LINF);st.insert(-LINF);//放两个很大的！
    scanf("%lld%lld",&n,&m);
    a[n+1]=LINF;
    rep(i,1,n){
        scanf("%lld",&a[i]);
        b[i]=aa[i]=a[i];
        st.insert(a[i]);
    }
    sort(aa+1,aa+1+n);
    rep(i,2,n){
        q.push(mkp(abs(a[i]-a[i-1]),mkp(i-1,0)));
        min2 = min(min2,abs(aa[i]-aa[i-1]));
    }
    char hc[10];
    ll pos,num,cntt;
    rep(i,1,m){
        scanf("%s",hc);
        if(hc[0]=='i'){
            scanf("%lld%lld",&pos,&num);
            cnta[pos]++;
            //更新min1
            q.push(mkp( abs(a[pos+1]-num),mkp(pos,cnta[pos]) ));//和后面的
            q.push(mkp( abs(num-b[pos]),mkp(-1,-1)           ));//这种是不会被消去的
            b[pos] = num;
            //更新min2,集合中找前驱后继
            it = st.lower_bound(num);
            min2 = min(min2,abs(*it-num));
            it--;
            min2 = min(min2,abs(num-*it));
            st.insert(num);
        }
        else if(hc[6]=='1'){
            while(1){
                if(q.top().sd.ft==-1) break;
                pos = q.top().sd.ft,cntt = q.top().sd.sd;
                if(cnta[pos]==cntt) break;
                q.pop();
            }
            //cout<<"checktop"<<q.top().sd.ft<<' '<<q.top().sd.sd<<endl;
            printf("%lld\n",q.top().ft);
        }
        else if(hc[6]=='2'){
            printf("%lld\n",min2);
        }
    }
}

signed main(){
    solve();
}