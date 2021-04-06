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
int n;
typedef pair<int,int> pii;
#define mkp make_pair
#define ft first
#define sd second
const int MAXN = 114514;
pii ac[MAXN];
ll res;
void solve(){
    res = 0;
    cin>>n;
    rep(i,1,n) cin>>ac[i].ft>>ac[i].sd,res+=ac[i].sd;
    sort(ac+1,ac+1+n);
    int now = ac[1].ft+ac[1].sd;//now是当前房子+梯子的高度
    //之后每步的消耗看作max(0,aj-(ai+ci))
    rep(i,2,n){
        if(ac[i].ft>=now)//通过梯子上去的情况
            res += ac[i].ft-now;
        //不加的这些是达到最高之后访问的
        //如果这个楼可以使now更高，也应该在中间免费经过
        now = max(now,ac[i].ft+ac[i].sd);
    }
    //第二部分经过的楼全部免费
    cout<<res<<endl;
}

int main(){
    solve();
}