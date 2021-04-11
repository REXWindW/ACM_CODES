#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int n;
const int MAXN = 114514;
int nowp,maxp;
int a[MAXN];
void solve(){
    cin>>n;
    if(n==1){
        cout.flush();
        cout<<"! 1"<<endl;return;
    }
    int x,y;
    maxp = 1;
    rep(i,2,n){
        cout.flush();
        cout<<"? "<<i<<' '<<maxp<<endl;
        cin>>x;
        cout.flush();
        cout<<"? "<<maxp<<' '<<i<<endl;
        cin>>y;
        if(x>y){
            //maxp不变
            a[i] = x;
        }
        else{
            a[maxp] = y;
            maxp = i;
        }
    }
    a[maxp] = n;
    cout.flush();
    cout<<"! ";
    rep(i,1,n){
        cout<<a[i];
        if(i!=n) cout<<' ';
    }
    cout<<endl;
}

int main(){
    solve();
}