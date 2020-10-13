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
const int mod=998244353;
const int N=400007;

int t,n,m;
ll w[10007],g1[107][107],g2[107][107],m1[107][107],m2[107][107],x[10007],y[10007];

ll qpow(ll a,ll p,ll m){
    ll ret=1;
    while(p){
        if(p&1)ret=(ret*a)%m;
        a=(a*a)%m;
        p>>=1;
    }
    return ret;
}

ll exgcd(ll a,ll b,ll& x,ll& y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }else{
        ll r=exgcd(b,a%b,y,x);
        y-=x*(a/b);
        return r;
    }
}

ll inv(ll num){
    ll x,y;
    exgcd(num,mod,x,y);
    x=(x%mod+mod)%mod;
    return x;
}

ll getRet(ll a[][107]){
    ll ret=1;
    for(int i=1;i<n;i++){
        if(a[i][i]<0){
            ret=(mod-ret)%mod;
            for(int k=i;k<n;k++){
                a[i][k]=(mod-a[i][k])%mod;
            }
        }
        for(int j=i+1;j<n;j++){
            for(int k=i;k<n;k++){
                a[i][k]%=mod;
                a[j][k]%=mod;
            }
            while(a[j][i]){
                if(a[j][i]<0){
                    ret=(mod-ret)%mod;
                    for(int k=i;k<n;k++){
                        a[j][k]=(mod-a[j][k])%mod;
                    }
                }
                ll t=a[i][i]/a[j][i];
                for(int k=i;k<n;k++){
                    a[i][k]=(mod-(a[i][k]-(t*a[j][k])%mod)%mod)%mod;
                }
                for(int k=i;k<n;k++){
                    swap(a[i][k],a[j][k]);
                }
                ret=(mod-ret)%mod;
            }
        }
        if(a[i][i]==0)return 0;
        ret=(ret*a[i][i])%mod;
    }
    return (ret+mod)%mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=m;++i){
            cin>>x[i]>>y[i]>>w[i];
        }
        ll ans=0;
        memset(g1,0,sizeof(g1));
        memset(m1,0,sizeof(m1));
        for(int i=1;i<=m;++i){
            g1[x[i]][y[i]]++;
            g1[y[i]][x[i]]++;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(g1[i][j]){
                    m1[i][i]++;
                    m1[i][j]=(mod-g1[i][j])%mod;
                }
            }
        }
        /*for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                cout<<m1[i][j]<<' ';
            }
            cout<<endl;
        }*/
        ll ret1=getRet(m1);
        //cout<<ret1<<endl;
        for(int i=0;i<=32;++i){
            memset(g2,0,sizeof(g2));
            memset(m2,0,sizeof(m2));
            for(int j=1;j<=m;++j){
                if((w[j]>>i)&1){
                    g2[x[j]][y[j]]++;
                    g2[y[j]][x[j]]++;
                }
            }
            for(int j=1;j<=n;++j){
                for(int k=1;k<=n;++k){
                    if(g2[j][k]){
                        m2[j][j]++;
                        m2[j][k]=(mod-g2[j][k])%mod;
                    }
                }
            }
            ll ret2=getRet(m2);
            ans=(ans+((ret2*inv(ret1))%mod)*qpow(2,i,mod))%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}

