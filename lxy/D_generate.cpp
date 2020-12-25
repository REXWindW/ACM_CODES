#include<iostream>
#include<algorithm>
#include<random>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
mt19937 rnd(233);
int n;
#define ll long long
ll maxx = 1e13;
int main(){
    freopen("D_in.txt","w",stdout);
    cin>>n;
    cout<<n<<endl;
    rep(i,1,n){
        cout<<rnd()%maxx<<endl;
    }
}