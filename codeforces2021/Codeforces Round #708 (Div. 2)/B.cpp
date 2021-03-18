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
int n,m;
const int MAXN = 114514;
int a[MAXN];
int cnt[MAXN];//记录%m=b的数量
void solve(){
    cin>>n>>m;
    rep(i,1,n){
        cin>>a[i];
        a[i]%=m;
        cnt[a[i]]++; 
    }
    int tmp;
    int res=0;
    rep(i,1,n){
        if(cnt[a[i]]){
            if(a[i]==0||a[i]*2==m){//两种特殊情况
                res++;
                cnt[a[i]]=0;//a[i]==0的全部放在一组
                continue;
            }
            else if(cnt[m-a[i]]){
                tmp = min(cnt[a[i]],cnt[m-a[i]]);
                cnt[a[i]]-=tmp;
                cnt[m-a[i]]-=tmp;
                if(cnt[a[i]]) cnt[a[i]]--;
                else if(cnt[m-a[i]]) cnt[m-a[i]]--;
                res++;
            }
            res+=cnt[a[i]];//生下来这些要一个一组了！
            cnt[a[i]]=0;
        }
    }
    cout<<res<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}