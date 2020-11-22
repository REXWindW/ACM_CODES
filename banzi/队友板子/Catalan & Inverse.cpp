#include<iostream>
#include<algorithm>

typedef long long ll;

using namespace std;

const ll m=1000000007;

ll exgcd(ll a,ll b,ll& x,ll& y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }else{
        ll r=exgcd(b,a%b,y,x);
        y-=x*(a/b);
        return r;
    }
}

ll inv(ll num,ll m){
    ll x,y;
    exgcd(num,m,x,y);
    x=(x%m+m)%m;
    return x;
}

int main(){
    ll n,ans=1;
    cin>>n;
    for(int i=2;i<=n;++i)ans=((ans*(4*i-2)%m)*inv(i+1))%m;
    cout<<ans<<endl;
    return 0;
}