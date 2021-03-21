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

int n,u,r,l,d;
int a[10];
int b[10];
int dd[10];
int rest[10];
void solve(){
    cin>>n;
    rep(i,0,3){
        cin>>a[i];
        dd[i] = b[i] = 0;
    }
    rep(i,0,3){
        if(a[i]==n-1) dd[i] = 1;
    }
    rep(i,0,3){
        if(a[i]==n){
            b[(i+3)%4]++,b[(i+1)%4]++;
            dd[(i+3)%4]=dd[(i+1)%4]=0;
        }
    }
    rep(i,0,3){
        if(a[i]<b[i]){
            cout<<"NO"<<endl;
            return;
        }
        rest[i] = a[i]-b[i];//还有多少个余裕
    }
    rep(i,0,3){
        if(dd[i]&&dd[(i+1)%4]) dd[i]=dd[(i+1)%4]=0;
    }
    rep(i,0,3){
        if(rest[i]==0){
            if(dd[(i+1)%4]||dd[(i+3)%4]){
                cout<<"NO"<<endl;
                return;
            }
        }

    }
    cout<<"YES"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}