#include<iostream> 
#include<map>
#define ll long long
#define uit unsigned int
#define mkp make_pair
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
const ll b = 1145143;//1145143,1145141
const ll b2 = 1145141;
const int MAXN = 1e5+5;
typedef unsigned long long ull;
typedef pair<ull,ll> prr;
ull hb[MAXN],pw[MAXN]; // h[k]存储字符串前k个字母的哈希值, pw[k]存储 b^k mod 2^64
//这里的模数M取的就是ull的上限2^64
ll med = 1e9+7;//1e7+7;1e8+7;1e9+7
ll hb2[MAXN],pw2[MAXN];//模数是unsigned int的上限
int sb[MAXN];
int n;
void init(int n){//初始化
    pw2[0]=pw[0] = 1;
    hb2[0]=hb[0] = 0;
    for(int i = 1; i <= n; i++ ) {
        hb[i] = hb[i-1]*b + sb[i];
        hb2[i]=(hb2[i-1]*b2%med + sb[i])%med;
        pw[i] = pw[i-1]*b;//预处理b^k的值
        pw2[i] = pw2[i-1]*b2%med;//预处理b2^k的值
    }
}
// 计算子串 str[l ~ r] 的哈希值
ull getb(int le,int ri){
    if(le>ri) return 0;
    int l = n-ri+1;int r = n-le+1;
    return hb[r]-hb[l-1]*pw[r-l+1];
}
ll getb2(int le,int ri){
    if(le>ri) return 0;
    int l = n-ri+1;int r = n-le+1;
    return (hb2[r]-(hb2[l-1]*pw2[r-l+1]%med)+med)%med;
}
map<prr,bool>mp;
void solve(){
    int res = 0;
    rep(i,1,n){
        cin>>sb[n-i+1];
    }
    init(n);
    mp.clear();
    prr now;
    rep(i,1,n){
        now.first = getb(1,i)*pw[n-i]+getb(i+1,n);
        now.second= (getb2(1,i)*pw2[n-i]%med+getb2(i+1,n))%med;
        if(!mp[now]){
            res++;
            mp[now] = 1;
        }
    }
    cout<<res<<endl;
}
int main(){
    while(cin>>n) solve();
}