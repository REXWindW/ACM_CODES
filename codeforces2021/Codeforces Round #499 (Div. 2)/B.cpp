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
int a[114]={0},b[114];
int n,m;
void solve(){
    cin>>n>>m;
    int hc;
    rep(i,1,m){
        cin>>hc;
        a[hc]++;
    }
    int l=0,r=110;
    int mid;
    while(l<r-1){
        int peo = 0;
        mid=(l+r)>>1;
        rep(i,1,100) b[i]=a[i];
        rep(i,1,100){
            while(b[i]-mid>=0){
                b[i]-=mid;
                peo++;
            }
        }
        if(peo>=n) l=mid;
        else r=mid;
    }
    cout<<l<<endl;
}

int main(){
    solve();
}