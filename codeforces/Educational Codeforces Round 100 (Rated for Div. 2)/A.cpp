#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x7fffffff
int n;
const int MAXN = 114514;
int a[MAXN];

void solve(){
    rep(i,1,3) cin>>a[i];
    sort(a+1,a+1+3,greater<int>());
    int d = a[1]-a[3]+a[2]-a[3];//需要多打多少次
    if(d/6>a[3]){
        cout<<"NO"<<endl;
        return;
    }
    a[1]=a[2]=a[3]= a[3]-d/6;
    int rest = d%6;
    if(rest%3!=0){
        cout<<"NO"<<endl;
        return;
    }
    a[1]=a[2]=a[3]= a[3]-rest/3;
    if(rest){
        a[1]=a[2]=a[3]=a[3]-1;
    }
    if(a[3]%3==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}
//这题被教育了