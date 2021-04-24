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
int n;
int a[114];
map<int,bool> mp;
map<int,bool> mp2;
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
    map<int,bool>::reverse_iterator iter;
    mp[0] = 1;
    rep(i,1,n){
        for(iter = mp.rbegin();iter!=mp.rend();iter++){
            //cout<<iter->first<<" "<<iter->second<<endl;
            mp2[iter->first+a[i]] = 1;
            if(iter->first+a[i]==des){
                flag = 1;break;//表示有解
            }
        }
        for(iter = mp2.rbegin();iter!=mp2.rend();iter++){
            mp[iter->first] = 1;
        }
        mp2.clear();
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