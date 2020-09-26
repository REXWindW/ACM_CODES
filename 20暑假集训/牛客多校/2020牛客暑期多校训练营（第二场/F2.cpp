#include<iostream>
#include<deque>
using namespace std;
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define rep(i,a,b) for(int i=(a);i<=(b);i++) 
#define ll long long
const int MAXN = 5005;
struct node{
	int data;
	int order;
};
//int gcdm[MAXN][MAXN];
int a[MAXN][MAXN];
int res[MAXN][MAXN];//�ȴ���ÿ�н��е������г���� 
//int res2[MAXN][MAXN];//����ÿ�����ϵ�res���е������� 
//����ɾ����res2���ø���res1������ 

int main(){
	int m,n,k;
	cin>>m>>n>>k;
	rep(i,1,n){//o(n^2)��gcd 
		rep(j,1,m){
			if(!res[i][j]){
				for(int k=1;k*i<=n&&k*j<=m;k++){
					res[i*k][j*k] = k; 
					a[i*k][j*k] = i*j*k;
				}
			}
		}
	}
	deque<node> dq;//ÿ�н��е�������
	//�����뽨maxn��deque�ģ��������﷢�ֿ��Թ���
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!dq.empty()&&dq.front().order<j-k+1) dq.pop_front();
			while(!dq.empty()&&a[i][j]>=dq.back().data) dq.pop_back();
			dq.push_back(node{a[i][j],j});
			res[i][j] = dq.front().data;
		}
		dq.clear();
	}
	//��k��ʼ��ÿ�н��е������� 
	for(int j=k;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(!dq.empty()&&dq.front().order<i-k+1) dq.pop_front();
			while(!dq.empty()&&dq.back().data<=res[i][j]) dq.pop_back();
			dq.push_back(node{res[i][j],i});
			res[i][j] = dq.front().data;
		}
		dq.clear();
	}
	ll msum = 0;
	for(int i=k;i<=n;i++){
		for(int j=k;j<=m;j++){
			msum+=res[i][j];
		}
	}
	cout<<msum<<endl;
}
//�����и�С���£�ԭ����4��5k*5k�����������deque
//�ڴ泬�� 
//����ɾ����һ��deque������5k*5k�ĲŹ��� 
//wls˵��stl�Ƿǳ�ռ���ڴ棬����deque���ٶȱȽ����� 
