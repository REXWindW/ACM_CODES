#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define m(a) memset(a,0,sizeof(a))
//求1到n内的素数个数
const int N = 310000;
ll n, g[N<<1], a[N<<1];
int id, cnt, sn, prime[N];
inline int Id(ll x){return x<=sn?x:id-n/x+1;}
int main(){
	scanf("%lld", &n), sn=sqrt(n);
	for(ll i=1; i<=n; i=a[id]+1) a[++id]=n/(n/i), g[id]=a[id]-1;
	for(int i=2; i<=sn; ++i) if(g[i]!=g[i-1]){
		prime[++cnt]=i;
		ll sq=(ll)i*i;
		for(int j=id; a[j]>=sq; --j) g[j]-=g[Id(a[j]/i)]-(cnt-1);
	}
	return printf("%lld\n", g[id]), 0;
}
/*求1到n内的素数之和
namespace Min25{
    int prime[N], id1[N], id2[N], flag[N], ncnt, m;
    ll g[N], sum[N], a[N], T, n;
    inline int ID(ll x) {
        return x <= T ? id1[x] : id2[n / x];
    }
    inline ll calc(ll x) {
        return x * (x + 1) / 2 - 1;
    }
    inline ll f(ll x) {
        return x;
    }
    inline void init() {
        T = sqrt(n + 0.5);
        for (int i = 2; i <= T; i++) {
            if (!flag[i]) prime[++ncnt] = i, sum[ncnt] = sum[ncnt - 1] + i;
            for (int j = 1; j <= ncnt && i * prime[j] <= T; j++) {
                flag[i * prime[j]] = 1;
                if (i % prime[j] == 0) break;
            }
        }
        for (ll l = 1; l <= n; l = n / (n / l) + 1) {
            a[++m] = n / l;
            if (a[m] <= T) id1[a[m]] = m; else id2[n / a[m]] = m;
            g[m] = calc(a[m]);
        }
        for (int i = 1; i <= ncnt; i++) 
            for (int j = 1; j <= m && (ll)prime[i] * prime[i] <= a[j]; j++) 
                g[j] = g[j] - (ll)prime[i] * (g[ID(a[j] / prime[i])] - sum[i - 1]);
    }
    inline ll solve(ll x) {
        if (x <= 1) return x;
        //m(prime),m(flag),ncnt=0,m=0;
        return n = x, init(), g[ID(n)];
    }
}
int main(){
    cout<<Min25::solve(10)<<endl;
}
*/