#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int MAXN = 3e6+5;
const double Pi = acos(-1.0);
struct cplx{//手写负数complex用起来会更快
    double x,y;
    cplx(double x=0,double y=0):x(x),y(y){}
    friend cplx operator + (cplx a,cplx b){return cplx(a.x+b.x,a.y+b.y);}
    friend cplx operator - (cplx a,cplx b){return cplx(a.x-b.x,a.y-b.y);}
    friend cplx operator * (cplx a,cplx b){return cplx(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
}a[MAXN],b[MAXN];
void FFT(int limit,cplx *a,int type){//limit记录项数
    if(limit==1) return;//只有一个常数项结束递归(即只剩下0次的)
    cplx a1[limit>>1],a2[limit>>1];//按照奇偶分组
    for(int i=0;i<limit;i+=2)
        a1[i>>1] = a[i],a2[i>>1] = a[i+1];
    FFT(limit>>1,a1,type);
    FFT(limit>>1,a2,type);
    cplx Wn(cos(2*Pi/limit),type*sin(2*Pi/limit));//单位根
    //这里type挺重要的,反变换的时候用-1,因为是-k
    cplx w(1,0);//一会儿算单位根幂的时候用w存
    for(int i=0;i<(limit>>1);i++,w=w*Wn){//w相当于公式中的w_n^k
        a[i]=a1[i]+w*a2[i];//偶
        a[i+(limit>>1)]=a1[i]-w*a2[i];//O(1)算另外一部分
    }
}
int main(){
    int n=read(),m=read();
    rep(i,0,n) a[i].x=read();
    rep(i,0,m) b[i].x=read();
    int limit = 1;
    while(limit<=n+m) limit<<=1;//这里非常精髓
    //把长度补到2的幂，这样就不用考虑%2余数的情况
    //而且不必担心高次项的系数，因为默认为0
    FFT(limit,a,1);
    FFT(limit,b,1);
    //1表示FFT，-1则是反变换   
    rep(i,0,limit) a[i] = a[i]*b[i];//转换为点值后直接相乘
    FFT(limit,a,-1);//现在变回去
    rep(i,0,n+m) printf("%d ",(int)(a[i].x/limit+0.5));//还要除以n的
    printf("\n");
}
//P3803 【模板】多项式乘法（FFT）
//https://www.luogu.com.cn/problem/P3803