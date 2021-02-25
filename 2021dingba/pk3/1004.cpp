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
const int MAXN = 2*114514;
const ll med = 998244353;
ll res=0;
int a[MAXN];
void dfs(int pos,ll now,ll tmp){
    if(pos==n){
        res+=tmp*now%med;
        res%=med;
        return;
    }
    //下个作为新数字
    dfs(pos+1,now*tmp%med,a[pos+1]%med);
    //下个并入当前tmp
    dfs(pos+1,now,(tmp*10+a[pos+1])%med);
}
void solve(){
    cin>>n;
    char hc;
    rep(i,1,n){
        cin>>hc;
        a[i]=hc-'0';
    }
    dfs(0,1,0);
    cout<<res<<endl;
}

int main(){
    solve();
}