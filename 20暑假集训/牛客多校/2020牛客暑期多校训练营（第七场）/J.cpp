#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<set>
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
typedef pair<int,int> pii;
//#define INF 0x7fffffff
const int MAXN = 28;
int idx(char c){//给大小写字母编号 
	return c-'a'+1;
}
int lidx(char c){
	return c-'A'+1;
}
int n;

vector<int>V[MAXN];
vector<int>VFtoV[MAXN][MAXN];
vector<pii> VtoVF[MAXN];//pair的两个元素对应VF数组两个下标 
vector<int> VtoV[MAXN];//V指向V的情况，类似e

set<int>resset[MAXN];

set<int> dfsVtoV(int nowV);
set<int> dfsVtoVF(int nowV);
set<int> dfsVFtoV(pii nowVF);
set<int> dfsVtoO(int nowV);

set<int> dfsVtoV(int nowV){
	set<int>ress;
	set<int>hc;
	set<int>hc2;
	for(auto toV:VtoV[nowV]){
		hc=dfsVtoO(toV);
		set_union(hc.begin(),hc.end(),ress.begin(),ress.end(),inserter(hc2,hc2.begin()));
		ress = hc2;
		hc=dfsVtoVF(toV);
		set_union(hc.begin(),hc.end(),ress.begin(),ress.end(),inserter(hc2,hc2.begin()));
		ress = hc2;
		hc=dfsVtoV(toV);
		set_union(hc.begin(),hc.end(),ress.begin(),ress.end(),inserter(hc2,hc2.begin()));
		ress = hc2;
	}
	return ress;
}

set<int> dfsVtoVF(int nowV){
	set<int>ress;
	set<int>hc;
	set<int>hc2;
	for(auto toVF:VtoVF[nowV]){
		hc=dfsVFtoV(toVF);
		set_union(hc.begin(),hc.end(),ress.begin(),ress.end(),inserter(hc2,hc2.begin()));
		ress = hc2;
	}
	return ress;
}

set<int> dfsVFtoV(pii nowVF){
	set<int> ress;
	set<int>hc;
	set<int>hc2;
	for(auto toV:VFtoV[nowVF.first][nowVF.second]){
		hc=dfsVtoO(toV);
		set_union(hc.begin(),hc.end(),ress.begin(),ress.end(),inserter(hc2,hc2.begin()));
		ress = hc2;
		hc=dfsVtoVF(toV);
		set_union(hc.begin(),hc.end(),ress.begin(),ress.end(),inserter(hc2,hc2.begin()));
		ress = hc2;
		hc=dfsVtoV(toV);
		set_union(hc.begin(),hc.end(),ress.begin(),ress.end(),inserter(hc2,hc2.begin()));
		ress = hc2;
	}
	//set_union(resset[nowVF.first].begin(),resset[nowVF.first].end(),ress.begin(),ress.end(),inserter(hc2,hc2.begin()));
	//resset[nowVF.first] = hc2;
	return ress;
}

set<int> dfsVtoO(int nowV){
	return resset[nowV];
}

int main(){
	string str;
	int leftV,leftF,rightV,rightF,rightO;
	cin>>n;
	getline(cin,str);
	rep(i,1,n){
		getline(cin,str);
		if(str[1]=='.'){//VF指向V的情况
			leftV = lidx(str[0]);
			leftF = idx(str[2]);
			rightV = lidx(str[6]);
			VFtoV[leftV][leftF].push_back(rightV);
		} 
		else if(str[5]=='.'){//V添加VF的情况
			leftV = lidx(str[0]);
			rightV = lidx(str[4]);
			rightF = idx(str[6]);
			VtoVF[leftV].push_back(make_pair(rightV,rightF));
		}
		else{
			if(isupper(str[4])){
				leftV = lidx(str[0]);
				rightV = lidx(str[4]);
				VtoV[leftV].push_back(rightV);
			}
			else if(islower(str[4])){
				leftV = lidx(str[0]);
				rightO = idx(str[4]);
				VtoV[leftV].clear();//test
				VtoVF[leftV].clear();//test
				resset[leftV].insert(rightO);
			}
		}
	}
//	/*
	rep(i,1,26){
		set<int>hc;
		set<int>hc2;
		hc=dfsVtoV(i);
		set_union(hc.begin(),hc.end(),resset[i].begin(),resset[i].end(),inserter(hc2,hc2.begin()));
		resset[i] = hc2;
		hc=dfsVtoVF(i);
		set_union(hc.begin(),hc.end(),resset[i].begin(),resset[i].end(),inserter(hc2,hc2.begin()));
		resset[i] = hc2;
		hc=dfsVtoO(i);
		set_union(hc.begin(),hc.end(),resset[i].begin(),resset[i].end(),inserter(hc2,hc2.begin()));
		resset[i] = hc2;
	}
//	*/
	rep(i,1,26){
		set<int>hc;
		set<int>hc2;
		hc=dfsVtoV(i);
		set_union(hc.begin(),hc.end(),resset[i].begin(),resset[i].end(),inserter(hc2,hc2.begin()));
		resset[i] = hc2;
		hc=dfsVtoVF(i);
		set_union(hc.begin(),hc.end(),resset[i].begin(),resset[i].end(),inserter(hc2,hc2.begin()));
		resset[i] = hc2;
		hc=dfsVtoO(i);
		set_union(hc.begin(),hc.end(),resset[i].begin(),resset[i].end(),inserter(hc2,hc2.begin()));
		resset[i] = hc2;
		char hcc;
		hcc = i+'A'-1;
		cout<<hcc<<": ";
		for(auto x:resset[i]){
			hcc = x+'a'-1;
			cout<<hcc;
		}
		cout<<endl;
	}
}

