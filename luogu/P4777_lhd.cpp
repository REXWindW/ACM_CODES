#include<bits/stdc++.h>
using namespace std;
#define int __int128
typedef long long ll;
void Exgcd(int a,int b,int &d,int &x,int &y){//不同的是，这里的d使用引用来实现 
	if(!b){d=a;x=1;y=0;}
	else{Exgcd(b,a%b,d,y,x);y-=x*(a/b);}//先交换了xy的位置，实现y1=x2-(a/b)*x2 
} 
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
template<class T>
void wt(T x){
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
int a[110000],b[110000];
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
ll lcm(ll a,ll b){ return a/gcd(a,b)*b;}
int excrt(int a[],int b[],int n){
    int lc=1;
    for(int i=1;i<=n;i++)
        lc=lcm(lc,a[i]);
    for(int i=1;i<n;i++){
        int p,q,g;
        Exgcd(a[i],a[i+1],g,p,q);
        int k=(b[i+1]-b[i])/g;
        q=-q;p*=k;q*=k;
        b[i+1]=(a[i]*p%lc+b[i])%lc;
        a[i+1]=lcm(a[i],a[i+1]);
    }
    return (b[n]%lc+lc)%lc;
}
signed main(){
    int n;
    rd(n);
    for(int i=1;i<=n;i++){
        rd(a[i]),rd(b[i]);
    }
    wt(excrt(a,b,n));
    cout<<endl;
    return 0;
}
