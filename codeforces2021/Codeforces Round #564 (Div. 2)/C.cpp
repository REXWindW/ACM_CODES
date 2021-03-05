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
int a[MAXN];
int b[MAXN];
int n,m;
void solve(){
    cin>>n>>m;
    rep(i,1,n){
        cin>>a[i];
    }
    int l=0,r=m-1;
    bool flag;
    while(l<r){
        int mid = (l+r)>>1;
        flag = 1;
        b[1]=min(a[1],(a[1]+mid)%m);
        rep(i,1,n){
            if((a[i]+mid)%m<a[i]&&(a[i]+mid)%m>=b[i-1]){
                b[i] = b[i-1];
            }
            else if(a[i]<b[i-1]&&a[i]+mid>=b[i-1]) b[i]=b[i-1]; 
            else b[i] = a[i];
        }
        rep(i,2,n){
            if(b[i]<b[i-1]){
                flag=0;break;
            }
        }
        if(flag) r = mid;
        else l = mid+1;
    }
    cout<<r<<endl;
}
int main(){
    solve();
}