#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<cstdio>
#include<algorithm>
using namespace std;

//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define int ll
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f

const ll LINF = 1ll<<60;
const int MAXN = 114514*5;
set<ll>::iterator it;
ll a[MAXN],aa[MAXN];
ll b[MAXN];//两个数字间末尾的数字
set<ll> st;
int n,m;
ll min1,min2;//分别记录两种询问的最小值
void solve(){
    min1 = min2 = LINF;
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
        min1 = min(min1,abs(a[i]-a[i-1]));
        min2 = min(min2,abs(aa[i]-aa[i-1]));
    }
    char hc[10];
    ll pos,num;
    rep(i,1,m){
        scanf("%s",hc);
        if(hc[0]=='i'){
            scanf("%lld%lld",&pos,&num);
            //更新min1
            min1 = min(min1,abs(a[pos+1]-num));
            min1 = min(min1,abs(num-b[pos]));
            b[pos] = num;
            //更新min2,集合中找前驱后继
            it = st.lower_bound(num);
            min2 = min(min2,abs(*it-num));
            it--;
            min2 = min(min2,abs(num-*it));
            it = st.upper_bound(num);
            min2 = min(min2,abs(*it-num));
            st.insert(num);
            //cout<<"now min1:"<<min1<<' '<<"min2:"<<min2<<endl;
        }
        else if(hc[6]=='1'){
            printf("%lld\n",min1);
        }
        else if(hc[6]=='2'){
            printf("%lld\n",min2);
        }
    }
}

signed main(){
    solve();
}