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
const int MAXN = 114514;
int a[MAXN];
int n,m,s,c;
void solve(){
    cin>>n;
    rep(i,1,n)
        cin>>a[i];
    bool flag = 1;
    int dd = a[2]-a[1];
    rep(i,2,n){
        if(a[i]-a[i-1]!=dd){flag=0;break;}
    }
    if(flag){
        cout<<0<<endl;
        return;
    }
    rep(i,2,n){
        if(a[i]>a[i-1]){
            c = a[i]-a[i-1];break;
        }
    }
    rep(i,2,n){
        if(a[i]<a[i-1]){
            m = a[i-1]+c-a[i];break;
        }
    }
    int tmp;
    flag = 1;
    rep(i,2,n){
        tmp = (a[i-1]+c)%m;
        if(a[i]!=tmp){
            flag = 0;break;
        }
    }
    rep(i,1,n){
        if(a[i]>=m) flag = 0;
    }
    if(flag) cout<<m<<' '<<c<<endl;
    else cout<<-1<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}