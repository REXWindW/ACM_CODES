#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
double rbi;
int gangti;
double rdbi;
double chang[2]={2.455,1.26};
void solve(){
    scanf("%lf%d%lf",&rbi,&gangti,&rdbi);
    double res = chang[gangti]*rbi;
    printf("%.2lf ",res);
    if(res>rdbi) printf("T_T\n");
    else printf("^_^\n");
}
int main(){
    solve();
}