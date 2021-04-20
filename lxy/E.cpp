#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }

int l,x,y,d;
void solve(){
    cin>>l>>x>>y>>d;
    double hh = sqrt(3)*l-y;
    double dd = hh/sqrt(3);
    double cha = dd-x;
    //cout<<"D"<<d<<"L"<<l<<endl;
    int res = (d/l)*2;//正常碰撞几次
    //int res = ((d+x)/l)*2;
    //cout<<res<<endl;
    int yu = d%l;//剩下来多少距离
    if(yu>=cha) res++;
    if(yu>=l-(dd-cha)) res++;//新加的
    cout<<res<<endl;
}

int main(){
    //freopen("E_in.txt","r",stdin);
    //freopen("E_out.txt","w",stdout);
    int z;
    cin>>z;
    while(z--) solve();
}