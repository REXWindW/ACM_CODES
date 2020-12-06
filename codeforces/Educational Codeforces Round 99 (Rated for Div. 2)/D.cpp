#include<iostream>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f
const int chou = 114;
const int MAXN = 514;//hen hen aaaaaaaaaaaaa
int a[MAXN],b[MAXN];
int n,x;
int res = INF;
void solve(){
    res = INF;
    cin>>n>>x;
    rep(i,1,n) cin>>a[i];
    rep(i,0,n){
        rep(j,1,n) b[j]=a[j];
        b[i] = x;
        sort(b+1,b+1+n);
        int tmp = x;
        bool flag = 1;
        int cnt = 0;//记录数量
        //开始了;
        rep(i,1,n){
            if(a[i]!=b[i]){
                if(a[i]<=tmp||tmp!=b[i]){
                    flag = 0;break;  
                }
                tmp = a[i];
                cnt++;
            }
        }
        if(flag) res = min(res,cnt);
    }
    if(res==INF) cout<<-1<<endl;
    else cout<<res<<endl;
}
int main(){
    int z;
    cin>>z;
    while(z--) solve();
}