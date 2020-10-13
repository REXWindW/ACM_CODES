#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<functional>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define INF 0x3f3f3f3f
#define cendl printf("\n")
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff

const int MAXN = 1e5+5;
const int Mod = 1e9+7;
int a[MAXN];
int n;
//���鼯���� 
int par[MAXN];//��¼���׽ڵ� 
int rk[MAXN];//��¼����,���ڵ�(���Ƚڵ�)�ǲ��ǲ����ȥ��  
void init(int n){
	for(int i=0;i<n;i++){
		par[i]=i;
		rk[i]=0;
	}
} 
int find(int x){//��ѯ��������ͬʱ����·��ѹ�� 
	if(par[x]==x) return x;
	else return par[x]=find(par[x]);//�ݹ��ѯ���ڵ��ͬʱ·iѹ�� 
}

ll cnt1[MAXN];
ll cnt2[MAXN];//��¼�����������ж��ٸ�1��2 
ll tot1,tot2;//��¼1��2������

ll merge(int x,int y){//����ֵ����κϲ�֮���ٵ������� 
	ll ans;
	ll rest1,rest2;
	x=find(x);
	y=find(y);
	if(x==y) return 0;//��Ŀ����������� 
	if(rk[x]<rk[y]){
		par[x]=y;//x����y 
		rest1 = tot1-cnt1[y]-cnt1[x];
		rest2 = tot2-cnt2[y]-cnt2[x];//����ʣ������1��2
		//��ans 
		ans = cnt2[x]*cnt2[y]*(rest1+rest2);//xy����2 
		ans += cnt2[x]*cnt1[y]*rest2;
		ans += cnt2[y]*cnt1[x]*rest2; 
		
		cnt1[y] = cnt1[y]+cnt1[x];
		cnt2[y] = cnt2[y]+cnt2[x];//��x����˶�����y�� 
	}
	else{
		par[y]=x;
		if(rk[x]==rk[y]) rk[x]++;
		rest1 = tot1-cnt1[x]-cnt1[y];
		rest2 = tot2-cnt2[x]-cnt2[y];
		//��ans
		ans = cnt2[x]*cnt2[y]*(rest1+rest2);//xy����2 
		ans += cnt2[x]*cnt1[y]*rest2;
		ans += cnt2[y]*cnt1[x]*rest2;
		
		cnt1[x] = cnt1[y]+cnt1[x];
		cnt2[x] = cnt2[y]+cnt2[x];
	}
	cout<<"minus"<<ans<<endl;
	return ans; 
}

void solve(){
	tot1=tot2=0;
	cin>>n;
	init(n); 
	rep(i,1,n){
		cin>>a[i];
		if(a[i]==1) cnt1[i]=1,cnt2[i]=0,tot1++;//һ��ʼÿ���˶������� 
		else cnt2[i]=1,cnt1[i]=0,tot2++;
	}
	//ll res = (tot2*(tot2-1)*tot1%Mod + tot2*(tot2-1)*(tot2-2)%Mod)%Mod;
	ll res = (tot2*(tot2-1)/2*tot1 + tot2*(tot2-1)*(tot2-2)/2/3);
	//�����û��������µĽ��
	cout<<res%Mod<<endl; 
	int u,v;
	rep(i,1,n-1){
		cin>>u>>v;
		res-=merge(u,v);
		cout<<max(res%Mod,(ll)0)<<endl;
	}
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}

