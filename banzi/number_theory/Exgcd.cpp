#include<iostream>
using namespace std;
#define ll long long
ll Exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){x=1;y=0;return a;}//边界条件结束递归 
	ll d = Exgcd(b,a%b,x,y);//gcd 
	ll t = x;
	x=y;y=t-(a/b)*y;//通过x2y2求得x1y1,层层返回 
	return d;
}
//紫书里面刘汝佳的简短的版本
void Exgcd(ll a,ll b,ll &d,ll &x,ll &y){//不同的是，这里的d使用引用来实现 
	if(!b){d=a;x=1;y=0;}
	else{Exgcd(b,a%b,d,y,x);y-=x*(a/b);}//先交换了xy的位置，实现y1=x2-(a/b)*x2 
} 