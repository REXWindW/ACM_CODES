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
const int MAXN = 1234;
int e[MAXN][MAXN];
int n,m;
string s;

void solve(){
    cin>>n>>m;
    rep(i,1,n){
        cin>>s;
        rep(j,1,n){
            if(s[j-1]=='a') e[i][j]=0;
            else if(s[j-1]=='b') e[i][j]=1;
        }
    }
    if(m%2){
        cout<<"YES"<<endl;
        rep(i,1,m+1){
            if(i%2) cout<<1<<' ';
            else cout<<2<<' ';
        }
        cout<<endl;return;
    }
    if(n==2){
        if(e[1][2]!=e[2][1]) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            rep(i,1,m+1){
                if(i%2) cout<<1<<' ';
                else cout<<2<<' ';
            }
            cout<<endl;
        }
        return;
    }
    cout<<"YES"<<endl;
    int st,md;
    if(e[1][2]==e[2][3]) md = 1;
    else if(e[2][3]==e[3][1]) md = 2;
    else if(e[3][1]==e[1][2]) md = 3;
    int bef = m/2-1;//前面的部分
    st = (md-(bef%3)+5)%3+1;
    rep(i,0,m){
        cout<<(st+i-1+3)%3+1<<' ';
    }
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}