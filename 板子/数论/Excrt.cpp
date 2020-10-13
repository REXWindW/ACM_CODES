#include<iostream>
using namespace std;
#define ll __int128
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
template<class T>
void wt(T x){//快写
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
void Exgcd(ll a,ll b,ll &d,ll &x,ll &y){//扩展欧几里得
	if(!b){d=a;x=1;y=0;}
	else{Exgcd(b,a%b,d,y,x);y-=x*(a/b);}//先交换了xy的位置，实现y1=x2-(a/b)*x2 
}
inline ll mul(ll a,ll b,ll mo){//取模乘法
    return ((a%mo)*(b%mo)%mo+mo)%mo; 
}
const int MAXN = 1e5+5;
ll c[MAXN],m[MAXN];//每组同余式的余数和模数
int n;
ll Excrt(ll m[],ll c[],int n){
    ll mnow = m[1],cnow = c[1];//记录每次合成后的模数余数
    rep(i,2,n){
        ll p1,p2,gcdd;
        ll m1 = mnow,m2 = m[i];//m1p1+c1 = m2p2+c2
        ll dc = (c[i]-cnow%m2+m2)%m2;//dc在保证同余的情况下变成最小的正数
        Exgcd(m1,m2,gcdd,p1,p2);
        if(dc%gcdd) {cout<<i<<endl;return -1;}
        p1 = mul(p1,dc/gcdd,m2/gcdd);//p1存的实际是p1*m1,这里的模数比较讲究
        //一会儿要对lcm(m1,m2)取模,最终结果是[p1*m1*(dc/gcdd)] % [m2/gcdd*m1]
        //m1还没乘上去,这时候先对m2/gcdd取模
        cnow += p1*m1;//更新cnow和mnow
        mnow = m1/gcdd*m2;
        cnow = (cnow%mnow+mnow)%mnow;
    }
    return cnow;  
} 
int main(){
    cin>>n;
    rep(i,1,n) read(m[i]),read(c[i]);
    wt(Excrt(m,c,n));
}
//洛谷P4777 【模板】扩展中国剩余定理（EXCRT）
//https://www.luogu.com.cn/problem/P4777