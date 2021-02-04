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
int n,k;
const int MAXN = 114514;
char a[MAXN];
bool OK(char a,char b,char c){
    if(b-a>1&&c-b>1) return 1;
    else return 0;
}
int cal(char a,char b,char c){
    return a-'a'+b-'a'+c-'a'+3;
}
void solve(){
    cin>>n>>k;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    //rep(i,1,n) cout<<a[i];
    //cout<<endl;
    int res = INF;
    rep(i,1,n){
        rep(j,i,n){
            rep(k,j,n){
                if(OK(a[i],a[j],a[k])){
                    res = min(res,cal(a[i],a[j],a[k]));
                }
            }
        }
    }
    if(res!=INF)cout<<res<<endl;
    else cout<<-1<<endl;
}

int main(){
    solve();
}