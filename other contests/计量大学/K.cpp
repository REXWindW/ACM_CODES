#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cstdlib>
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
const int MAXN = 2e6+5;
string s;
int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int dr[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int pi[MAXN];//MAXN记得开大一点,因为这里要存到m+n+1长度的
void getpi(const string &s){ //求s的前缀函数
	pi[0]=0;
	int j=0;
	rep(i,1,s.length()-1){
		while(j>0&&s[i]!=s[j]) j=pi[j-1];//找到合适且最长的j 
		if(s[i]==s[j])j++;//能成功匹配的情况 
		pi[i]=j;
	}
}
bool kmp(string s,string t){ //在主串t中找模式串s 
	getpi(s+'#'+t);
	int n=(int)s.length(),m=(int)t.length();
	rep(i,n+1,m+n+1-1){
		if(pi[i]==n){//i-2n计算得左端点
            return 1;
        }
    }
    return 0;
}

bool run(int x){//判断是否为闰年
    if(x%100&&x%4==0) return 1;
    else if(x%400==0) return 1;
    return 0;
}
bool judge(string x){
    //cout<<x<<endl;
    string y = x;
    reverse(y.begin(),y.end());
    getpi(x);
    if(!kmp(x,y)) return 0;
    //cout<<"first test pass"<<x<<endl;
    int yy,mm,dd;
    yy = stoi(x.substr(0,4));
    mm = stoi(x.substr(4,2));
    dd = stoi(x.substr(6,2));
    if(mm<=12&&mm>=1){
        if(run)
            if(dd!=0&&dd<=d[mm]) return 1;
        else
            if(dd!=0&&dd<=dr[mm]) return 1;
    } 
    return 0;
}
void solve(){
    int cnt = 0;
    int siz = s.size();
    rep(i,0,siz-8){//保证长度大于8
        if(s[i+7]==' '){//跳过
            i+=7;continue;
        }
        //cout<<"substr"<<s.substr(i,8)<<endl;
        if(judge(s.substr(i,8))) cnt++;
    }
    cout<<cnt<<endl;
}

int main(){
    while(1){
        getline(cin,s);
        if(s[0]=='#') break;
        solve();
    }
}