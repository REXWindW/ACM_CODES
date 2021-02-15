#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
typedef pair<int,int> pii;//绩效,位置
#define mkp make_pair
#define ft first
#define sd second
int n,b;
const int MAXN = 1e5+5;
int a[MAXN];
int res[MAXN];
pii aa[MAXN];
void solve(){
    cin>>n>>b;
    rep(i,0,n-1){
        cin>>a[i];
        aa[i]=mkp(a[i],i);
    }
    sort(aa,aa+n);
    rep(i,0,n-1){
        int x = aa[i].sd;
        if(a[x]>a[(x+n-1)%n]){
            res[x]=max(res[x],res[(x+n-1)%n]+1);
            //cout<<'!'<<endl;
        }
        if(a[x]>a[(x+1)%n]){
            res[x]=max(res[x],res[(x+1)%n]+1);
            //cout<<'?'<<endl;
        }
        if(a[x]==0) res[x]=max(res[x],0);
        else res[x]=max(res[x],1);
    }
    rep(i,0,n-1){
        cout<<(ll)b*res[i];
        if(i!=n-1) cout<<' ';
    }
    cout<<endl;
}

int main(){
    solve();
}