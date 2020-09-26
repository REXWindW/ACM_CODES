#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define ll long long
const int MAXN = 1e5+5;

ll ans;
int da[MAXN];//��¼dfn���ϵĸ�����ֵ������ʼ���߶���
int n,m,rt,p;//�ڵ�����ѯ����������ģ�� 

struct tree{
	int sum;
	int lazy;
};

struct St{//�߶��� 
	tree t[MAXN<<2];
	void pushup(int pos){ 
		t[pos].sum=(t[pos<<1].sum+t[pos<<1|1].sum) %p;
		return;
	}
	void pushdown(int l,int r,int pos){
		if(!t[pos].lazy) return;
		int mid = (l+r)>>1;
		t[pos<<1].sum += t[pos].lazy*(mid-l+1);
		t[pos<<1].sum %= p;//ȡģ 
		t[pos<<1|1].sum += t[pos].lazy*(r-(mid+1)+1);
		t[pos<<1|1].sum %= p;//ȡģ 
		t[pos<<1].lazy += t[pos].lazy;
		t[pos<<1].lazy %= p;//ȡģ 
		t[pos<<1|1].lazy += t[pos].lazy;
		t[pos<<1|1].lazy %= p;//ȡģ 
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
			t[pos].lazy %= p;//ȡģ 
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
			ans%=p;//ȡģ 
			return;
		}
		if(r<L||R<l) return;
		pushdown(l,r,pos);
		int mid = (l+r)>>1;
		query(L,R,l,mid,pos<<1);
		query(L,R,mid+1,r,pos<<1|1);
		return;
	}
	//��ѯ���޸ģ�Ϊ�˼򻯲���������д������ 
	ll tquery(int L,int R){
		ans = 0;
		query(L,R,1,n,1);
		return ans; 	
	}
	void tupdate(int L,int R,int v){
		update(L,R,1,n,1,v);
	} 
};
//���ṹ 
vector<int> e[MAXN];//��¼��
int a[MAXN];//��¼��Ŷ�Ӧ�ڵ�ĳ�ʼ��ֵ

//���ʲ���
St segt;
int si[MAXN],dep[MAXN],fa[MAXN],rem[MAXN],dfn[MAXN],top[MAXN];
int dfn_num;

void dfs1(int x,int faa){//Ԥ�����fa,dep,si,rem
	int ma = 0;//����x���ض��ӣ���¼����size
	si[x] = 1;
	for(auto v:e[x]){
		if(v==faa) continue;//�������׽ڵ� 
		dep[v] = dep[x]+1;//���¶��ӵ�dep 
		dfs1(v,x);
		si[x] += si[v];//x��size���ϵ�ǰ���ӵ�size
		fa[v] = x;//���v�ĸ��ڵ�Ϊx 
		if(si[v]>ma){
			ma = si[v];
			rem[x] = v;//��¼�ض��� 
		} 
	}
} 

void dfs2(int x,int faa){//Ԥ�����dfn��top
	if(rem[faa]==x) top[x] = top[faa];//ͬһ������ͬһ��top 
	else top[x] = x;//����Ϊ����ͷ
	dfn[x] = ++dfn_num;//����������ͬʱ�±�����
	da[dfn_num] = a[x];
	if(rem[x]) dfs2(rem[x],x);//���ȱ����ض���
	for(auto v:e[x]){
		if(v==faa) continue;
		if(v==rem[x]) continue;//�ض���֮ǰ�Ѿ���������
		dfs2(v,x); 
	} 
}

inline ll cal(int L,int R){
	return segt.tquery(L,R);
}

void init(){//��ʼ��
	dfn_num=0;
	dfs1(rt,0);
	dfs2(rt,0);
	segt.build(1,n,1);//����ͨ��da����ʼ���߶��� 
}

ll query(int x,int y){
	ll res=0;
	while(top[x]!=top[y]){//����ͬһ������ 
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		//������ȸ���ĵ�����������
		res += cal(dfn[top[x]],dfn[x]);//�������������� 
		res%=p;//ȡģ 
		x = fa[top[x]];//��������ͷ�ĸ��ڵ��� 
	}
	//�������ѭ��ʱ��xy�Ѿ���ͬһ����������
	res += cal(min(dfn[x],dfn[y]),max(dfn[x],dfn[y]));
	res%=p;//ȡģ 
	//xy��ȷ��˳��Բ��ԣ�����ȡminmax 
	return res;
}

void update(int x,int y,int v){
	ll res=0;
	while(top[x]!=top[y]){//����ͬһ������ 
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		//������ȸ���ĵ�����������
		segt.tupdate(dfn[top[x]],dfn[x],v);//������ֵ 
		x = fa[top[x]];//��������ͷ�ĸ��ڵ��� 
	}
	//�������ѭ��ʱ��xy�Ѿ���ͬһ����������
	segt.tupdate(min(dfn[x],dfn[y]),max(dfn[x],dfn[y]),v);
	//xy��ȷ��˳��Բ��ԣ�����ȡminmax
}

int main(){
	cin>>n>>m>>rt>>p;//�ڵ����������������ڵ���ţ�ģ��
	for(int i=1;i<=n;i++){
		cin>>a[i];//��¼��ʼ��ֵ 
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
		if(typ==1){//��·�����޸� 
			cin>>x>>y>>v;
			update(x,y,v);
		}
		else if(typ==2){//��·���ϲ�ѯ 
			cin>>x>>y;
			cout<<query(x,y)<<endl;
		}
		else if(typ==3){//�������޸� 
			cin>>x>>v;
			segt.tupdate(dfn[x],dfn[x]+si[x]-1,v);
		}
		else if(typ==4){//�����ϲ�ѯ 
			cin>>x;
			cout<<segt.tquery(dfn[x],dfn[x]+si[x]-1)<<endl;
		}
	}
}
