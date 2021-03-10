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
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }

const int MAXN = 114514;
int n;
int a[MAXN];
int b[MAXN];//记录b为山顶的下坡长度，为1则不是山顶
int c[MAXN];//上坡长度

void solve(){
    cin>>n;
    rep(i,1,n){
        cin>>a[i];
        b[i]=c[i]=1;
    }
    if(n==3){//n=3特殊情况
        //if(a[1]<a[2]&&a[2]>a[3]) cout<<0<<endl;
        //else if(a[1]>a[2]&&a[2]<a[3]) cout<<0<<endl;
        //else cout<<1<<endl;
        cout<<0<<endl;
        return;
    }
    int maxx = 0;
    rep(i,1,n-1){//下降
        int px = i+1;
        while(px<=n&&a[px-1]>a[px]) px++;
        b[i] = px-i;//记录为山顶
        maxx = max(b[i],maxx);//维护最长
        i = px-1;
    }
    rep(i,1,n-1){//上升
        int px = i+1;
        while(px<=n&&a[px-1]<a[px]) px++;
        c[px-1] = px-i;
        maxx = max(c[px-1],maxx);//维护最长
        i = px-1;
    }  
    /*
    cout<<"check down"<<endl;
    rep(i,1,n) cout<<b[i]<<' ';
    cout<<endl;
    cout<<"check up"<<endl;
    rep(i,1,n) cout<<c[i]<<' ';
    cout<<endl;
    */
    if(maxx==1||maxx==0||maxx%2==0){cout<<0<<endl;return;}//应该不会有这种情况
    int cnt = 0;
    rep(i,1,n){
        if(b[i]==maxx||c[i]==maxx) cnt++;
    }
    int res = 0;
    rep(i,1,n){
        if(b[i]==maxx&&c[i]==maxx&&cnt==1){res++;}//最容易理解的情况
    }
    cout<<res<<endl;
}

int main(){
    solve();
}