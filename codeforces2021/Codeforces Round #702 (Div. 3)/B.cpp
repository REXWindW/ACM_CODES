#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INconst int  0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int n;
int c[5];
void solve(){
    c[0]=c[1]=c[2] = 0;
    cin>>n;
    int tmp;
    rep(i,1,n){
        cin>>tmp;
        c[tmp%3]++;
    }
    int res = 0;
    int avg = n/3;
    rep(pt,1,2){
        rep(i,0,2){
            if(c[i]<avg){
                int cha = avg-c[i];
                res+=cha;
                c[i] = avg;
                c[(i+2)%3]-=cha;
            }
        }
    }
    cout<<res<<endl;
    return;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}