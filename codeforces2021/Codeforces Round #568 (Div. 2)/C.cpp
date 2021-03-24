#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int n,m;
const int MAXN = 2*114514;
int t[MAXN];
int cnt[105];
int tot;

void solve(){
    cin>>n>>m;
    rep(i,1,n) cin>>t[i];
    cout<<0<<' ';
    cnt[t[1]]=1;
    rep(i,2,n){
        int tot = t[i],cntt = 0,cha,ge;
        rep(j,1,100){
            if(cnt[j]==0) continue;
            //cout<<"in"<<j<<endl;
            if(tot+j*cnt[j]<m){
                cntt+=cnt[j];
                tot+=j*cnt[j];
            }
            else{
                cha = m-tot;
                ge = cha/j;
                cntt+=ge;
                break;
            }
        }
        cnt[t[i]]++;
        cout<<i-cntt-1<<' ';
    }
    cout<<endl;
}

int main(){
    solve();
}