#include <bits/stdc++.h>
using namespace std;
const int MAXN=200010;
int t1[MAXN],t2[MAXN],c[MAXN],rak[MAXN],height[MAXN];
//int RMQ[MAXN],mm[MAXN],best[20][MAXN];
bool cmp(int *r,int a,int b,int l){
	return r[a] == r[b] && r[a+l] == r[b+l];
}
void da(int str[],int sa[],int rak[],int height[],int n,int m){
	n++;
	int i, j, p, *x = t1, *y = t2;
	for(i = 0;i < m;i++)c[i] = 0;
	for(i = 0;i < n;i++)c[x[i] = str[i]]++;
	for(i = 1;i < m;i++)c[i] += c[i-1];
	for(i = n-1;i >= 0;i--)sa[--c[x[i]]] = i;
	for(j = 1;j <= n; j <<= 1){
		p = 0;
		for(i = n-j; i < n; i++)y[p++] = i;
		for(i = 0; i < n; i++)if(sa[i] >= j)y[p++] = sa[i] - j;
		for(i = 0; i < m; i++)c[i] = 0;
		for(i = 0; i < n; i++)c[x[y[i]]]++;
		for(i = 1; i < m;i++)c[i] += c[i-1];
		for(i = n-1; i >= 0;i--)sa[--c[x[y[i]]]] = y[i];
		swap(x,y);
		p = 1; x[sa[0]] = 0;
		for(i = 1;i < n;i++)
		x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		if(p >= n)break;
		m = p;
	}
	int k = 0;
	n--;
	for(i = 0;i <= n;i++)rak[sa[i]] = i;
	for(i = 0;i < n;i++){
		if(k)k--;
		j = sa[rak[i]-1];
		while(str[i+k] == str[j+k])k++;
		height[rak[i]] = k;
	}
}

/*void initRMQ(int n){
	for(int i=1;i<=n;i++)RMQ[i]=height[i];
	mm[0]=-1;
	for(int i=1;i<=n;i++)mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
	for(int i=1;i<=n;i++)best[0][i]=i;
	for(int i=1;i<=mm[n];i++)
	for(int j=1;j+(1<<i)-1<=n;j++){
		int a=best[i-1][j];
		int b=best[i-1][j+(1<<(i-1))];
		if(RMQ[a]<RMQ[b])best[i][j]=a;
		else best[i][j]=b;
	}
}
int askRMQ(int a,int b){
	int t;
	t=mm[b-a+1];
	b-=(1<<t)-1;
	a=best[t][a];b=best[t][b];
	return RMQ[a]<RMQ[b]?a:b;
}
int lcp(int a,int b){
	a=rak[a];b=rak[b];
	if(a>b)swap(a,b);
	return height[askRMQ(a+1,b)];
}*/
char str[MAXN];
int r[MAXN],sa[MAXN];
int main(){
	while(scanf("%s",str) == 1){
		int len1 = strlen(str);
		str[len1]='#';
		scanf("%s",str+len1+1);
		int len=strlen(str);
		int n=len+1;
		for(int i = 0;i < len;i++)r[i] = str[i];
		for(int i = 0;i < len;i++)r[len + 1 + i] = str[len - 1 - i];
		r[len] = 1;
		r[n] = 0;
		da(r,sa,rak,height,n,'z'+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			if((sa[i]-len1)*(sa[i-1]-len1)<0)ans=max(ans,height[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1.可重叠最长重复字串 O(n)
求height数组里的最大值，最长重复字串等价于求两个后缀的最长公共前缀的最大值，
因为任意两个后缀的最长公共前缀都是height数组里某一段的最小值

2.不可重叠最长重复字串 O(nlogn)
二分答案，判断是否存在两个长度为k的子串是相同且不重叠的。
把排序后的后缀分成若干组，其中每组的后缀之间的height值都不小于k
*/
