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
int n;
char a[114514*2];
int res;
void solve(){
    res = 0;
    cin>>n;
    rep(i,1,n)
        cin>>a[i];
    bool gr=0;
    int cnt = 0;
    a[n+1]='b';
    n++;
    rep(i,1,n){
        if(a[i]=='b'){
            if(gr==1){
                res+=cnt;
            }
            gr = 0;
            cnt = 0;
            continue;
        }
        else if(a[i]=='a'){
            gr = 1;
        }
        cnt++;
    }

    cout<<res<<endl;
}

int main(){
    solve();
}