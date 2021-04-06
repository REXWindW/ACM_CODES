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
char hc;
int n;
const int MAXN = 2*114514;
int a[MAXN],b[MAXN],s[MAXN];
int nowa,nowb;
int c[3];
void solve(){
    c[0]=c[1]=0;
    cin>>n;
    rep(i,1,n){
        a[i]=b[i]=0;
        cin>>hc;
        s[i] = hc-'0';
        c[s[i]]++;
    }
    //首先保证1的数量和0的数量都为偶数
    if(s[1]=='0'||c[0]%2||c[1]%2){
        cout<<"NO"<<endl;
        return;
    }
    //一半的1给（一半的给）
    int cnt = 1;
    rep(i,1,n){
        if(s[i]==1){
            if(cnt*2<=c[1]) a[i]=b[i]=1;
            else a[i]=b[i]=-1;
            cnt++;
        }
    }
    bool flag = 1;
    nowa=nowb=0;
    rep(i,1,n){
        if(s[i]==0){
            if(nowa<nowb){
                a[i]=1;
                b[i]=-1;
            }
            else{
                a[i]=-1;
                b[i]=1;
            }
        }
        nowa+=a[i];
        nowb+=b[i];
        //cout<<"check"<<i<<':'<<nowa<<' '<<nowb<<endl;
        //检查是否合法
        if(nowa<0||nowb<0){
            flag = 0;break;
        }
    }
    if(!flag){
        cout<<"NO"<<endl;
        return;
    }
    else{
        cout<<"YES"<<endl;
        rep(i,1,n){
            if(a[i]==-1) cout<<')';
            else cout<<'(';
        }
        cout<<endl;
        rep(i,1,n){
            if(b[i]==-1) cout<<')';
            else cout<<'(';
        }
        cout<<endl;
    }
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}