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

int a,b,c,d,k;
int x,y;//x可以用c节课，y可以用d节课
void solve(){
    cin>>a>>b>>c>>d>>k;
    int xx = (a+c-1)/c;
    int yy = (b+d-1)/d;
    if(xx+yy<=k){
        cout<<xx<<' '<<k-xx<<endl;
    }
    else cout<<-1<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}