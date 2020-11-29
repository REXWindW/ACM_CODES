#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<stack>
#include<string>
using namespace std;
#define ll long long
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
stack<int> s1;
stack<char> s2;
int n;
void solve(){
    cin>>n;
    int hc;char ch;
    rep(i,1,n){
        cin>>hc;
        s1.push(hc);
    }
    rep(i,1,n-1){
        cin>>ch;
        s2.push(ch);
    }
    int a,b;
    while(!s2.empty()){
        b = s1.top();
        s1.pop();
        a = s1.top();
        s1.pop();
        ch = s2.top();
        s2.pop();
        if(ch=='+'){
            hc = a+b;
        }
        else if(ch=='-'){
            hc = a-b;
        }
        else if(ch=='*'){
            hc = a*b;
        }
        else if(ch=='/'){
            if(b==0){
                cout<<"ERROR: "<<a<<"/0"<<endl;
                return;
            }
            hc = a/b;
        }
        s1.push(hc);
    }
    cout<<s1.top()<<endl;
}
int main(){
    solve();
}