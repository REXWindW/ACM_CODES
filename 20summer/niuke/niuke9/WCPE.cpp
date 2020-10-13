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
const int inv2=499122177;
const int N=400007;

ll a,b,c,d,x,y;

ll qpow(ll a,ll p,ll m){
    ll ret=1;
    while(p){
        if(p&1)ret=(ret*a)%m;
        a=(a*a)%m;
        p>>=1;
    }
    return ret;
}

int main(){
	cout<<mod<<endl; 
    ios::sync_with_stdio(false);
    cin>>a>>b>>c>>d>>x>>y;
    int sx=sqrt(x),sy=sqrt(y);
    map<int,int> Mx,My;
    for(int i=2;i<=sx;++i){
        int cnt=0;
        while(x%i==0){
            x/=i;
            cnt++;
        }
        if(cnt)Mx[i]=cnt;
    }
    if(x)Mx[x]=1;
    for(int i=2;i<=sy;++i){
        int cnt=0;
        while(y%i==0){
            y/=i;
            cnt++;
        }
        if(cnt)My[i]=cnt;
    }
    if(y)My[y]=1;
    ll ans=1;
    for(map<int,int>::iterator it=Mx.begin();it!=Mx.end();++it){
        ll p=it->first;
        ll m=Mx[p],n=My[p];
        //cout<<p<<' '<<m<<' '<<n<<endl;
        if(n==0 || m==0)continue;
        ll cnt=0;
        /*for(int i=a;i<=b;++i){
            for(int j=c;j<=d;++j){
                cnt=(cnt+min(i*m,j*n))%mod;
            }
        }*/

        for(ll i=a;i<=b;++i){
            ll div=ll(i*m/n);
            if(div<c)cnt=(cnt+(((d-c+1)*i)%mod)*m)%mod;
            else if(div>=c && div<=d)cnt=(cnt+(((((d-div)*i)%mod)*m)%mod)+((((((c+div)*(div-c+1))%mod)*inv2)%mod)*n)%mod)%mod;
            else cnt=(cnt+(((((c+d)*(d-c+1)%mod)*inv2)%mod)*n)%mod)%mod;
        }
        ans=(ans*qpow(p,cnt,mod))%mod;
    }
    cout<<ans<<endl;
    return 0;
}

