#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
#define double long double
int hh,mm,h,d,c,n;//h初始,d消耗,c价格，n食物效果
inline int dis(int hh,int mm){
    return 60*(20-hh)+(0-mm);
}
void solve(){
    cin>>hh>>mm;
    cin>>h>>d>>c>>n;
    double minn = 1e12;
    if(dis(hh,mm)>0){
        minn = ceil((double)(dis(hh,mm)*d+h)/n)*(c-0.2*c);
        minn = min(minn,ceil((double)h/n)*c);
    }
    else if(dis(hh,mm)<=0){
        minn = ceil((double)h/n)*(c-0.2*c);
    }
    cout<<minn<<endl;
}

int main(){
    solve();
}