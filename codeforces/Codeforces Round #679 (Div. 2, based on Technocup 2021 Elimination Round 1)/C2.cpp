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
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define mkp make_pair
#define ft first
#define sd second
typedef pair<ll,ll> pll;
const int MAXN = 1e5+5;
ll a[8];
ll b[MAXN];
int in[MAXN];
int n;
set<pll>st;
void solve(){
	int m = 6;
	rep(i,1,m) cin>>a[i];
	sort(a+1,a+1+m);
	m = unique(a+1,a+1+m)-a-1;
	cin>>n;
	rep(i,1,n) cin>>b[i];
    sort(b+1,b+1+n);
	n = unique(b+1,b+1+n)-b-1;
	//这里其实没太大必要去重，但是我想了一下还是去重了
    rep(i,1,n){
        in[i] = m;
        st.insert(mkp(b[i]-a[m],(ll)i));//一开始都是用m弦弹的
    }
    ll minn = st.rbegin()->ft-st.begin()->ft;
    while(1){
        pll now = *st.begin();
        st.erase(st.begin());//这边的参数是迭代器,这样删复杂度更小
        if(in[now.sd]==1) break;
        //如果最小的都是1,那么其他的音符换弦也不可能让结果更小了,因为往下换只会让bi-aj更大
        in[now.sd]--;//每次换成更小的弦
        st.insert(mkp(b[now.sd]-a[in[now.sd]],now.sd));
        minn = min(minn,st.rbegin()->ft-st.begin()->ft);
    }
    cout<<minn<<endl;
}
int main(){
    solve();
}