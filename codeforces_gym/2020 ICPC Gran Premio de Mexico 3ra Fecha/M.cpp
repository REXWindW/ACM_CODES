#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
stack<char> st,tmp;
string s;
int c[11],d[11];
void solve(){
    cin>>s;
    rep(i,1,9) cin>>d[i];
    int siz = s.size();
    rep(i,0,siz-1) c[s[i]-'0']++;
    st.push('0'+10);
    rep(i,0,siz-1){
        if(c[s[i]-'0']==d[s[i]-'0']){
            d[s[i]-'0']--,c[s[i]-'0']--;
            continue;
        }
        while(s[i]>st.top()&&d[st.top()-'0']){
            d[st.top()-'0']--;
            st.pop();
        }
        st.push(s[i]);c[s[i]-'0']--;
    }
    stack<char> tmp;
    while(st.size()!=1){
        tmp.push(st.top());st.pop();
    }
    while(tmp.size()){
        cout<<tmp.top();tmp.pop();
    }
    cout<<endl;
}

int main(){
    solve();
}