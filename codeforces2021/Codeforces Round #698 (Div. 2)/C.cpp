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
const int MAXN = 114514*2;
ll d[MAXN];
int n;
void solve(){
    cin>>n;
    rep(i,1,2*n){
        cin>>d[i];
    }
    d[0]=-1;
    sort(d+1,d+1+2*n,greater<ll>());
    bool flag = 1;
    rep(i,1,n){
        if(d[2*i]!=d[2*i-1]){//防止出现两次
            flag = 0;break;
        }
        else if(d[2*i]==d[2*i-2]){//防止出现四次
            flag = 0;break;
        }
    }
    ll maxd,now = 0;
    ll div;
    rep(i,1,n){
        div = 2*(n-i+1);
        maxd = d[2*i]-now;
        //cout<<"maxd"<<i<<"=="<<maxd<<endl;
        if(maxd%div!=0||maxd<=0){
            flag=0;break;
        }
        //cout<<"a"<<i<<"=="<<maxd/div<<endl;
        now += 2*(maxd/div);
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}