#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
#define int ll
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int n,m;
int cnt[14];
ll res;
const int med = 1e9+7;
const int MAXN = 14;
struct Matrix{
	ll a[MAXN][MAXN];
	Matrix(ll x=0){//感觉是特别好的初始化,从hjt那里学(抄)来的 
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				a[i][j] = 0;
			}
		}
	}
	Matrix operator *(const Matrix &b)const{//通过重载运算符实现矩阵乘法 
		Matrix res(0);
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				for(int k=0;k<10;k++){
					ll &ma = res.a[i][j];
					ma = (ma+a[i][k]*b.a[k][j])%med;
				}
			}
		}
		return res;
	}
};

Matrix qpow(Matrix d,ll m){//底数和幂次数 
	Matrix res(1);//构造E单位矩阵 
	while(m){
		if(m&1){
			m--;//其实这句是可以不要的 
			res=res*d;
		}
		d=d*d;
		m>>=1;
	}
	return res; 
}

inline void solve(){
    rep(i,0,9) cnt[i] = 0;
    scanf("%lld%lld",&n,&m);
    while(n){
        cnt[n%10]++;
        n/=10;
    }
	Matrix inp;
    rep(i,0,9)
        inp.a[0][i] = cnt[i];
    Matrix mi;
    rep(i,0,9){
        mi.a[i][(i+1)%10]=1;
    }
    mi.a[9][1]=1;
	Matrix res = qpow(mi,m);
    rep(i,0,9){
        rep(j,0,9){
            cout<<res.a[i][j]<<' ';
        }
        cout<<endl;
    }
    res = inp*res;
    ll ress = 0;
	for(int i=0;i<10;i++){
		ress+=res.a[0][i];
        ress%=med;
	}
    printf("%lld\n",ress%med);
}

signed main(){
    int z;
    scanf("%lld",&z);
    while(z--) solve();
}