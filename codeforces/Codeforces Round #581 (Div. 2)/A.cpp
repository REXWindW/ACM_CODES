#include<iostream>
#include<cstring>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
string s;
void solve(){
    cin>>s;
    int siz = s.length();
    if(siz==1&&s[0]=='0')cout<<0<<endl;
    else{
        int res = (siz+1)/2;
        bool flag = 1;
        rep(i,1,siz-1){
            if(s[i]=='1'){flag = 0;break;}
        }
        if(siz%2&&flag) res--;
        cout<<res<<endl;
    }
}
 
int main(){
    solve();
}