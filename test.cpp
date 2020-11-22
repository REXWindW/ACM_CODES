#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define mkp make_pair
#define ft first
#define sd second
#define log(x) (31-__builtin_clz(x))
#define INF 0x3f3f3f3f
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff
const int med = 998244353;
ll tot[4];
bool fr[4],fr2[4];
bool bk[4],bk2[4];
int n,a,b;
string sa,sb;
void solve(){
  cin>>n>>a>>b;
  cin>>sa>>sb;
  rep(i,1,3){
    fr[i] = bk[i] = bk2[i] = fr2[i] = 0;
    tot[i] = 0;
  }
  rep(i,2,a-1){
    if(sa[i-2]=='1'&&sa[i-1]=='1'&&sa[i]=='1') tot[1]++;
  }
  rep(i,2,b-1){
    if(sb[i-2]=='1'&&sb[i-1]=='1'&&sb[i]=='1') tot[2]++;
  }
  if(sa[0]=='1') fr[1] = 1;
  if(fr[1]&&sa[1]=='1') fr2[1] = 1;
  if(sb[0]=='1') fr[2] = 1;
  if(fr[2]&&sb[1]=='1') fr2[2] = 1;
  if(sa[a-1]=='1') bk[1] = 1;
  if(bk[1]&&sa[a-2]=='1') bk2[1] = 1;
  if(sb[b-1]=='1') bk[2] = 1;
  if(bk[2]&&sb[b-2]=='1') bk2[2] = 1;
  rep(i,3,n){
    fr[3] = fr[1];
    bk[3] = bk[2];
    fr2[3] = fr2[1];
    bk2[3] = bk2[2];
    if(i==3){
      if(a==1&&fr[1]&&fr[2]){
        fr2[3] = 1;
      }
      if(b==1&&bk[1]&&bk[2]){
        bk2[3] = 1;
      }
    }
    else if(i==4){
      if(b==1&&fr[1]&&fr[2]){
        fr2[3] = 1;
      }
    }
    //tepan
    tot[3] = tot[2]+tot[1];
    //cout<<"tmpchk"<<tot[3]<<endl;
    if(bk2[1]&&fr2[2]) tot[3]+=2;
    else if( (bk2[1]&&fr[2]) || (bk[1]&&fr2[2]) ) tot[3]+=1;
    tot[3]%=med;

    //cout<<"check"<<i<<':'<<endl;
    //cout<<tot[3]<<' '<<fr2[3]<<' '<<bk2[3]<<endl;//debug

    tot[1] = tot[2];
    fr[1]=fr[2],fr2[1]=fr2[2];
    bk[1]=bk[2],bk2[1]=bk2[2];

    tot[2] = tot[3];
    fr[2]=fr[3],fr2[2]=fr2[3];
    bk[2]=bk[3],bk2[2]=bk2[3];
  }
  cout<<tot[2]<<endl;
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}