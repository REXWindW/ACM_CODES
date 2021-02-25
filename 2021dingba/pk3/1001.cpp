#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll g,l;
ll a,b;
void solve(){
    cin>>g>>l;
    //a和b是g的倍数！g>=l肯定
    //a/g x b/g = g*l/g/g = l/g!
    ll tmp = l/g;
    repb(i,sqrt(tmp),1){
        if(tmp%i==0){
            a = i;break;
        }
    }
    b = tmp/a;
    cout<<(a+b)*g<<' '<<(1+tmp)*g<<endl;

}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}