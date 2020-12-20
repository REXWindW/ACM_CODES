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
int n;
ll a[MAXN];
int minn;
void solve(){
    minn = INF;
    cin>>n;
    ll tmp=0;
    ll now=0;
    rep(i,1,n) cin>>a[i];
    rep(i,1,n){
        tmp+=a[i];
        //cout<<"tmp"<<tmp<<endl;
        now = 0;
        bool flag = 1;
        int res = 0;
        rep(j,1,n){
            now+=a[j];
            //cout<<"now"<<now<<endl;
            if(now==tmp){
                now=0;
            }
            else if(now>tmp){
                flag = 0;
                break;
            }
            else res++;
        }
        if(flag&&now==0){
            //cout<<"tmpres"<<res<<endl;
            minn = min(minn,res);
        }
    }
    cout<<minn<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}