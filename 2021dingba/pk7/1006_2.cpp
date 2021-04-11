#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
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
int res[MAXN];
set<int> vis[MAXN];
void solve(){
    cin>>n;
    int maxx = 0;
    rep(i,1,n) cin>>a[i],maxx = max(maxx,a[i]);
    int tmp,now;
    rep(i,1,n){
        tmp = a[i];
        //看小的
        now = 0;
        int pre=-1;
        while(tmp){
            res[tmp]+=now;
            int tmpp = tmp*2;
            int nnow = now+1;
            vis[tmp].insert(i);
            if(pre!=tmp*2){//有损失的情况才要搞
                while(tmpp<=maxx){
                    vis[tmpp].insert(i);
                    res[tmpp]+=nnow;
                    tmpp<<=1;
                    nnow++;
                }
            }
            pre = tmp;
            tmp>>=1;
            now++;
        }
    }
    int ress = INF;
    rep(i,1,maxx){
        //cout<<"res"<<i<<':'<<res[i]<<"vis"<<vis[i]<<endl;
        if((int)vis[i].size()==n)ress = min(ress,res[i]);
    }
    cout<<ress<<endl;
}

int main(){
    solve();
}