#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
#define ft first
#define sd second
#define mkp make_pair
const int MAXN = 114514;
int n,m;
int res[MAXN];
ppi a[MAXN];
vector<int> av[MAXN];
int cnt[MAXN];//记录出现次数
void solve(){
    cin>>n>>m;
    rep(i,1,n) cnt[i] = 0;
    rep(i,1,m){
        av[i].clear();
        a[i].sd = i;//存编号
        cin>>a[i].ft.ft;//有多少个数字
        int hc;
        rep(j,1,a[i].ft.ft){
            cin>>hc;
            av[i].push_back(hc);
        }
        sort(av[i].begin(),av[i].end());
        a[i].ft.sd = av[i][0];
    }
    sort(a+1,a+1+m);
    rep(i,1,m){
        if(a[i].ft.ft==1){
            cnt[a[i].ft.sd]++;
            res[a[i].sd]=a[i].ft.sd;
        }
        else{
            int bh = a[i].sd;
            if(cnt[av[bh][0]]<cnt[av[bh][1]]){
                res[bh] = av[bh][0];
            }
            else res[bh] = av[bh][1];
            cnt[res[bh]]++;
        }
    }
    bool flag = 1;
    int maxx = (m+1)/2;
    rep(i,1,n){
        if(cnt[i]>maxx){flag = 0;break;}
    }
    if(flag){
        cout<<"YES"<<endl;
        rep(i,1,m) cout<<res[i]<<' ';
        cout<<endl;
    }
    else cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}