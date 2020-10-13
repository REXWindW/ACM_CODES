#include<iostream>
#include<deque>
using namespace std; 

struct node{//结构体，存储数值和位置 
	int data;
	int order;//原本数列里的位置 
};

const int MAXN = 1e6+5;

deque<node>dq_min;
deque<node>dq_max;

int n,k;
int a[MAXN];
int res_min[MAXN];
int res_max[MAXN];

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		//如果队列头超过这k的范围，则出队 
		if(!dq_max.empty()&&dq_max.front().order<i-k+1) dq_max.pop_front();
		if(!dq_min.empty()&&dq_min.front().order<i-k+1) dq_min.pop_front();
		//新元素从队尾插进来，队尾没用的元素在这里出队 
		while(!dq_max.empty()&&dq_max.back().data<=a[i]) dq_max.pop_back();
		dq_max.push_back(node{a[i],i});
		while(!dq_min.empty()&&dq_min.back().data>=a[i]) dq_min.pop_back();
		dq_min.push_back(node{a[i],i});
		//存储区间最大最小值 
		res_max[i] = dq_max.front().data;
		res_min[i] = dq_min.front().data;
	}
	for(int i=k;i<=n;i++){
		cout<<res_min[i];
		if(i!=n) cout<<' ';
	}
	cout<<endl;
	for(int i=k;i<=n;i++){
		cout<<res_max[i];
		if(i!=n) cout<<' ';
	}
	cout<<endl;
}
//洛谷 P1886 滑动窗口 /【模板】单调队列 https://www.luogu.com.cn/problem/P1886