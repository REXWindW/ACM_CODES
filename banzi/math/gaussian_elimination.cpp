#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)

const int MAXN = 1004; 
double a[MAXN][MAXN];
int n,pl;

int main(){
	scanf("%d",&n);
	rep(i,1,n)
		rep(j,1,n+1) scanf("%lf",&a[i][j]); 
	rep(i,1,n){
		pl = i;
		while(a[pl][i]==0&&pl<=n) pl++;//找到每列的第一个非0元素
		if(pl==n+1){//无解的情况(存在空列 
			cout<<"No Solution"<<endl;return 0;
		} 
		rep(j,1,n+1) swap(a[i][j],a[pl][j]);//保证i行i列必不是0
		double k = a[i][i];//第二步，使a[i][i]变成1 
		rep(j,1,n+1) a[i][j]/=k;//i行所有元素除a[i][i]
		rep(ii,1,n){
			if(ii==i) continue;//枚举不同的两行
			double ki = a[ii][i];
			rep(m,1,n+1) a[ii][m]-=ki*a[i][m]; 
		}  
	}
	rep(i,1,n) printf("%.2lf\n",a[i][n+1]);
}
//洛谷P3389 【模板】高斯消元法 https://www.luogu.com.cn/problem/P3389