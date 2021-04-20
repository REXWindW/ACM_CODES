#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 3*114514;
int a[3][MAXN];
int c[3][3];//数0和1的数量
int n;
vector<int> duo0,duo1,res;
inline void solve(){
    duo0.clear(),duo1.clear();
    cin>>n;
    char hc;
    rep(i,1,3){
        c[i][0]=c[i][1] = 0;
        rep(j,1,2*n){
            cin>>hc;
            a[i][j] = hc-'0';
            c[i][hc-'0']++;
        }
        if(c[i][1]>=c[i][0]) duo1.push_back(i);//0多的串
        else duo0.push_back(i);//1多的串
    }
    //开始正式处理
    int c2,c1,maxx;
    if(duo1.size()>duo0.size()){//1多的情况,两串同步1
        int px1 = 1,px2 = 1;
        int i1 = duo1[0],i2 = duo1[1];
        while(px1<=2*n||px2<=2*n){
            c1=0;
            while(a[i1][px1]==0&&px1<=2*n){
                px1++;
                c1++;
            }
            while(a[i2][px2]==0&&px2<=2*n){
                px2++;
                c2++;
            }
            maxx = max(c1,c2);
            rep(i,1,maxx) cout<<0;

        }
    }
    else{
        
    }
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}