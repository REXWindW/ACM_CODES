#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 114514*10;
//5 4 4
//5/2*2
int n;
int a[MAXN];
int cnt[MAXN];
int maxx;
int res[MAXN];
int vis[MAXN];
void solve(){
    int tmp,now;
    rep(i,1,n){
        tmp = a[i];
        //看小的
        now = 0;
        while(tmp){
            res[tmp]+=now;
            vis[tmp]++;//表示这个数可以到达
            tmp>>=1;
            now++;
        }
        tmp = a[i];
        now = 1;
        tmp<<=1;
        while(tmp<=maxx){
            res[tmp]+=now;
            vis[tmp]++;
            tmp<<=1;
            now++;
        }
    }
    int ress = INF;
    rep(i,1,maxx){
        //cout<<"res"<<i<<':'<<res[i]<<"vis"<<vis[i]<<endl;
        if(vis[i]==n)ress = min(ress,res[i]);
    }
    cout<<ress<<endl;
}
void solve1(){
    int ress=INF,cnt,tmp;
    rep(i,1,maxx){
        int to = i;//奇数偶数共有的中位数
        cnt = 0;
        rep(i,1,n){
            tmp = a[i];
            while(tmp>to){
                tmp>>=1;
                cnt++;
            }
            while(tmp<to){
                tmp<<=1;
                cnt++;
            }
            if(tmp!=to){
                cnt = INF;break;
            }
        }
        ress = min(ress,cnt);
    }
    cout<<ress<<endl;
}
int main(){
    cin>>n;
    maxx = 0;
    rep(i,1,n) cin>>a[i],maxx = max(maxx,a[i]);
    if(n<=1e3&&maxx<=1e3) solve1();
    else solve();
}