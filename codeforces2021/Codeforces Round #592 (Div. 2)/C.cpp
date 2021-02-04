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
void Exgcd(ll a,ll b,ll &d,ll &x,ll &y){//不同的是，这里的d使用引用来实现 
	if(!b){d=a;x=1;y=0;}
	else{Exgcd(b,a%b,d,y,x);y-=x*(a/b);}//先交换了xy的位置，实现y1=x2-(a/b)*x2 
} 

ll n,p,w,d;
void solve(){
    cin>>n>>p>>w>>d;
    ll ttx = p/w;
    ll ys = p%w;
    ll tty = ys/d;
    ys=ys%d;
    ll gcdd,xx,yy;
    Exgcd(w,d,gcdd,xx,yy);
    ll bs = ys/gcdd;
    if(ys%gcdd!=0){
        cout<<-1<<endl;
        return;
    }
    //cout<<bs<<endl;
    ll tx = bs*xx+ttx;
    ll ty = bs*yy+tty;
    //cout<<"ttxtty-ys"<<ttx<<' '<<tty<<' '<<ys<<endl;
    //cout<<"xxyy"<<xx<<' '<<yy<<endl;
    //cout<<"txty"<<tx<<' '<<ty<<endl;
    //cout<<"bs*w/gcdd"<<bs*w/gcdd<<endl;
    //cout<<"gcdd"<<gcdd<<endl;
    while(tx<0){
        ty-=w/gcdd;tx+=d/gcdd;
    }
    while(ty<0){
        ty+=w/gcdd;tx-=d/gcdd;
    }
    //cout<<"txty"<<tx<<' '<<ty<<endl;
    if(tx+ty<=n&&tx>=0&&ty>=0){
        cout<<tx<<' '<<ty<<' '<<n-tx-ty<<endl;
    }
    else cout<<-1<<endl;
}

int main(){
    solve();
}