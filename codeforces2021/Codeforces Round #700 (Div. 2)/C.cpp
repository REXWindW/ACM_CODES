#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x7fffffff
const int MAXN = 114514;
int n;
int a[MAXN];
void solve(){
    cin>>n;
    a[0]=a[n+1]=INF;
    int l = 0,r = n+1;//记录下降顶点
    int mid;
    while(l<r-1){
        mid = (l+r)>>1;
        if(!a[mid]){
            cout.flush();
            cout<<"? "<<mid<<endl;
            cin>>a[mid];
        }
        if(!a[mid-1]&&mid-1>0){//看左边
            cout.flush();
            cout<<"? "<<mid-1<<endl;
            cin>>a[mid-1];
        }
        if(!a[mid+1]&&mid+1<=n){
            cout.flush();
            cout<<"? "<<mid+1<<endl;
            cin>>a[mid+1];
        }

        if(a[mid-1]<a[mid]){
            r = mid;
        }
        else if(a[mid+1]<a[mid]){
            l = mid;
        }
        else{//最好的情况，直接出答案
            cout.flush();
            cout<<"! "<<mid<<endl;
            return;
        }
    }
    cout.flush();
    cout<<((l+r)>>1)<<endl;
}

int main(){
    solve();
}