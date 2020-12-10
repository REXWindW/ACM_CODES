#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
struct Node{
	int d,p;
	Node(int _d=0,int _p=0){
		d=_d; p=_p;
	}
	bool operator < (const Node &rhs) const{
		if(d!=rhs.d) return d<rhs.d;
		else return p<rhs.p;
	}
};
set<Node> mp; set<int> st;
int n,m,op,x,p[N];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d",&op);
		if(op==1){
			if((int)st.size()==0){
				p[i]=1; st.insert(1);
				if(2<=n) mp.insert(Node(n-1,n));
			}else{
				p[i]=(*mp.begin()).p; mp.erase(mp.begin());
				auto it=st.lower_bound(p[i]);
				int l=-1,r=-1;
				if(it!=st.end()) r=*(it);
				if(it!=st.begin()){
					--it; l=*(it);
				}
				st.insert(p[i]);
				if(l==-1){
					if(p[i]>1) mp.insert(Node(p[i]-1,1));
				}else if(l<=p[i]-1){
					mp.insert(Node((p[i]+l)/2-l,(p[i]+l)/2));
				}
				if(r==-1){
					if(p[i]<n) mp.insert(Node(n-p[i],n));
				}else if(p[i]+1<=r){
					mp.insert(Node((p[i]+r)/2-p[i],(p[i]+r)/2));
				}
				st.insert(p[i]);
			}
			printf("ppp = %d\n",p[i]);
		}else{
			scanf("%d",&x);
			if((int)st.size()==1){
				st.clear(); mp.clear();
			}else{
				p[i]=p[x];
				auto it=st.lower_bound(p[i]);
				int l=-1,r=-1;
				if(it!=st.begin()){
					--it; l=*(it); ++it;
				}
				++it;
				if(it!=st.end()) r=*it;
				st.erase(p[i]);
				
				
				if(l==-1){
					if(p[i]>1) mp.erase(Node(p[i]-1,1));
				}else if(l<=p[i]-1){
					mp.erase(Node((p[i]+l)/2-l,(p[i]+l)/2));
				}
				if(r==-1){
					if(p[i]<n) mp.erase(Node(n-p[i],n));
				}else if(p[i]+1<=r){
					mp.erase(Node((p[i]+r)/2-p[i],(p[i]+r)/2));
				}
				
				printf("%d %d\n",l,r);
				if(l!=-1&&r!=-1){
					mp.insert(Node((l+r)/2-l,(l+r)/2));
				}else if(l==-1){
					mp.insert(Node(r-1,1));
				}else if(r==-1){
					mp.insert(Node(n-l,n));
				}
			}
		}
	}
}