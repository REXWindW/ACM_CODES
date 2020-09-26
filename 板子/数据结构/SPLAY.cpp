#include<bits/stdc++.h>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define INF 0x3f3f3f3f
#define cendl printf("\n")
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff

const int MAXN = 5e5+5;
int root,tot,n;

struct Node{
    int ch[2];//左右儿子
    int val;//值
    int fa;//父节点
    int size;//子树大小
    int cnt;//计数 
}t[MAXN];

inline void pushup(int x){//维护节点的size 
	t[x].size = t[x].cnt;//自己重复的次数先累计
	if(t[x].ch[0]) t[x].size+=t[t[x].ch[0]].size;
	if(t[x].ch[1]) t[x].size+=t[t[x].ch[1]].size;
	//如果有儿子,把儿子的size加到自己
	//同线段树的pushup必须先处理儿子再处理父节点
}

void rotate(int x){//旋转操作
	int y=t[x].fa, z=t[y].fa;
	int k=(t[y].ch[1]==x);//x是y的左还是右儿子 
	t[z].ch[t[z].ch[1]==y] = x;//x换到y原来在的位置
	t[x].fa = z; 
	t[y].ch[k] = t[x].ch[k^1];//y顶下来x的儿子，放在x原来对y的位置 
	t[t[x].ch[k^1]].fa = y;
	t[x].ch[k^1] = y;//y换到 x原来在y的 相对的 位置
	t[y].fa = x;
	pushup(y),pushup(x);//更新size,因为y是儿子,所以先y 
}//这里的异或是用来调整0和1(左右儿子) 

inline void splay(int x,int goal){//找到x并把x旋转为goal的儿子根节点 
	while(t[x].fa!=goal){//x一直旋转到成为goal的儿子
		int y=t[x].fa,z=t[y].fa; 
		if(z!=goal)//如果y不是根节点,分两类讨论 
			(t[z].ch[0]==x)^(t[y].ch[0]==y)?rotate(x):rotate(y);
			//x和y分别是y和z的同一侧儿子,先转y再转x;不同则先转x转两次 
		rotate(x);//无论三种情况中的哪一种都要最后转x 
	}
	if(goal==0) root=x;//若goal是0,根节点更新为x
}

inline void find(int x){//查找x的位置,并旋转x到根节点,类似二分,O(logn) 
	int u = root;
	if(!u) return;//树是空的情况
	while(t[u].ch[x>t[u].val]&&x!=t[u].val)//找到x,不一定找得到
		u = t[u].ch[x>t[u].val];//左儿子小，右儿子大 
	splay(u,0);//当前位置旋转到根节点.根节点的fa存0
}

inline void insert(int x){//类似find,如果插入的数已经存在,可以在找到的节点计数 
	int u = root,fu = 0;//当前位置u,u的爸爸fu 
	while(u&&t[u].val!=x){//找合适位置,u找到空的地方也会停止
		fu = u;
		u = t[u].ch[x>t[u].val];
	}
	if(u) t[u].cnt++;//已有这个数字的情况,计数 
	else{
		u = ++tot;//节点总数tot+1
		if(fu)//这时候fu是上一个u即新插入u的父节点,如果父节点不是0
			t[fu].ch[x>t[fu].val]=u;
		t[u].ch[0] = t[u].ch[1] = 0;//这个新节点没儿子
		t[u].fa = fu;//父亲
		t[u].val = x;//数值
		t[u].cnt = 1;//计数
		t[u].size  = 1;//大小
	}
	splay(u,0);
}

inline int Next(int x,int f){
	find(x); 
	int u=root;//根节点，此时x的父节点(存在的话)就是根节点 
	//这里sls回答了我的疑问
	//"splay中不一定有x这个节点,那么它splay到根的就直接可以满足了"
	//"如果有这个点的话就要在splay上再找一波(因为当前的根就是x这个点)"
	if(t[u].val>x&&f)return u;//如果当前节点的值大于x并且要查找的是后继
    if(t[u].val<x&&!f)return u;//如果当前节点的值小于x并且要查找的是前驱 
    //上面两个是x不在splay中的情况
	u = t[u].ch[f];//后继在根右边找,前驱在左边找
	while(t[u].ch[f^1]) u = t[u].ch[f^1];//左半边要往右跳找最大的,右半边往左跳 
	return u;
}

inline void Delete(int x){//删除x 
	int last = Next(x,0);//查找x的前驱
	int next = Next(x,1);//找x的后继
	splay(last,0);splay(next,last);//前驱节点转到根节点,后继转到根的儿子上
	//操作完之后.后继是前驱的右儿子,x是前驱的左儿子,而且x是叶子节点 
	int del = t[next].ch[0];//后继的左儿子x
	if(t[del].cnt>1){
		t[del].cnt--;//如果有多个x,则x的计数减少一个
		splay(del,0);//这个splay还重新pushup计算了del的子树
	}
	else
		t[next].ch[0]=0;//因为是左儿子是叶子节点,直接丢掉 
}

inline int kth(int x){//找第k小,改一下也可以找第k大 
	int u=root;
		return 0; 
	while(1){
		int y = t[u].ch[0];//左儿子
		if(x>t[y].size+t[u].cnt){//如果左儿子和当前点的size比要找的排名数小 
			x-=t[y].size+t[u].cnt;//数量减少,相当于把这个寻找排名的起点变成了当前节点 
			u=t[u].ch[1];//那么当前排名的数一定要往右儿子上找 
		}
		else if(t[y].size>=x) u=y;//左儿子的size足够,儿子在左侧上找 
		else return t[u].val;//左儿子的size比x小,加上当前点u的size则比x大,说明第kA大的就是x 
	}
} 

int main(){
	tot=0;
	read(n);
    insert(+2147483647);insert(-2147483647);//博客作者在这里先加了正负INF
    int typ,x;
    while(n--){
        read(typ);
        if(typ==1){read(x);insert(x);}//插入 
        else if(typ==2){read(x);Delete(x);}//删除 
        else if(typ==3){//查找 
			read(x);find(x);
            printf("%d\n",t[t[root].ch[0]].size);
        }
        else if(typ==4){//第k小 
            read(x);printf("%d\n",kth(x+1));//之前插进去正负INF,所以要+1; 
        }
        else if(typ==5){//前驱
            read(x);printf("%d\n",t[Next(x,0)].val);
        }
        else if(typ==6){//后继 
            read(x);printf("%d\n",t[Next(x,1)].val);
        }
    }
    return 0;
}
//基本是抄的这个大爹的博客https://www.cnblogs.com/cjyyb/p/7499020.html
//再自己加了一点注解
//全部代码https://paste.ubuntu.com/p/gH5mWpz669/