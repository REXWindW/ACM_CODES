#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std; 

#define ll long long 
#define MAXN 110

int n;
const ll mod = 998;

struct Matrix{
	ll a[MAXN][MAXN];
	
	Matrix(ll x=0){//感觉是特别好的初始化,从hjt那里学(抄)来的 
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				a[i][j]=x*(i==j);//这句特简洁		
			}
		}
	}
	
	Matrix operator *(const Matrix &b)const{//通过重载运算符实现矩阵乘法 
		Matrix res(0);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					ll &ma = res.a[i][j];
					ma = (ma+a[i][k]*b.a[k][j])%mod;
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

int main(){
	int p;
	Matrix inp;
	cin>>n>>p;
	for(int i=-0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%lld",&inp.a[i][j]);
		}
	}
	Matrix res = qpow(inp,p);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<res.a[i][j];
			if(j!=n-1) cout<<' ';
		}
		cout<<endl;
	}
}