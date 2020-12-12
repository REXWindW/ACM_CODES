#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
#define log(x) (31-__builtin_clz(x))//谢谢hjt
const int MAXN = 1e5+10;
const int LOGN = log(MAXN)/log(2)+5;//这里要开大一点,之前因为没开大翻车了 

int M[MAXN][LOGN]; 
int a[MAXN];
int z,m,n;

void init(){//初始化，复杂度O(nlogn) 
	for(int i=1;i<=n;i++) M[i][0]=i;//长度为1的区间最值是自己 
	for(int j=1;j<=LOGN;j++){
		for(int i=1;i<=n-(1<<j)+1;i++){
			if(a[M[i][j-1]]<a[M[i+(1<<(j-1))][j-1]]) M[i][j] = M[i][j-1];//这里以最小值为例 
			else M[i][j] = M[i+(1<<j-1)][j-1];
		}
	} 
}

int query(int l,int r){
	int k = log(r-l+1)/log(2);//向下取整
	if(a[M[l][k]]<a[M[r-(1<<k)+1][k]]) return M[l][k];
	else return M[r-(1<<k)+1][k];
}

int main(){
	int q;
	scanf("%d%d",&n,&q); 
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	init();
	int l,r;
	while(q--){
		scanf("%d%d",&l,&r);
		printf("%d\n",a[query(l,r)]);
	}
}