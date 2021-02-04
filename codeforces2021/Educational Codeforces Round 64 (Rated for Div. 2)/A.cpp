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
const int MAXN = 2e6+5;
int a[MAXN];
int b[4][4];
void solve(){
    b[1][2] = 3;
    b[1][3] = 4;
    b[2][1] = 3;
    b[2][3] = INF;
    b[3][1] = 4;
    b[3][2] = INF;
    int n;
    cin>>n;
    cin>>a[1];
    a[0] = -1;
    int res = 0;
    bool flag = 0;
    rep(i,2,n){
        cin>>a[i];
        if(a[i]==2&&a[i-1]==1&&a[i-2]==3) res+=2;
        else res+=b[a[i-1]][a[i]];
        if(res>=INF){
            flag = 1;
        }
    }
    if(flag) cout<<"Infinite"<<endl;
    else cout<<"Finite"<<endl<<res<<endl;
}

int main(){
    solve();
}