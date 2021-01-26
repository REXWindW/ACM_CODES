#include<iostream>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f

const int MAXN = 114514*2;
int a[MAXN];
int dp[MAXN];//存最大长度
map<int,int> mp;//从数字到下标的映射
int n;


void solve(){
    mp.clear();
    cin>>n;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);//小的排在前面
    dp[0]=0;
    int res=0;
    rep(i,1,n){
        dp[i] = 0;
        int sqr = sqrt(a[i]);
        rep(k,1,sqr){//细节是1和a[i]也需要去map找,因为可能有重复数字
            if(a[i]%k==0){
                dp[i]=max(dp[i],dp[mp[k]]+1);//dp[i]要取最大值！
                dp[i]=max(dp[i],dp[mp[a[i]/k]]+1);
            }
        }
        mp[a[i]]=i;//更新map
        res = max(res,dp[i]);
    }
    cout<<n-res<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}