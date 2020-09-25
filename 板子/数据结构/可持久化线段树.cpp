#include<iostream>
#include<algorithm>
using namespace std;
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define mid ((l+r)>>1)

const int MAXN = 2e5+5;
int n,q,m,cnt=0;
int a[MAXN],b[MAXN]; 
int T[MAXN];//记录每个时间上树的根节点 
int sum[MAXN<<5];//记录节点覆盖区间内数字的数量 
int L[MAXN<<5],R[MAXN<<5];//记录左右儿子 

int build(int l,int r){//一开始通过递归建树
	int pos = ++cnt;//建立新的节点，节点数cnt自增
	sum[pos]=0;//时间0时是没有任何数字的
	if(l<r){
		L[pos]=build(l,mid);
		R[pos]=build(mid+1,r);
	}
	return pos; 
}

int update(int pre,int l,int r,int x){//pre是在pos位置上一个时间的节点编号
	int pos = ++cnt;
	L[pos]=L[pre];R[pos]=R[pre];//pre是上个时间点在如今pos位置上的节点
	//这里相当于是把这个新的节点接到相应的位置
	sum[pos] = sum[pre]+1;//这一整条链上各点的权值都+1(叶子上加了1，上面的都受影响)
	if(l<r){//找到长度为一个数的节点就结束递归了
		if(x<=mid) L[pos] = update(L[pre],l,mid,x);
		else R[pos] = update(R[pre],mid+1,r,x);
		//判断数值x的这个节点在当前节点的左儿子还是右儿子
		//这样一直沿着这条链往下，建立新的节点。
		//因为pos节点的儿子中新建立的节点需要返回编号
	}
	return pos;
}

int query(int u,int v,int l,int r,int k){
	if(l>=r) return l;
	int x = sum[L[v]]-sum[L[u]];//计算左子树中数的数量x 
	if(x>=k) return query(L[u],L[v],l,mid,k);//x比k大，说明第k大的数在左子树中
	else return query(R[u],R[v],mid+1,r,k-x);
}

int main(){
	cin>>n>>q;
	rep(i,1,n){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	m = unique(b+1,b+1+n)-b-1;//排序后可以用unique函数去重 
	T[0] = build(1,m);
	rep(i,1,n){
		int t = lower_bound(b+1,b+1+m,a[i]) - b;//找到对应的离散化后的数值
		T[i] = update(T[i-1],1,m,t);//建立新时间的根节点，并且建新的链并接上去 
	}
	while(q--){
		int u,v,k;
		cin>>u>>v>>k;//找u到v区间内第k大的数 
		int t = query(T[u-1],T[v],1,m,k); 
		cout<<b[t]<<endl;//输出对应的原值
	} 
}