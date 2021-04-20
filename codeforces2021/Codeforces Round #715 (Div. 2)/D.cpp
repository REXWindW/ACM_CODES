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
int a[10][MAXN];
int c[10][10];//数0和1的数量
int n;
vector<int> duo0,duo1;
inline void solve(){
    duo0.clear(),duo1.clear();
    cin>>n;
    char hc;
    int nn = n*2;
    rep(i,1,3){
        c[i][0]=c[i][1] = 0;
        rep(j,1,nn){
            cin>>hc;
            a[i][j] = hc-'0';
            c[i][hc-'0']++;
        }
        if(c[i][1]>=c[i][0]) duo1.push_back(i);//0多的串
        else duo0.push_back(i);//1多的串
    }
    //开始正式处理
    if(duo1.size()>duo0.size()){//1多的情况,两串同步1
        //cout<<"tongbu1 "<<duo1[0]<<':'<<duo1[1]<<endl;
        int i1 = duo1[0],i2 = duo1[1];
        int px1=1,px2=1;//第二个指针
        //如果是0直接推入，是的话等另一个串的1
        while(px1<=nn&&px2<=nn){//两个都没输出完的情况
            if(a[i1][px1]==0){
                cout<<0;
                px1++;
                if(a[i2][px2]==0&&px2<=nn) px2++;
            }
            else if(a[i1][px1]==1){
                while(a[i2][px2]==0&&px2<=nn){
                    cout<<0;
                    px2++;
                }
                cout<<1;
                px1++;
                if(a[i2][px2]==1&&px2<=2*n) px2++;
            }
        }
        //把剩余的全部输出掉
        while(px1<=nn) cout<<a[i1][px1],px1++;
        while(px2<=nn) cout<<a[i2][px2],px2++;
    }
    else{
        //cout<<"tongbu1 "<<duo1[0]<<':'<<duo1[1]<<endl;
        int i1 = duo0[0],i2 = duo0[1];
        int px1=1,px2=1;//第二个指针
        //如果是0直接推入，是的话等另一个串的1
        while(px1<=nn&&px2<=nn){//两个都没输出完的情况
            if(a[i1][px1]==1){
                cout<<1;
                px1++;
                if(a[i2][px2]==1&&px2<=nn) px2++;
            }
            else if(a[i1][px1]==0){
                while(a[i2][px2]==1&&px2<=nn){
                    cout<<1;
                    px2++;
                }
                cout<<0;
                px1++;
                if(a[i2][px2]==0&&px2<=2*n) px2++;
            }
        }
        //把剩余的全部输出掉
        while(px1<=nn) cout<<a[i1][px1],px1++;
        while(px2<=nn) cout<<a[i2][px2],px2++;
    }
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}