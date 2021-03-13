#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<set>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define mkp make_pair
#define ft first
#define sd second
#define log(x) (31-__builtin_clz(x))
#define INF 0x3f3f3f3f
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff
const int MAXN = 114514*4;
const int MAXNNN = 5e6+5;
int a[MAXN];
int sz[MAXNNN];
int yxl[MAXN];//原序列
int n;
int cnt[MAXNNN];//记录差值
int ma[MAXNNN],mi[MAXNNN];//记录右端点最大最小
void solve(){
    rep(i,0,MAXNNN-2){
        ma[i] = -1;
        mi[i] = INF;
    }
    int maxx = 0;
    cin>>n;
    rep(i,1,n){
        cin>>a[i];
        yxl[i] = a[i];
        maxx = max(maxx,a[i]);
        sz[a[i]]++;
    }
    sort(a+1,a+1+n);
    int res = 0;
    rep(i,3,n){
        rep(j,1,i-1){
            if(cnt[a[i]-a[j]]){
                if(ma[a[i]-a[j]]==j&&mi[a[i]-a[j]]==j)
                    continue;
                res = a[i]-a[j];
                break;
            }
        }
        rep(j,1,i-2){
            cnt[a[i-1]-a[j]]++;
            ma[a[i-1]-a[j]] = max(ma[a[i-1]-a[j]],i-1);
            mi[a[i-1]-a[j]] = min(mi[a[i-1]-a[j]],i-1);
        }
    }
    if(res==0){
        cout<<"NO"<<endl;
        return;
    }
    int flag = 0;int rs[5];
    rep(i,1,maxx){
        if(flag==0){
            if(i+res<=maxx&&sz[i]&&sz[i+res]){
                rs[1] = i;rs[2] = i+res;
                flag = 1;
                sz[i]--;sz[i+res]--;
            }
        }
        if(flag==1){
            if(i+res<=maxx&&sz[i]&&sz[i+res]){
                rs[3] = i;rs[4] = i+res;
                break;
            }
        }
    }
    int rss[5];
    rep(i,1,4){
        rep(j,1,n){
            if(yxl[j]==rs[i]){
                rss[i] = j;
                yxl[j] = -1;
                break;
            }
        }
    }
    cout<<"YES"<<endl;
    cout<<rss[1]<<' '<<rss[4]<<' '<<rss[2]<<' '<<rss[3]<<' '<<endl;
}

int main(){
    solve();
}