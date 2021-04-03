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
typedef pair<int,pii> pip;
#define ft first
#define sd second
#define mkp make_pair
const int MAXN = 505;
pii p[MAXN];
vector<pip> vec;
bool vis[MAXN][MAXN];
bool e[MAXN][MAXN];
int d[MAXN];
int n;
void solve(){
    cin>>n;
    rep(i,1,n){
        cin>>d[i];
        p[i] = mkp(d[i],i);
    }
    sort(p+1,p+1+n);//sort一下
    int l=1,r=n;
    while(l<=n&&p[l].sd==0) l++;
    while(r>=1&&p[r].sd==n-1) r--;
    if(l>=r){
        cout.flush();
        cout<<"! 0 0"<<endl;
        return;
    }
    rep(i,l,r-1){
        rep(j,i+1,r){
            vec.push_back(mkp(p[j].ft-p[i].ft,mkp(p[i].sd,p[j].sd)));
        }
    }
    sort(vec.begin(),vec.end(),greater<pip>());
    int siz = vec.size();
    pip now;
    string s;
    rep(i,0,siz-1){
        now = vec[i];
        cout.flush();
        cout<<"? "<<now.sd.ft<<' '<<now.sd.sd<<endl;
        cin>>s;
        if(s=="Yes"){
            cout<<"! "<<now.sd.ft<<' '<<now.sd.sd<<endl;
            return;
        }
    }
    cout.flush();
    cout<<"! 0 0"<<endl;
}
int main(){
    solve();
}