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
typedef pair<int,pii> ppi;
#define ft first
#define sd second
#define mkp make_pair
const int MAXN = 505;
int d[MAXN];
pii p[MAXN];
ppi e[MAXN*MAXN];
vector<ppi> vec;
int n;
void solve(){
    cin>>n;
    rep(i,1,n){
        cin>>d[i];
        p[i]=mkp(d[i],i);
    }
    sort(p+1,p+1+n);
    int l = 1,r = n;//标记可用范围
    while(l<=n&&p[l].ft==0) l++;
    while(r>=1&&p[r].ft==n-1) r--;
    rep(i,l,r-1){
        rep(j,i+1,r){
            vec.push_back(mkp(p[j].ft-p[i].ft,mkp(p[i].sd,p[j].sd)));
        }
    }
    int siz = vec.size();
    sort(vec.begin(),vec.end(),greater<ppi>());
    string s;
    rep(i,0,siz-1){
        cout.flush();
        cout<<"? "<<vec[i].sd.sd<<' '<<vec[i].sd.ft<<endl;
        cin>>s;
        if(s=="Yes"){
            cout.flush();
            cout<<"! "<<vec[i].sd.ft<<' '<<vec[i].sd.sd<<endl;
            return;
        }
    }
    cout.flush();
    cout<<"! "<<0<<' '<<0<<endl;
}

int main(){
    solve();
}