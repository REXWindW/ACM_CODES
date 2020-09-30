#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

#define MAXN 100000 

int par[MAXN];//记录父亲节点 
int rank[MAXN];//记录树高,根节点(祖先节点)那层是不算进去的  

void init(int n){
	for(int i=0;i<n;i++){
		par[i]=i;
		rank[i]=0;
	}
} 

int find(int x){//查询根操作，同时进行路径压缩 
	if(par[x]==x) return x;
	else return par[x]=find(par[x]);//这句很精简,在递归查询根节点的同时路i压缩 
} 
//虽然路径压缩的操作会对树高产生影响，导致rank的数值不准确，但这样还是能有效地提高运行效率的 

void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;///如果已经具有相同的祖先，则不进行合并操作
	if(rank[x]<rank[y]) par[x]=y;//y树比x树高的情况，把x并为y的儿子节点 
	else{//y比x高，或同高的情况下，把y并为x的儿子节点 
		par[y]=x;
		if(rank[x]==rank[y]) rank[x]++;//如果合并的两树同高，则合并后树高+1; 
	} 
} 

int main(){
	int n,m;
	cin>>n>>m;
	init(n);
	int a,b;
	while(m--){
		cin>>a>>b;
		merge(a,b);
	}
	cin>>m;
	while(m--){
		cin>>a>>b;
		if(find(a)==find(b)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
} 
//路径压缩+树高优化