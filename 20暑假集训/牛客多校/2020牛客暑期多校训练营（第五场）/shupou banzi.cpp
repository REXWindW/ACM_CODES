#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define ll long long
const int MAXN = 1e5+5;

ll ans;
int da[MAXN];//记录dfn序上的各点数值用来初始化线段树
int n,m,rt,p;//节点数，询问数，根，模数 

struct tree{
	int sum;
	int lazy;
};

struct St{//线段树 
	tree t[MAXN<<2];
	void pushup(int pos){ 
		t[pos].sum=(t[pos<<1].sum+t[pos<<1|1].sum) %p;
		return;
	}
	void pushdown(int l,int r,int pos){
		if(!t[pos].lazy) return;
		int mid = (l+r)>>1;
		t[pos<<1].sum += t[pos].lazy*(mid-l+1);
		t[pos<<1].sum %= p;//取模 
		t[pos<<1|1].sum += t[pos].lazy*(r-(mid+1)+1);
		t[pos<<1|1].sum %= p;//取模 
		t[pos<<1].lazy += t[pos].lazy;
		t[pos<<1].lazy %= p;//取模 
		t[pos<<1|1].lazy += t[pos].lazy;
		t[pos<<1|1].lazy %= p;//取模 
		t[pos].lazy = 0; 
	}
	void build(int l,int r,int pos){ 
		t[pos].sum = t[pos].lazy = 0;
		if(l==r){
			t[pos].sum = da[l];
			return;
		}
		int mid = (l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		pushup(pos);
	}
	void update(int L,int R,int l,int r,int pos,int v){
		if(L<=l&&r<=R){
			t[pos].sum += v*(r-l+1);
			t[pos].lazy += v;
			t[pos].lazy %= p;//取模 
			return;
		}
		if(r<L||l>R) return;
		pushdown(l,r,pos);
		int mid = (l+r)>>1;
		update(L,R,l,mid,pos<<1,v);
		update(L,R,mid+1,r,pos<<1|1,v);
		pushup(pos);
	}
	void query(int L,int R,int l,int r,int pos){
		if(L<=l&&r<=R){
			ans += t[pos].sum;
			ans%=p;//取模 
			return;
		}
		if(r<L||R<l) return;
		pushdown(l,r,pos);
		int mid = (l+r)>>1;
		query(L,R,l,mid,pos<<1);
		query(L,R,mid+1,r,pos<<1|1);
		return;
	}
	//查询和修改，为了简化参数，我又写了两个 
	ll tquery(int L,int R){
		ans = 0;
		query(L,R,1,n,1);
		return ans; 	
	}
	void tupdate(int L,int R,int v){
		update(L,R,1,n,1,v);
	} 
};
//树结构 
vector<int> e[MAXN];//记录边
int a[MAXN];//记录编号对应节点的初始数值

//树剖部分
St segt;
int si[MAXN],dep[MAXN],fa[MAXN],rem[MAXN],dfn[MAXN],top[MAXN];
int dfn_num;

void dfs1(int x,int faa){//预处理出fa,dep,si,rem
	int ma = 0;//用来x的重儿子，记录最大的size
	si[x] = 1;
	for(auto v:e[x]){
		if(v==faa) continue;//跳过父亲节点 
		dep[v] = dep[x]+1;//更新儿子的dep 
		dfs1(v,x);
		si[x] += si[v];//x的size加上当前儿子的size
		fa[v] = x;//标记v的父节点为x 
		if(si[v]>ma){
			ma = si[v];
			rem[x] = v;//记录重儿子 
		} 
	}
} 

void dfs2(int x,int faa){//预处理出dfn，top
	if(rem[faa]==x) top[x] = top[faa];//同一条重链同一个top 
	else top[x] = x;//否则为重链头
	dfn[x] = ++dfn_num;//更新树剖序，同时下标自增
	da[dfn_num] = a[x];
	if(rem[x]) dfs2(rem[x],x);//优先遍历重儿子
	for(auto v:e[x]){
		if(v==faa) continue;
		if(v==rem[x]) continue;//重儿子之前已经遍历过了
		dfs2(v,x); 
	} 
}

inline ll cal(int L,int R){
	return segt.tquery(L,R);
}

void init(){//初始化
	dfn_num=0;
	dfs1(rt,0);
	dfs2(rt,0);
	segt.build(1,n,1);//这里通过da来初始化线段树 
}

ll query(int x,int y){
	ll res=0;
	while(top[x]!=top[y]){//跳到同一条重链 
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		//重链深度更大的点优先往上跳
		res += cal(dfn[top[x]],dfn[x]);//算上这条重链的 
		res%=p;//取模 
		x = fa[top[x]];//跳到重链头的父节点上 
	}
	//跳出这个循环时，xy已经在同一个重链上了
	res += cal(min(dfn[x],dfn[y]),max(dfn[x],dfn[y]));
	res%=p;//取模 
	//xy不确定顺序对不对，所以取minmax 
	return res;
}

void update(int x,int y,int v){
	ll res=0;
	while(top[x]!=top[y]){//跳到同一条重链 
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		//重链深度更大的点优先往上跳
		segt.tupdate(dfn[top[x]],dfn[x],v);//更新数值 
		x = fa[top[x]];//跳到重链头的父节点上 
	}
	//跳出这个循环时，xy已经在同一个重链上了
	segt.tupdate(min(dfn[x],dfn[y]),max(dfn[x],dfn[y]),v);
	//xy不确定顺序对不对，所以取minmax
}

int main(){
	cin>>n>>m>>rt>>p;//节点数，操作数，根节点序号，模数
	for(int i=1;i<=n;i++){
		cin>>a[i];//记录初始数值 
		a[i] = a[i]%p;
	} 
	int x,y;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<n;i++){
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	init();
	int v;
	int typ;
	while(m--){
		cin>>typ;
		if(typ==1){//简单路径上修改 
			cin>>x>>y>>v;
			update(x,y,v);
		}
		else if(typ==2){//简单路径上查询 
			cin>>x>>y;
			cout<<query(x,y)<<endl;
		}
		else if(typ==3){//子树上修改 
			cin>>x>>v;
			segt.tupdate(dfn[x],dfn[x]+si[x]-1,v);
		}
		else if(typ==4){//子树上查询 
			cin>>x;
			cout<<segt.tquery(dfn[x],dfn[x]+si[x]-1)<<endl;
		}
	}
}
