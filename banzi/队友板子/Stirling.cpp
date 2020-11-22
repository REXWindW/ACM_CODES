#include<bits/stdc++.h>
  
using namespace std;

#define rep(a,b,c) for(int a=(b);a<(c);++a)
#define dep(a,b,c) for(int a=(b);a>=(c);--a)
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int>Pii;
typedef pair<double, double> Pdd;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const int N=400007;

int n,r;
ll f[17][17],fac[17]={1};

int main(){
    ios::sync_with_stdio(false);
    for(int i=1;i<17;++i){
        fac[i]=fac[i-1]*i;
    }
    cin>>n>>r;
    f[0][0]=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=r;++j){
            f[i][j]=f[i-1][j-1]+f[i-1][j]*j;
        }
    }
    /*盒子互不相同时需要乘盒子数的阶乘*/
    cout<<f[n][r]*fac[r]<<endl;
    return 0;
}