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

const int MAXN = 114514;
int r[MAXN],b[MAXN];
int n;
void solve(){
    cin>>n;
    char hc;
    rep(i,1,n){
        cin>>hc;
        r[i] = hc-'0';
    }
    rep(i,1,n){
        cin>>hc;
        b[i] = hc-'0';
    }
    int cr=0,cb=0;
    rep(i,1,n){
        if(r[i]>b[i]) cr++;
        else if(r[i]<b[i]) cb++;
    }
    if(cr>cb) cout<<"RED"<<endl;
    else if(cr<cb) cout<<"BLUE"<<endl;
    else cout<<"EQUAL"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}