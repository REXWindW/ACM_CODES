#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
queue<int> q[2];//只要检查一开始的序列行不行就ok了
int n;
int a[114];
int mp1[214514];
int mp2[214514];
inline void solve(){
    cin>>n;
    cin>>a[1];
    int gcdd = a[1];
    rep(i,2,n){
        cin>>a[i];
        gcdd = gcd(a[i],gcdd);
    }
    ll summ=0;
    rep(i,1,n){
        a[i]/=gcdd;//这样一来肯定有一个奇数！
        summ+=a[i];
    }
    if(summ%2){//和一定为偶数
        cout<<0<<endl;
        return;
    }
    int des = summ/2; 
    //判断不用删去的情况
    bool flag = 0;
    mp1[0] = 1;
    int maxx = 0;
    int maxx2 = 0;
    rep(i,1,n){
        rep(j,0,maxx){
            //cout<<i<<','<<j<<endl;
            if(mp1[j]){
                mp2[j+a[i]] = 1;
                maxx2 = max(j+a[i],maxx);
                //cout<<"maxx"<<maxx<<endl;
                if(j+a[i]==des){
                    //cout<<"find"<<i<<endl;
                    flag = 1;break;
                }
            }
            rep(j,0,maxx2){
                if(mp2[j]) mp1[j] = 1;
            }
            maxx = maxx2;
        }
    }
    if(!flag){cout<<"0"<<endl;return;}
    rep(i,1,n){
        if(a[i]%2){
            cout<<1<<endl<<i<<endl;
            return;
        }
    }
}

int main(){
    solve();
}