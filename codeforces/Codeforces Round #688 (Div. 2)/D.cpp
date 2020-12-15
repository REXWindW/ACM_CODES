#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f
int a[2077];
ll f[2020];
ll k;
void solve(){
    cin>>k;
    if(k%2){cout<<-1<<endl;return;}
    ll now = 0;
    a[1] = 1;
    f[1] = 2;
    now+=2;//a1
    int i;
    for(i=2;now<k;i++){
        if(now+f[i-1]*2<=k){
            a[i] = 0;
            f[i] = f[i-1]*2;
        }
        else{
            a[i] = 1;
            f[i] = 2;
        }
        now+=f[i];
    }
    i--;
    cout<<i<<endl;
    rep(j,1,i){
        cout<<a[j]<<' ';
    }
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}