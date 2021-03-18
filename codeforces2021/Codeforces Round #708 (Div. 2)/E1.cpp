#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int n,k;
const int MAXN = 114514*2;
//显然是一个贪心
//只需要记录奇数因子的位数,
//如果奇数因子完全相同，则必须隔开
int a[MAXN];
vector<int> prim;
int ntprim[10001];//只需要判断小于sqrt的质数即可
//用字典树！！！
int trie[10005][500];//字典树
int vis[10005][500];//如果是now的话表示有路
int visz[10005][500];
map<int,int> mp[10005];
map<int,int> mpz[10005];
int tot;
int cnt;
int res,zz;
void insert(int x){
    int now = 0;
    rep(i,0,cnt-1){
        int tmp = 0;
        while(x%prim[i]==0){
            x/=prim[i];
            tmp++;
        }
        if(tmp%2){//发现奇数
            if(vis[now][i]!=res||visz[now][i]!=zz){
                trie[now][i] = ++tot;
                vis[now][i]=res;visz[now][i]=zz;
            }
            now = trie[now][i];
        }
    }
    mp[now][x] = res;mpz[now][x] = zz;
}
bool find(int x){
    int now = 0;
    rep(i,0,cnt-1){
        int tmp = 0;
        while(x%prim[i]==0){
            x/=prim[i];
            tmp++;
        }
        if(tmp%2){//发现奇数
            if(vis[now][i]!=res||visz[now][i]!=zz){
                return 0;
            }
            now = trie[now][i];
        }
    }
    if(mp[now][x]==res&&mpz[now][x]==zz) return 1;
    return 0;
}
void init(){//筛出质因数
    int sqr = sqrt(1e7); 
    rep(i,2,sqr){
        if(ntprim[i]) continue;
        for(int j=i;j<=sqr;j+=i){
            ntprim[j] = 1;
        }
        prim.push_back(i);
    }
    cnt = prim.size();
    /*
    cout<<prim.size()<<endl;
    int tmp = 1;
    rep(i,0,7){
        tmp*=prim[i];
        cout<<tmp<<' ';
    }
    cout<<endl;
    */
    //最多只有8个质数相乘得到！
}

void solve(){
    res = 1;
    cin>>n>>k;
    rep(i,1,n) cin>>a[i];
    rep(i,1,n){
        if(find(a[i])){
            //cout<<"chongtu in"<<i<<endl;
            res++;
            tot = 0;//清空一下
        }
        insert(a[i]);
    }
    cout<<res<<endl;
}

int main(){
    init();
    int z;
    cin>>z;
    for(zz=1;zz<=z;zz++) solve();
}