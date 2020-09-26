#include<bits/stdc++.h>
  
using namespace std;

#define rep(a,b,c) for(int a=(b);a<(c);++a)
#define dep(a,b,c) for(int a=(b);a>=(c);--a)
#define sf scanf
#define pf printf
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int>Pii;
typedef pair<double, double> Pdd;
const int inf=0x3f3f3f3f;
const int mod=998244353;

int t,n;

ll f1[1500007]={1,1},f2[1500007]={1,1},a[1500007],invn[1500007]={0,1},inv1[1500007]={1},inv2[1500007]={1};

int main(){
    //ios::sync_with_stdio(false);
    for(int i=2;i<1500007;++i){
        invn[i]=((ll)(mod-mod/i)*invn[mod%i])%mod;
    }
    inv1[1]=inv2[1]=invn[1];
    inv1[2]=inv2[2]=invn[2];
    for(int i=2;i<1500007;++i){
        f1[i]=(i*f1[i-1])%mod;
        inv1[i]=(invn[i]*inv1[i-1])%mod;
    }
    for(int i=2;i<1500007;++i){
        f2[i]=(i*f2[i-2])%mod;
        inv2[i]=(invn[i]*inv2[i-2])%mod;
    }
    scanf("%d",&t);
    cout<<inv2[8]<<endl;
    while(t--){
        scanf("%d",&n);
        int num=1;
        for(int i=1;i<=n;++i){
            if(i<=n/2){
                a[i]=0;
                continue;
            }else if(i==n/2+1){
                a[i]=((f1[i-1]%mod)*inv1[n-1])%mod;
            }else{
                a[i]=(((((f2[num]*f1[i-1])%mod)*inv1[num+1])%mod)*inv2[n-1])%mod;
                num+=2;
            }
        }
        for(int i=1;i<=n;++i){
            printf("%lld",a[i]);
            if(i<n)printf(" ");else printf("\n");
        }
    }
    return 0;
}
