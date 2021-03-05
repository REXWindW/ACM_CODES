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
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 3e5+5;
int a[MAXN],b[MAXN];
int n,m;
int x,y;
int px;
bool check(){
    //cout<<"check!!"<<x<<' '<<y<<endl;
    rep(i,px+1,m){
        if(a[i]!=x&&b[i]!=x&&a[i]!=y&&b[i]!=y){
            //cout<<"fail"<<i<<endl;
            return 0;
        }
    }
    return 1;
}
void solve(){
    cin>>n>>m;
    rep(i,1,m)
        cin>>a[i]>>b[i];

    x=a[1];
    px = 0;
    rep(i,2,m){
        if(a[i]!=x&&b[i]!=x){
            px = i;break;//标记px
        }
    }
    if(px==0){
        cout<<"YES"<<endl;
        return;
    }
    y=a[px];
    if(check()){
        cout<<"YES"<<endl;
        return;
    }
    y=b[px];
    if(check()){
        cout<<"YES"<<endl;
        return;
    }

    x=b[1];
    px = 0;
    rep(i,2,m){
        if(a[i]!=x&&b[i]!=x){
            px = i;break;
        }
    }
    if(px==0){
        cout<<"YES"<<endl;
        return;
    }
    y=a[px];
    if(check()){
        cout<<"YES"<<endl;
        return;
    }
    y=b[px];
    if(check()){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main(){
    solve();
}