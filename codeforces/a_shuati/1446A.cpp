#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
#define mkp make_pair
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int MAXN = 2e5+5;
typedef pair<ll,int> pli;
#define ft first
#define sd second
int n;
ll w,half;
ll a[MAXN];
vector<pli> vec;
void solve(){
    vec.clear();
    cin>>n>>w;
    half = (w+1)/2;
    ll summ = 0;
    rep(i,1,n){cin>>a[i];summ+=a[i];}
    if(summ<half){cout<<-1<<endl;return;}
    rep(i,1,n){
        if(a[i]>=half&&a[i]<=w){cout<<1<<endl<<i<<' '<<endl;return;}
        vec.push_back(mkp(a[i],i));
    }
    sort(vec.begin(),vec.end());
    if(vec[0].ft>w){cout<<-1<<endl;return;}
    int cnt = vec.size();
    while(vec[cnt-1].ft>w) cnt--;
    ll tot = 0;
    rep(i,0,cnt-1){
        tot+=vec[i].ft;
        if(tot>=half){
            cout<<i+1<<endl;
            rep(j,0,i) cout<<vec[j].sd<<' ';
            cout<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}
int main(){
    int z;
    cin>>z;
    while(z--) solve();
}