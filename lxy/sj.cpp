#include<iostream>
#include<ctime>
using namespace std;
int n,z;//z组数，n每个组的数量
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const ll MAXX = 1e6;
int main(){
    srand((unsigned)time(NULL));
    cin>>z;//几组数据
    while(z--){
    	cin>>n;
        rep(i,1,n){
			int fh = rand()%2;
            ll x = rand()%MAXX;
            if(fh){
				x = -x;
            }
            cout<<x;
            if(i!=n) cout<<' ';
        }
        cout<<endl;
    }
}