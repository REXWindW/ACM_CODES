#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int n;
double chang[2]={2.455,1.26};
void solve(){
    scanf("%d",&n);
    double tot = 0;
    double hc;
    rep(i,1,n){
        scanf("%lf",&hc);
        tot+=1/hc;
    }
    printf("%.2lf\n",1/(tot/n));
}
int main(){
    solve();
}