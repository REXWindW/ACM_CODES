#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
#define ft first
#define sd second
#define mkp make_pair
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int main(){
    int n,p;
    double tmp;
    scanf("%d%d",&n,&p);
    rep(i,1,n){
        cin>>tmp;
        if(tmp<p){
            printf("On Sale! %.1lf\n",tmp);
        }
    }
}