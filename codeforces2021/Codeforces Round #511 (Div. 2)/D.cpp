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
ll x,y,res;
ll solve(){
    cin>>x>>y;
    if(y>x) swap(x,y);
    if(x+y<=4&&y!=1){
        return 0;
    }
    if(y==1){
        ll rest = x%6;
        res = x/6*6;
        if(rest==4) res+=2;
        if(rest==5) res+=4;
        return res;
    }
    if(y==2){
        if(x==3) return 4;
        if(x==7) return 12;
    }
    res = x*y;
    if(x*y%2) res--;
    return res;
}

int main(){
    cout<<solve()<<endl;
}