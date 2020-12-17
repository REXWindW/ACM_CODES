#include<bits/stdc++.h>
  
using namespace std;

#define rep(a,b,c) for(int a=(b);a<(c);++a)
#define dep(a,b,c) for(int a=(b);a>=(c);--a)
#define sf scanf
#define pf printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int>Pii;
typedef pair<double, double> Pdd;
const int inf=0x3f3f3f3f;
const int mod=998244353;
const int N=20000007;
const double sin1=sin(0.01);
const double cos1=cos(0.01);

int t;

double n,p1,p2,v1,v2;

int main(){
    //ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>p1>>v1>>p2>>v2;
        if(p1>p2){
            swap(p1,p2);
            swap(v1,v2);
        }
        double ans;
        ans=min((n+n-p1)/v1,(n+n-p2)/v2);
        ans=min(ans,min((n+p1)/v1,(n+p2)/v2));
        ans=min(ans,(n+p1+n-p2)/(v1+v2));
        ans=min(ans,max(p1/v1,(n-p2+n-p1)/v2));
        ans=min(ans,max((n-p2)/v2,(p1+p2)/v1));
        ans=min(ans,max(p2/v2,(n-p1)/v1));
        ans=min(ans,max(p1/v1,(p2-p1+(n-p1))/v2));
        ans=min(ans,max((n-p2)/v2,(p2-p1+p2)/v1));
        
        if((2*(p2-p1)+p1)/ v1>(n-p2)/ v2 || (2*(p2-p1)+(n-p2))/ v2>p1/ v1){
            ans=min(ans,(n-p1+p2)/(v1+v2));
        }
        if((2*v1*n-v1*p2+v2*p1)/(2*v2+v1)>=p1&&(2*v1*n-v1*p2+v2*p1)/(2*v2+v1)<=p2){
            
        }
        if((v1*p1-v2*p1+v1*n)/(2*v1+v2)>=p1&&(v1*p1-v2*p1+v1*n)/(2*v1+v2)<=p2){
            ans=min(ans,(2.0*p1+p2+n)/(2.0*v1+v2));
        }
        printf("%.10lf\n",ans);
    }
    return 0;
}