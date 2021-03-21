#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//假定必须要包含最大的数字
const int MAXN = 114514;
int n;
int a[MAXN];
typedef pair<int,int> pii;
pii res[MAXN];
multiset<int> st;
#define ft first
#define sd second
#define mkp make_pair
void solve(){
    cin>>n;
    rep(i,1,2*n){
        cin>>a[i];
    }
    sort(a+1,a+1+2*n);
    int x;
    rep(i,1,2*n-1){//枚举第二个元素
        st.clear();
        rep(i,1,2*n) st.insert(a[i]);
        st.erase(st.find(a[i]));
        st.erase(st.find(a[n*2]));
        res[1]=mkp(a[i],a[2*n]);
        x = a[2*n];
        bool flag = 1;
        multiset<int>::const_iterator it;
        rep(j,2,n){
            it = st.end();
            it--;
            int now = *it;
            st.erase(it);
            if(now>=x){
                flag=0;break;
            }
            if(st.find(x-now)==st.end()){
                flag=0;break;
            }
            st.erase(st.find(x-now));//擦掉
            res[j] = mkp(now,x-now);
            x = now;
        }
        if(flag){
            cout<<"YES"<<endl;
            cout<<a[i]+a[2*n]<<endl;
            rep(j,1,n) cout<<res[j].ft<<' '<<res[j].sd<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}