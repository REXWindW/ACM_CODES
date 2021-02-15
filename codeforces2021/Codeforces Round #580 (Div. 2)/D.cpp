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

const int MAXN = 114514;
ll a[MAXN];
int e[666][666],mp[666][666];
int n;
vector<ll> vec;
void solve(){
    cin>>n;
    rep(i,1,n) cin>>a[i];
    ll tmp;
    rep(i,0,63){
        tmp = 1ll<<i;
        int cnt = 0;
        rep(i,1,n)
            if(a[i]&tmp) cnt++;
        if(cnt>=3){
            cout<<3<<endl;
            return;
        }
    }
    vec.push_back(-1);//填个空
    rep(i,1,n)
        if(a[i]!=0) vec.push_back(a[i]);//防止0的情况
    n = vec.size()-1;
    //最多2*64个数，floyd找最小环
    int minn = INF;
    rep(i,1,n){
        rep(j,1,n){
            e[i][j] = INF/3;//INF的话会越界
            if(i==j) e[i][j]=0;
            else if(vec[i]&vec[j]) e[i][j]=1;
        }
    }
    //floyd
    rep(i,1,n)
        rep(j,1,n)
            mp[i][j]=e[i][j];//把一开始的e复制一遍给mp
    rep(k,1,n){
        //当循环到k的时候,可以保证之前的e[i][j]路径中都不会包含k
        rep(i,1,k-1){
            rep(j,i+1,k-1){
                minn = min(minn,e[i][j]+mp[i][k]+mp[j][k]);//i->j->k->i这个环长度
                //这句后面两个一定要是mp！一开始错在这里
                //想明白了是因为圈上会有边被经过两次,类似丫字型,原本不能成环,但如果不是mp会被误判成环
            }
        }
        rep(i,1,n){
            rep(j,1,n){
                e[i][j]=min(e[i][j],e[i][k]+e[k][j]);//这样处理之后,路径可以包含k
            }
        }
    }
    if(minn>n) cout<<-1<<endl;
    else cout<<minn<<endl;
}

int main(){
    solve();
}