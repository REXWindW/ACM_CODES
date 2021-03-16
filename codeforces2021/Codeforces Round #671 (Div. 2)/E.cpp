#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
int n;
int siz;
vector<int> yz;
vector<int> cntyz;//数有几个
inline ll qpow(int d,int m){//快速幂
    ll ret = 1;
    while(m){
        if(m%2) ret*=d;
        m/=2;
        d = d*d;
    }
    return ret;
}
void getyz(int n){
    int sqr = sqrt(n);
    int tmp;
    rep(i,2,sqr){
        if(n%i==0){
            tmp = 0;
            while(n%i==0){
                n/=i;
                tmp++;
            }
            yz.push_back(i);
            cntyz.push_back(tmp);//记录次数
        }
    }
    if(n!=1) yz.push_back(n),cntyz.push_back(1);
}
map<int,bool> mp;
const int MAXN = 114514*2;
vector<int> res[MAXN];//夹在中间的

void dfs(int now,int z,int fyz){//fyz是第一个因子
    if(now==siz){//结束
        if(fyz==-1) return;
        if(mp[z]) return;//如果数字已经出现过
        mp[z] = 1;//标记数字出现
        res[fyz].push_back(z);
        return;
    }
    int tmp = 1;
    rep(i,0,cntyz[now]){//枚举当前因子放几个
        if(i&&fyz==-1) dfs(now+1,z*tmp,now);
        else dfs(now+1,z*tmp,fyz);
        tmp*=yz[now];
    }
}

void solve(){
    mp.clear();
    cin>>n;
    yz.clear();
    cntyz.clear();
    getyz(n);
    siz = yz.size();
    /*
    cout<<siz<<endl;
    rep(i,0,siz-1) cout<<yz[i]<<' ';
    cout<<endl;
    */
    rep(i,0,siz-1){//先把这些关键节点标记了
        res[i].clear();//清空vector
        mp[yz[i]]=1;mp[yz[(i+1)%siz]]=1;
        mp[yz[i]*yz[(i+1)%siz]]=1;
    }
    dfs(0,1,-1);
    int sizv;
    if(siz==2){//特殊情况
        if(cntyz[0]==1&&cntyz[1]==1){//有一个是质数
            cout<<yz[0]<<' ';
            cout<<yz[0]*yz[1]<<' '<<yz[1]<<' '<<endl;
            cout<<1<<endl;
        }
        else{
            cout<<yz[0]<<' ';
            //1 12 2 n另一边用n来连接
            sizv = res[0].size();
            rep(j,0,sizv-1) if(res[0][j]!=n) cout<<res[0][j]<<' ';
            cout<<n<<' '<<yz[1]<<' ';
            sizv = res[1].size();
            rep(j,0,sizv-1) if(res[1][j]!=n) cout<<res[1][j]<<' ';
            cout<<yz[0]*yz[1]<<' '<<endl;
            cout<<0<<endl;
        }   
        return;
    }
    rep(i,0,siz-1){
        cout<<yz[i]<<' ';
        if(siz==2&&i==1) continue;//这里会重复1 12 2 21重复
        //中间输出所有含有yz[1]且未出现的
        sizv = res[i].size();
        rep(j,0,sizv-1){
            cout<<res[i][j]<<' ';
        }
        cout<<yz[i]*yz[(i+1)%siz]<<' ';
    }
    cout<<endl;
    cout<<0<<endl;
}
int main(){
    int z;
    cin>>z;
    while(z--) solve();
}