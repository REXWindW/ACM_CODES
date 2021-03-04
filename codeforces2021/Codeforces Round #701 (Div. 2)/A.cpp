#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
int a,b;
void solve(){
    //我的想法是要么用2要么用3?
    cin>>a>>b;
    int res = INF;
    int aa,tmp = 0;
    int sqr = sqrt(a);
    rep(i,b,sqr+1){
        if(i==1) continue;
        tmp=i-b;
        aa=a;
        while(aa){
            aa/=i;
            tmp++;
        }
        res = min(res,tmp);
    }
    if(b!=1){
        tmp = 0;aa = a;
        while(aa){
            aa/=b;
            tmp++;
        }
        res = min(res,tmp);
    }
    cout<<res<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}