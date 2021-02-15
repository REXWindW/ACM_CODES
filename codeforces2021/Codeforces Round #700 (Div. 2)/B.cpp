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
const int MAXN = 114514;
#define int ll
#define ft first
#define sd second
typedef pair<int,int> pii;
pii a[MAXN];
int aa,bb,n;
void solve(){
    cin>>aa>>bb>>n;
    rep(i,1,n) cin>>a[i].ft;
    rep(i,1,n) cin>>a[i].sd;
    sort(a+1,a+1+n);//先解决攻击力低的
    int t;
    bool flag = 0;
    rep(i,1,n){
        t = (a[i].sd +aa-1)/aa;
        bb-=t*a[i].ft;
        if(bb<=0){
            if(bb+a[i].ft>0&&i==n){
                flag = 1;
            }
            else break;
        }
    }
    if(bb>0||flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main(){
    int z;
    cin>>z;
    while(z--) solve();
}