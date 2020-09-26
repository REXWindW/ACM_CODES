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

int a[26][26];
int n;

void solve(){
	memset(a,0,sizeof(a));
	cin>>n;
	if(n<8){
		if(n==0){
			cout<<1<<' '<<1<<endl;
			cout<<"X"<<endl;
		}
		else if(n==1){
			cout<<1<<' '<<2<<endl;
			cout<<"X."<<endl;
		}
		else if(n==2){
			cout<<1<<' '<<3<<endl;
			cout<<"X.X"<<endl;
		}
		else if(n==3){
			cout<<2<<' '<<2<<endl;
			cout<<"X."<<endl<<".."<<endl;
		}
		else if(n==4){
			cout<<2<<' '<<2<<endl;
			cout<<"X."<<endl<<"X."<<endl; 
		}
		else if(n==5){
			cout<<2<<' '<<3<<endl;
			cout<<".X."<<endl<<"..."<<endl;
		}
		else if(n==6){
			cout<<3<<' '<<3<<endl;
			cout<<"X.."<<endl<<"..."<<endl<<"..X"<<endl;
		}
		else if(n==7){
			cout<<2<<' '<<3<<endl;
			cout<<"X.X"<<endl<<".X."<<endl;
		}
		return;
	}
	int dot = n/8;
	int ys = n%8;
	int mr=1,mc=1;
	int cnt = dot;
	rep(i,1,12){
		mr = max(mr,i*2+1);
		rep(j,1,12){
			if(cnt==0) break;
			mc = max(mc,j*2+1);
			a[i*2][j*2]=1;
			cnt--;
		}
		if(cnt==0) break;
	}
	if(dot==1){
		if(ys<=4){
			int px = 1;
			while(ys){
				if(px==1) a[1][1] = 1;
				else if(px==2) a[1][3]=1;
				else if(px==3) a[3][1] = 1;
				else if(px==4) a[3][3] = 1;
				ys--;px++;
			}
		}
		else{
			if(ys==5){a[1][3]=a[1][1]=a[3][2]=1;}
			if(ys==6){a[1][2]=a[3][2]=1;}
			if(ys==7){
				cout<<3<<' '<<4<<endl;
				cout<<"X..."<<endl;
				cout<<"X.X."<<endl;
				cout<<"X..."<<endl;
				return; 
			}
		}
		ys=0;
	}
	dot = ys/4;
	ys = ys%4;//一定小于3 
	if(dot) a[2][3]=1;
	int px = 1;
	while(ys){
		if(px==1) a[1][1] = 1;
		else if(px==2) a[1][mc]=1;
		else if(px==3) a[mr][1] = 1;
		ys--;px++;
	}
	cout<<mr<<' '<<mc<<endl;
	rep(i,1,mr){
		rep(j,1,mc){
			if(a[i][j]==1) cout<<'X';
			else cout<<'.';
		}
		cout<<endl;
	}
}

int main(){
	//freopen("inp.txt","w",stdout);
	int z;
	cin>>z;
	while(z--) solve();
}

