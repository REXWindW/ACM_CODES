#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
const int MAXN = 114514;
int n;
string a[MAXN];
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
    rep(i,n+1,m+n+1-1)
        if(pi[i]==n) return 1; //i-2n计算得左端点 
    return 0;
}
void solve(){
    ll res = 0;
    cin>>n;
    rep(i,1,n)
        cin>>a[i];
    rep(i,1,n){
        bool flag = 1;
        rep(j,1,i-1){
            getpi(a[j]);
            if(kmp(a[j],a[i]+a[i])) {flag = 0;break;}
        }
        res+=flag;
    }
    cout<<res<<endl;
}

int main(){
    solve();
}