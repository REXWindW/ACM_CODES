#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
multiset<int> st;

int main(){
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(2);
    multiset<int>::const_iterator it;
    it = st.end();
    it--;
    cout<<*it<<endl;
    st.erase(st.find(2));
    for(it=st.begin();it!=st.end();it++){
        cout<<*it<<' ';
    }
    cout<<endl;
}